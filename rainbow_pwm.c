#include <MKE06Z4.h>
#include <stdlib.h>
#include <math.h>

#define R_LED 21 // PTG5, FTM2_CH3
#define G_LED 22 // PTG6, FTM2_CH4
#define B_LED 23 // PTG7, FTM2_CH5

#define INCREMENT 10000

int main() {
  int counter = 0;

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

  FTM2_MOD = 100;
  FTM2_C3V = 0;
  FTM2_C4V = 0;
  FTM2_C5V = 0;

  int hue;

  int rVal;
  int gVal;
  int bVal;
  
  for (;;) {
    counter++;

    if (counter == INCREMENT) {
      counter = 0;

      hue++;
      if (hue >= 300) {
        hue = 0;
      }

      rVal = (uint32_t) fmax( abs(hue - 150) -  50, 0);
      gVal = (uint32_t) fmax(-abs(hue - 100) + 100, 0);
      bVal = (uint32_t) fmax(-abs(hue - 200) + 100, 0);

      FTM2_C3V = rVal;
      FTM2_C4V = gVal;
      FTM2_C5V = bVal;
    }
  }

  return 0;
}