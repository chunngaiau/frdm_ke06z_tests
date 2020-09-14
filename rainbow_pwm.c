#include <MKE06Z4.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define R_LED 21 // PTG5, FTM2_CH3
#define G_LED 22 // PTG6, FTM2_CH4
#define B_LED 23 // PTG7, FTM2_CH5

#define SW3 27 // PTH3
#define SW2 28 // PTH4

#define INCREMENT 48000

void delay();

int main() {
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

  // Enable input buttons
  GPIOB_PIDR ^= (1 << SW2) | (1 << SW3);

  // Sets the modulo value to 100
  FTM2_MOD = 100;
  FTM2_C3V = 0;
  FTM2_C4V = 0;
  FTM2_C5V = 0;

  int hue = 0;
  bool direction = true;

  int rVal;
  int gVal;
  int bVal;

  int sw2Val;
  int sw3Val;

  int lastSw3Val;
  
  for (;;) {
    delay();

    sw2Val = (GPIOB_PDIR & (1 << SW2)) >> SW2; // Press to pause animation
    sw3Val = (GPIOB_PDIR & (1 << SW3)) >> SW3; // Press to switch animation direction

    if ((lastSw3Val == 1) && (sw3Val == 0)) { // Only register not-pressed -> pressed
      direction = !direction;
    }

    lastSw3Val = sw3Val;
    
    // If SW2 is pressed (==0), stop rainbow animation
    if (sw2Val == 1) {
      if (direction) {
        hue++; // Goes R -> G -> B
        if (hue >= 300) {
          hue = 0;
        }
      } else {
        hue--; // Goes R -> B -> G
        if (hue <= 0) {
          hue = 300;
        }
      }
    }
    
    // Sets RGB values based on hue
    rVal = (uint32_t) fmax( abs(hue - 150) -  50, 0);
    gVal = (uint32_t) fmax(-abs(hue - 100) + 100, 0);
    bVal = (uint32_t) fmax(-abs(hue - 200) + 100, 0);

    FTM2_C3V = rVal;
    FTM2_C4V = gVal;
    FTM2_C5V = bVal;
  }

  return 0;
}

void delay() {
  for (int i = 0; i < INCREMENT; i++) {
    __ASM("NOP");
  }
}