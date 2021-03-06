# 1 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\MKE06Z4_Vectors.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\MKE06Z4_Vectors.s"
# 22 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\MKE06Z4_Vectors.s"
  .syntax unified
  .code 16

  .section .init, "ax"
  .align 0





  .thumb_func
  .weak NMI_Handler
NMI_Handler:
  b .

  .thumb_func
  .weak HardFault_Handler
HardFault_Handler:
  b .

  .thumb_func
  .weak SVC_Handler
SVC_Handler:
  b .

  .thumb_func
  .weak PendSV_Handler
PendSV_Handler:
  b .

  .thumb_func
  .weak SysTick_Handler
SysTick_Handler:
  b .

  .thumb_func
Dummy_Handler:
  b .
# 143 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\MKE06Z4_Vectors.s"
  .thumb_func
  .weak FTMRE_IRQHandler
FTMRE_IRQHandler:
  b .

  .thumb_func
  .weak PMC_IRQHandler
PMC_IRQHandler:
  b .

  .thumb_func
  .weak IRQ_IRQHandler
IRQ_IRQHandler:
  b .

  .thumb_func
  .weak I2C0_IRQHandler
I2C0_IRQHandler:
  b .

  .thumb_func
  .weak I2C1_IRQHandler
I2C1_IRQHandler:
  b .

  .thumb_func
  .weak SPI0_IRQHandler
SPI0_IRQHandler:
  b .

  .thumb_func
  .weak SPI1_IRQHandler
SPI1_IRQHandler:
  b .

  .thumb_func
  .weak UART0_IRQHandler
UART0_IRQHandler:
  b .

  .thumb_func
  .weak UART1_IRQHandler
UART1_IRQHandler:
  b .

  .thumb_func
  .weak UART2_IRQHandler
UART2_IRQHandler:
  b .

  .thumb_func
  .weak ADC_IRQHandler
ADC_IRQHandler:
  b .

  .thumb_func
  .weak ACMP0_IRQHandler
ACMP0_IRQHandler:
  b .

  .thumb_func
  .weak FTM0_IRQHandler
FTM0_IRQHandler:
  b .

  .thumb_func
  .weak FTM1_IRQHandler
FTM1_IRQHandler:
  b .

  .thumb_func
  .weak FTM2_IRQHandler
FTM2_IRQHandler:
  b .

  .thumb_func
  .weak RTC_IRQHandler
RTC_IRQHandler:
  b .

  .thumb_func
  .weak ACMP1_IRQHandler
ACMP1_IRQHandler:
  b .

  .thumb_func
  .weak PIT_CH0_IRQHandler
PIT_CH0_IRQHandler:
  b .

  .thumb_func
  .weak PIT_CH1_IRQHandler
PIT_CH1_IRQHandler:
  b .

  .thumb_func
  .weak KBI0_IRQHandler
KBI0_IRQHandler:
  b .

  .thumb_func
  .weak KBI1_IRQHandler
KBI1_IRQHandler:
  b .

  .thumb_func
  .weak ICS_IRQHandler
ICS_IRQHandler:
  b .

  .thumb_func
  .weak WDOG_IRQHandler
WDOG_IRQHandler:
  b .

  .thumb_func
  .weak PWT_IRQHandler
PWT_IRQHandler:
  b .

  .thumb_func
  .weak MSCAN_RX_IRQHandler
MSCAN_RX_IRQHandler:
  b .

  .thumb_func
  .weak MSCAN_TX_IRQHandler
MSCAN_TX_IRQHandler:
  b .







  .section .vectors, "ax"
  .align 0
  .global _vectors
  .extern __stack_end__
  .extern Reset_Handler

_vectors:
  .word __stack_end__
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word 0
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler
  .word Dummy_Handler
  .word Dummy_Handler
  .word Dummy_Handler
  .word Dummy_Handler
  .word Dummy_Handler
  .word FTMRE_IRQHandler
  .word PMC_IRQHandler
  .word IRQ_IRQHandler
  .word I2C0_IRQHandler
  .word I2C1_IRQHandler
  .word SPI0_IRQHandler
  .word SPI1_IRQHandler
  .word UART0_IRQHandler
  .word UART1_IRQHandler
  .word UART2_IRQHandler
  .word ADC_IRQHandler
  .word ACMP0_IRQHandler
  .word FTM0_IRQHandler
  .word FTM1_IRQHandler
  .word FTM2_IRQHandler
  .word RTC_IRQHandler
  .word ACMP1_IRQHandler
  .word PIT_CH0_IRQHandler
  .word PIT_CH1_IRQHandler
  .word KBI0_IRQHandler
  .word KBI1_IRQHandler
  .word Dummy_Handler
  .word ICS_IRQHandler
  .word WDOG_IRQHandler
  .word PWT_IRQHandler
  .word MSCAN_RX_IRQHandler
  .word MSCAN_TX_IRQHandler
_vectors_end:


  .section .vectors, "ax"


  .org 0x400, 0xFF
BackDoorKey:
  .byte 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
# 355 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\MKE06Z4_Vectors.s"
FPROT:
  .byte 0xff, 0xff, 0xff, 0xff
FSEC:
  .byte 0xfe
FOPT:



  .byte 0xff

FEPROT:
  .byte 0xff
FDPROT:
  .byte 0xff
