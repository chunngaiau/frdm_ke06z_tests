#include <MKE06Z4.h>

#define R_LED 21 // PTG5
#define G_LED 22 // PTG6
#define B_LED 23 // PTG7

#define INCREMENT 1000000

int main() {
  int counter = 0;

  GPIOB_PDDR |= (1 << R_LED);
  GPIOB_PSOR |= (1 << R_LED);

  for (;;) {
    counter++;

    if (counter == INCREMENT) {
      counter = 0;
      GPIOB_PTOR |= (1 << R_LED);
    }
  }
  
  return 0;
}