/*
  This code reads the Accelerometer data from the I2C interface asynchronously
  using the interrupts and forwards them to the OpenSDA UART Interface.

  MCU <--UART1--> OpenSDA
  MCU <--I2C0 --> MMA8451Q Accelerometer
*/

#include <MKE06Z4.h>
#include <stdio.h>
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
void getRegister(uint8_t slaveAddr, uint8_t regAddr, int *dataPtr);
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
  
  int whoAmI = 0;
  getRegister(ACCEL_I2C_ADDR, REG_WHO_AM_I, &whoAmI);

  while (i2cBusy) {
    __NOP();
  }

  printf("WHO_AM_I: 0x%X\n", whoAmI);

  if (whoAmI != 0x1A) {
    printf("Unexpected WHO_AM_I value!\n");
    return 1;
  }

  for (int i = 0; i < 100; i++) {
    __NOP(); // Wait a bit for i2c to reset
  }

  setRegister(ACCEL_I2C_ADDR, REG_CTRL_1, 0x01);
  
  int xLSB = 0;
  int xMSB = 0;
  int loading = 0;

  for (int i = 0; i < 100; i++) {
    __NOP();
  }

  for (;;) {
    if (timeout >= TIMEOUT) {
      timeout = 0;
      i2cBusy = false;
    }
    
    if (i2cBusy) {
      timeout++;
      continue;
    }

    if (loading == 0) {
      printf("0x%X\n", ((xMSB << 6) | (xLSB >> 2)));
      getRegister(ACCEL_I2C_ADDR, REG_OUT_X_LSB, &xLSB);
      loading = 1;
    } else if (loading == 1) {
      getRegister(ACCEL_I2C_ADDR, REG_OUT_X_MSB, &xMSB);
      loading = 0;
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
    printf("Sent RegAddr: %X\n", i2cRegAddr);
    I2C0_D = i2cRegAddr;
    i2cStep++;
    return;
  }

  if (i2cTXMode) {
    switch (i2cStep) {
      case 1: // Send data
        printf("Sent Data\n");
        I2C0_D = i2cWriteData;
        i2cStep++;
        return;
      case 2:
        printf("Reset TX Mode\n");
        I2C0_C1 &= ~(I2C_C1_MST_MASK | I2C_C1_TX_MASK);
        i2cBusy = false;
        i2cStep++;
        return;
    }
  } else {
    switch (i2cStep) {
      case 1: // Send REPEATED START and Slave Addr
        printf("Sent RSTA\n");
        I2C0_C1 |= I2C_C1_RSTA_MASK;
        I2C0_D = (i2cSlaveAddr << 1) | 1;
        i2cStep++;
        return;
      case 2: // Dummy Read
        printf("Sent SlaveAddr\n");
        I2C0_C1 &= ~I2C_C1_TX_MASK;
        I2C0_C1 |= I2C_C1_TXAK_MASK;
        (void) I2C0_D;
        i2cStep++;
        return;
      case 3: // Read and STOP
        printf("Read and Reset RX Mode\n");
        *i2cReadDataPtr = I2C0_D;
        I2C0_C1 &= ~I2C_C1_MST_MASK;
        I2C0_C1 &= ~I2C_C1_TXAK_MASK;
        i2cBusy = false;
        i2cStep++;
        return;
    }
  }

  // Reset when i2cStep is too big
  printf("I2C Reset\n");
  I2C0_C1 &= ~(I2C_C1_MST_MASK | I2C_C1_TX_MASK | I2C_C1_TXAK_MASK);
  return;
}

void getRegister(uint8_t slaveAddr, uint8_t regAddr, int *dataPtr) {
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