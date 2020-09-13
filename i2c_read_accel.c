/*
  This code reads the Valelerometer data from I2C interface and forwards
  them to the OpenSDA UART Interface

  MCU <--UART1--> OpenSDA
  MCU <--I2C0 --> MMA8451Q Valelerometer
*/

#include <MKE06Z4.h>
#include <stdio.h>

// MMA8451Q I2C Address
#define ValEL_I2C_ADDR 0x1D

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

// Timing
#define WAIT_TIME 10000

// Local function prototypes
void UARTInitialize();
void sendString(char toSend[]);

void I2CInitialize();
void I2CWait();
void writeRegister(uint8_t slaveAddr, uint8_t regAddr, uint8_t data);
static uint8_t readRegister(uint8_t slaveAddr, uint8_t regAddr);

// Main function
int main() {
  int counter;

  int xVal;
  float xAcc;
  char xStr[10];

  int yVal;
  float yAcc;
  char yStr[10];

  int zVal;
  float zAcc;
  char zStr[10];

  UARTInitialize();

  sendString("X, Y, Z\r\n");

  I2CInitialize();

  uint8_t whoAmI = readRegister(ValEL_I2C_ADDR, REG_WHO_AM_I);

  printf("Who Am I: 0x%X\n", whoAmI);

  writeRegister(ValEL_I2C_ADDR, REG_CTRL_1, 0x01);

  for (;;) {
    counter++;
    
    if (counter == WAIT_TIME) {
      counter = 0;

      xVal = readRegister(ValEL_I2C_ADDR, REG_OUT_X_MSB);
      xVal = xVal << 6;
      xVal |= readRegister(ValEL_I2C_ADDR, REG_OUT_X_LSB) >> 2;

      yVal = readRegister(ValEL_I2C_ADDR, REG_OUT_Y_MSB);
      yVal = yVal << 6;
      yVal |= readRegister(ValEL_I2C_ADDR, REG_OUT_Y_LSB) >> 2;

      zVal = readRegister(ValEL_I2C_ADDR, REG_OUT_Z_MSB);
      zVal = zVal << 6;
      zVal |= readRegister(ValEL_I2C_ADDR, REG_OUT_Z_LSB) >> 2;

      if (xVal >> 13 == 1) {
        xVal = -(8192 - (xVal & 0x1FFF));
      }

      if (yVal >> 13 == 1) {
        yVal = -(8192 - (yVal & 0x1FFF));
      }

      if (zVal >> 13 == 1) {
        zVal = -(8192 - (zVal & 0x1FFF));
      }

      sprintf(xStr, "%d, ", xVal);
      sprintf(yStr, "%d, ", yVal);
      sprintf(zStr, "%d\r\n", zVal);

      sendString(xStr);
      sendString(yStr);
      sendString(zStr);
    }
  }

  return 0;
}

//----------------------------- UART Functions ------------------------------//

// Initialize UART1 interface
void UARTInitialize() {
  // Connect bus clock (24MHz) to UART1
  SIM_SCGC |= SIM_SCGC_UART1_MASK;

  // Set baud rate to 9600
  int BR = 156; // Baud = 24MHz / (16 * BR)
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

// Initialize I2C interface
void I2CInitialize() {
  // Connect bus clock (24MHz) to I2C0
  SIM_SCGC |= SIM_SCGC_I2C0_MASK;

  // Set frequency divider register to set I2C baud rate
  // 0x23 sets prescaler to 256 (24 MHz / 256 = 93.75 kbit/s)
  I2C0_F |= 0x23 & I2C_F_ICR_MASK;

  // Set control register 1 to enable I2C module and interrupts
  // Enable I2C Module
  I2C0_C1 |= (1 << I2C_C1_IICEN_SHIFT);
}

// Wait for operation to finish
void I2CWait(char msg[]) {
  int waited = 0;
  while (((I2C0_S1 & I2C_S_IICIF_MASK) == 0) && (waited < 1000)) {
    if (waited == 0) {
      //printf("Waiting: %s\n", msg);
    }
    waited++;
  }
  I2C0_S1 |= I2C_S_IICIF_MASK;
}

// Write register
void writeRegister(uint8_t slaveAddr, uint8_t regAddr, uint8_t data) {
  // Set transmit mode
  I2C0_C1 |= I2C_C1_TX_MASK;

  // Send START signal
  I2C0_C1 |= I2C_C1_MST_MASK;

  // Send slave address with write (0)
  I2C0_D = (slaveAddr << 1) | 0;
  I2CWait("First Slave Address");

  // Send register address to read
  I2C0_D = regAddr;
  I2CWait("Register Address");

  // Send data
  I2C0_D = data;
  I2CWait("Data");

  // Send STOP signal
  I2C0_C1 &= ~I2C_C1_MST_MASK;
}

// Read register
uint8_t readRegister(uint8_t slaveAddr, uint8_t regAddr) {
  uint8_t result;

  // Set transmit mode
  I2C0_C1 |= I2C_C1_TX_MASK;

  // Send START signal
  I2C0_C1 |= I2C_C1_MST_MASK;

  // Send slave address with write (0)
  I2C0_D = (slaveAddr << 1) | 0;
  I2CWait("First Slave Address");

  // Send register address to read
  I2C0_D = regAddr;
  I2CWait("Register Address");

  // Send REPEATED START signal
  I2C0_C1 |= I2C_C1_RSTA_MASK;

  // Send slave address with read (1)
  I2C0_D = (slaveAddr << 1) | 1;
  I2CWait("Second Slave Address");

  // Set receive mode
  I2C0_C1 &= ~I2C_C1_TX_MASK;

  // Set NACK for second last byte
  I2C0_C1 |= I2C_C1_TXAK_MASK;

  // Dummy read to initialize receive
  (void)I2C0_D;
  I2CWait("Reading");

  // Send STOP signal
  I2C0_C1 &= ~I2C_C1_MST_MASK;

  // Read real result
  result = I2C0_D;

  // Reset C1
  I2C0_C1 &= ~I2C_C1_TXAK_MASK;

  return result;
}