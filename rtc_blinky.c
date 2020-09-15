/*
  RTC version of blinky

  Blinks the LED every second
*/

#include <MKE06Z4.h>
#include <stdlib.h>
#include <stdio.h>

#define R_LED 21 // PTG 5

volatile uint32_t seconds = 0;

int main() {
  // Enable Red LED
  GPIOB_PDDR |= (1 << R_LED);

  // Enable Oscillator
  OSC_CR |= OSC_CR_OSCEN_MASK;
  OSC_CR |= OSC_CR_RANGE_MASK;
  OSC_CR |= OSC_CR_OSCOS_MASK;

  // Enable ICS FLL Engaged External mode
  ICS_C1 |= ICS_C1_RDIV(0b011); // Set prescaler to 256 --> 40 MHz
  ICS_C2 |= ICS_C2_BDIV(0b001); // Set bus divider to 2 --> 20 MHz

  while ((OSC_CR & OSC_CR_OSCINIT_MASK) == 0) {
    __NOP(); // Wait for oscillator to init
  }

  while ((ICS_S & ICS_S_LOCK_MASK) == 0) {
    __NOP(); // Wait for FLL to lock
  }
  
  // Enable clock gate to RTC
  SIM_SCGC |= SIM_SCGC_RTC_MASK;

  // Configure RTC clock source to bus clock
  RTC_SC |= RTC_SC_RTCLKS(0b11);
  
  // Configure 1/64 prescaler
  RTC_SC |= RTC_SC_RTCPS(0b111);

  // Set the modulo value to 511
  RTC_MOD = 24000; // tuned to be accurate within 1 minute

  // Clear any interrupts
  RTC_SC |= RTC_SC_RTIF_MASK;

  // Enable interrupt
  RTC_SC |= RTC_SC_RTIE_MASK;
  NVIC_EnableIRQ(RTC_IRQn);

  for (;;) {
    ;
  }
  
  return 0;
}

void RTC_IRQHandler() {
  // Clear the interrupt
  RTC_SC |= RTC_SC_RTIF_MASK;

  // Toggle LED
  GPIOB_PTOR |= (1 << R_LED);

  seconds++;
}