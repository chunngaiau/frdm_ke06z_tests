# Kinetis Freedom KE06Z Board Tests

Test code for the Kinetis Freedom KE06Z Board.

To run, open the *.em file in Segger Embedded Studio

## Project Files

- **Blinker**: Blinks the LED. A GPIO digital output test.
- **Rainbow**: Cycles through the rainbow colours using PWM. Includes buttons input: SW2 pauses the animation, and SW3 reverses the animation order.
- **I2C_Read_Accel**: Bare metal (register) code to read the onboard MMA8154Q accelerometer using a polling method (i.e. the main loop is blocked while reading or writing). Has issues when sampling rate is high.
- **I2C_Read_Accel_Async**: Bare metal (register) code to read the onboard MMA8154Q accelerometer. Uses interrupts to read the data asynchronously (i.e. fress the main loop while reading or writing).
- **Rainbow_Accel**: Combines **Rainbow** with **I2C_Read_Accel_Async** to change the colour of the RGB led based on orientation and acceleration.
- **ADC_Read_Thermistor**: Code to read the thermistor's voltage using the onboard ADC module.

## Using the Segger J-Link OpenSDA booloader

To use the Freedom KE06Z board with Segger Embedded Studio, make sure the OpenSDA booloader on the FRDM-KE06Z board is configured for Segger J-Link. Go to Segger [website](https://www.segger.com/downloads/jlink/#JLinkOpenSDAGenericFirmwares) and download the OpenSDA V1 Booloader. Plug in the board in booloader mode (i.e. hold the reset button for 3 seconds when plugging into computer), and drag and drop the above bootloader file into the opened filesystem. Unplug and re-plug the board to install the bootloader.
