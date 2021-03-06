/*
  This code reads the Accelerometer data from the I2C interface asynchronously
  using the interrupts and forwards them to the OpenSDA UART Interface.

  MCU <--UART1--> OpenSDA
  MCU <--I2C0 --> MMA8451Q Accelerometer
*/

#include <MKE06Z4.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// MMA8451Q I2C Address
#define ACCEL_I2C_ADDR 0x1D

// MMA8451Q Register Addresses
#define REG_WHO_AM_I 0x0D // Default WHO_AM_I value is 0x1A
#define REG_OUT_X_MSB 0x01
#define REG_OUT_X_LSB 0x02
#define REG_OUT_Y_MSB 0x03
#define REG_OUT_Y_LSB 0x04
#define REG_OUT_Z_MSB 0x05
#define REG_OUT_Z_LSB 0x06
#define REG_XYZ_DATA_CFG 0x0E
#define REG_CTRL_1 0x2A

// Wait Time
#define WAIT_TIME 10000
#define TIMEOUT 10000

// Local function prototypes
void initUART();
void sendString(char toSend[]);

void initI2C();
void getRegister(uint8_t slaveAddr, uint8_t regAddr, uint8_t *dataPtr);
void setRegister(uint8_t slaveAddr, uint8_t regAddr, uint8_t data);

void initAccel();
int readAccel(int axis);

// Globals
bool i2cBusy;
bool i2cTXMode;
int i2cStep;
int timeout;
uint8_t i2cSlaveAddr;
uint8_t i2cRegAddr;
uint8_t i2cWriteData;
uint8_t *i2cReadDataPtr;

int main() {
  initI2C();
  initUART();
  
  uint8_t whoAmI = 0;
  getRegister(ACCEL_I2C_ADDR, REG_WHO_AM_I, &whoAmI);

  while (i2cBusy) {
    __NOP();
  }

  printf("WHO_AM_I: 0x%X\n", whoAmI);

  if (whoAmI != 0x1A) {
    printf("Unexpected WHO_AM_I value!\n");
    return 1;
  }

  setRegister(ACCEL_I2C_ADDR, REG_CTRL_1, 0x00); // Disable (if already enabled)

  for (int i = 0; i < 1000; i++) {
    __NOP();
  }

  setRegister(ACCEL_I2C_ADDR, REG_XYZ_DATA_CFG, 0x00); // Set dynamic range

  for (int i = 0; i < 1000; i++) {
    __NOP();
  }

  setRegister(ACCEL_I2C_ADDR, REG_CTRL_1, 0x01); // Enable

  // SETUP PWM
  // Enable clock gate for FTM2
  SIM_SCGC |= (1 << SIM_SCGC_FTM2_SHIFT) & SIM_SCGC_FTM2_MASK;

  // Pin select
  SIM_PINSEL1 |= (2 << SIM_PINSEL1_FTM2PS3_SHIFT) & SIM_PINSEL1_FTM2PS3_MASK;
  SIM_PINSEL1 |= (1 << SIM_PINSEL1_FTM2PS4_SHIFT) & SIM_PINSEL1_FTM2PS4_MASK;
  SIM_PINSEL1 |= (1 << SIM_PINSEL1_FTM2PS5_SHIFT) & SIM_PINSEL1_FTM2PS5_MASK;

  // Enable system clock for FTM2
  FTM2_SC |= (1 << FTM_SC_CLKS_SHIFT) & FTM_SC_CLKS_MASK;

  // Enable Edge-aligned PWM for channels
  FTM2_C3SC |= FTM_CnSC_MSB_MASK | FTM_CnSC_ELSA_MASK;
  FTM2_C4SC |= FTM_CnSC_MSB_MASK | FTM_CnSC_ELSA_MASK;
  FTM2_C5SC |= FTM_CnSC_MSB_MASK | FTM_CnSC_ELSA_MASK;

  // Sets the modulo value to 8192
  FTM2_MOD = 8192;
  FTM2_C3V = 0;
  FTM2_C4V = 0;
  FTM2_C5V = 0;
  
  uint8_t xLSB = 0;
  uint8_t xMSB = 0;
  int xVal;

  uint8_t yLSB = 0;
  uint8_t yMSB = 0;
  int yVal;

  uint8_t zLSB = 0;
  uint8_t zMSB = 0;
  int zVal;

  char outStr[30];

  int loading = 0;

  for (;;) {
    if (!i2cBusy) {
      switch (loading) {
        case 0:
          getRegister(ACCEL_I2C_ADDR, REG_OUT_X_LSB, &xLSB);
          break;
        case 1:
          getRegister(ACCEL_I2C_ADDR, REG_OUT_X_MSB, &xMSB);
          break;
        case 2:
          getRegister(ACCEL_I2C_ADDR, REG_OUT_Y_LSB, &yLSB);
          break;
        case 3:
          getRegister(ACCEL_I2C_ADDR, REG_OUT_Y_MSB, &yMSB);
          break;
        case 4:
          getRegister(ACCEL_I2C_ADDR, REG_OUT_Z_LSB, &zLSB);
          break;
        case 5:
          getRegister(ACCEL_I2C_ADDR, REG_OUT_Z_MSB, &zMSB);
          break;
      }
      
      loading++;

      if (loading == 6) {
        loading = 0;
      }
    
      xVal = ((xMSB << 6) | (xLSB >> 2));
      yVal = ((yMSB << 6) | (yLSB >> 2));
      zVal = ((zMSB << 6) | (zMSB >> 2));

      if ((xVal >> 13) == 1) {
        xVal = -(8192 - (xVal & 0x1FFF));
      }

      if ((yVal >> 13) == 1) {
        yVal = -(8192 - (yVal & 0x1FFF));
      }

      if ((zVal >> 13) == 1) {
        zVal = -(8192 - (zVal & 0x1FFF));
      }

      printf("%d, %d, %d\n", xVal, yVal, zVal);
      sprintf(outStr, "$%d %d %d;\n", xVal, yVal, zVal);
      sendString(outStr);

      FTM2_C3V = abs(xVal);
      FTM2_C4V = abs(yVal);
      FTM2_C5V = abs(zVal);
    }
  }

  return 0;
}

//----------------------------- UART Functions ------------------------------//

// Initialize UART1 interface
void initUART() {
  // Connect bus clock (24MHz) to UART1
  SIM_SCGC |= SIM_SCGC_UART1_MASK;

  // Set baud rate to 9600
  int BR = 13; // Baud = 24MHz / (16 * BR)
  UART1_BDL = BR & 0xFF;
  UART1_BDH = (BR >> 8) & 0x1F;

  // Enable transmitter and receiver
  UART1_C2 |= UART_C2_TE_MASK;
  UART1_C2 |= UART_C2_RE_MASK;
}

// Send a string through UART1 interface
void sendString(char toSend[]) {
  int i = 0;
  while (toSend[i] != '\0') { // '\0' is the end-of-string character
    while ((UART1_S1 & UART_S1_TDRE_MASK) == 0) {
      __NOP(); // Wait for write buffer to empty
    }
    (void)UART1_S1;
    UART1_D = toSend[i];
    i++;
  }
}

//----------------------------- I2C Functions -------------------------------//

// Initialize I2C module
void initI2C() {
  // Connect bus clock (24 MHz) to I2C0
  SIM_SCGC |= SIM_SCGC_I2C0_MASK;

  // Set frequecy divider register to set I2C baud rate
  // 0x23 sets prescaler to 256 (24 MHz / 256 = 93.75 kbit/s)
  I2C0_F |= 0x23 & I2C_F_ICR_MASK;

  // Set control register 1 to enable I2C module and interrupts
  I2C0_C1 |= I2C_C1_IICEN_MASK | I2C_C1_IICIE_MASK;
  NVIC_EnableIRQ(I2C0_IRQn);
}

// I2C Interrupt Handler
void I2C0_IRQHandler() {
  // Clear the interrupt flag
  I2C0_S1 |= I2C_S_IICIF_MASK;

  if (i2cStep == 0) {
    //printf("Sent RegAddr: 0x%X\n", i2cRegAddr);
    I2C0_D = i2cRegAddr;
    i2cStep++;
    return;
  }

  if (i2cTXMode) {
    switch (i2cStep) {
      case 1: // Send data
        //printf("Sent Data\n");
        I2C0_D = i2cWriteData;
        i2cStep++;
        return;
      case 2:
        //printf("Reset TX Mode\n");
        I2C0_C1 &= ~(I2C_C1_MST_MASK | I2C_C1_TX_MASK);
        i2cBusy = false;
        i2cStep++;
        return;
    }
  } else {
    switch (i2cStep) {
      case 1: // Send REPEATED START and Slave Addr
        //printf("Sent RSTA\n");
        I2C0_C1 |= I2C_C1_RSTA_MASK;
        I2C0_D = (i2cSlaveAddr << 1) | 1;
        i2cStep++;
        return;
      case 2: // Dummy Read
        //printf("Sent SlaveAddr\n");
        I2C0_C1 &= ~I2C_C1_TX_MASK;
        I2C0_C1 |= I2C_C1_TXAK_MASK;
        (void) I2C0_D;
        i2cStep++;
        return;
      case 3: // Read and STOP
        //printf("Read and Reset RX Mode\n");
        I2C0_C1 &= ~I2C_C1_MST_MASK;
        *i2cReadDataPtr = I2C0_D;
        I2C0_C1 &= ~I2C_C1_TXAK_MASK;
        i2cBusy = false;
        i2cStep++;
        return;
    }
  }

  // Reset when i2cStep is too big
  //printf("I2C Reset\n");
  I2C0_C1 &= ~(I2C_C1_MST_MASK | I2C_C1_TX_MASK | I2C_C1_TXAK_MASK);
  return;
}

void getRegister(uint8_t slaveAddr, uint8_t regAddr, uint8_t *dataPtr) {
  // Setup globals
  i2cSlaveAddr = slaveAddr;
  i2cRegAddr = regAddr;
  i2cReadDataPtr = dataPtr;
  
  // Set busy flag to true
  i2cBusy = true;
  timeout = 0;

  // Set flag to receive mode
  i2cTXMode = false;

  // Set step to 0
  i2cStep = 0;

  // Wait a bit before starting
  for (int i = 0; i < 10; i++) {
    __NOP();
  }

  // Set transmit mode
  I2C0_C1 |= I2C_C1_TX_MASK;

  // Send START
  I2C0_C1 &= ~I2C_C1_MST_MASK;
  I2C0_C1 |= I2C_C1_MST_MASK;

  // Send slave address with write (0)
  // Completion of this step triggers interrupt
  I2C0_D = (i2cSlaveAddr << 1) | 0;
  return;
}

void setRegister(uint8_t slaveAddr, uint8_t regAddr, uint8_t data) {
  // Setup globals
  i2cSlaveAddr = slaveAddr;
  i2cRegAddr = regAddr;
  i2cWriteData = data;

  // Set busy flag to true
  i2cBusy = true;
  timeout = 0;

  // Set flag to transmit mode
  i2cTXMode = true;

  // Set step to 0
  i2cStep = 0;

  // Wait a bit before starting
  for (int i = 0; i < 10; i++) {
    __NOP();
  }

  // Set transmit mode
  I2C0_C1 |= I2C_C1_TX_MASK;

  // Send START
  I2C0_C1 &= ~I2C_C1_MST_MASK;
  I2C0_C1 |= I2C_C1_MST_MASK;

  // Send slave address with write (0)
  // Completion of this step triggers interrupt
  I2C0_D = (i2cSlaveAddr << 1) | 0;
  return;
}

//--------------------------- MMA8451Q Functions ----------------------------//