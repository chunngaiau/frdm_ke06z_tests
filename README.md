# frdm_ke06z_tests
Test code for the Kinetis Freedom KE06Z Board.

To run, open the *.em file in Segger Embedded Studio, and open either the blinker.c (for the blinker project) or the rainbow_pwm.c (for the rainbow pwm project).

_Using the Segger J-Link OpenSDA booloader:_

Make sure the OpenSDA booloader on the FRDM-KE06Z board is configured for Segger J-Link. Go to Segger [website](https://www.segger.com/downloads/jlink/#JLinkOpenSDAGenericFirmwares) and download the OpenSDA V1 Booloader. Plug in the board in booloader mode (i.e. hold the reset button for 3 seconds when plugging into computer), and drag and drop the above bootloader file into the opened filesystem. Unplug and re-plug the board to install the bootloader.
