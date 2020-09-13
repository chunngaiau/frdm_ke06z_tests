/*
  UART Hello World Test

  The OpenSDA serial is connected to UART1.
*/

#include <MKE06Z4.h>
#include <stdio.h>

#define R_LED 21;

// Local function prototypes
void sendChar(uint8_t send);
void sendString(char toSend[]);
uint8_t receiveChar();

// Main function
int main() {
  // Connect bus clock to UART1
  SIM_SCGC |= SIM_SCGC_UART1_MASK;

  // Set baud rate to 9600
  int BR = 156; // Baud rate = 24MHz / (16 * BR)
  UART1_BDL = BR & 0xFF;
  UART1_BDH |= (BR >> 8) & 0x1F;

  // Enable transmitter and receiver
  UART1_C2 |= UART_C2_TE_MASK;
  UART1_C2 |= UART_C2_RE_MASK;

  // Enable receiver interrupt
  UART1_C2 |= UART_C2_RIE_MASK;
  NVIC_EnableIRQ(UART1_IRQn);

  // Hello World!
  sendString("Hello World!\r\n");
  //printf("Hello World!\r\n");

  return 0;
}

// Interrupt Function
void UART1_IRQHandler() {
  uint8_t temp = receiveChar();
  sendChar(temp);
}

// Send Character
void sendChar(uint8_t send) {
  while ((UART1_S1 & UART_S1_TDRE_MASK) == 0) {
    __NOP();
  }
  (void) UART1_S1;
  UART1_D = send;
}

// Send String
void sendString(char toSend[]) {
  int i = 0;
  while (toSend[i] != '\0') {
    sendChar(toSend[i]);
    i++;
  }
}

// Receive Character
uint8_t receiveChar() {
  while ((UART1_S1 & UART_S1_RDRF_MASK) == 0) {
    __NOP();
  }
  (void) UART1_S1;
  uint8_t received = UART1_D;
  return received;
}