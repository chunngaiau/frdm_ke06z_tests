# 1 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\Kinetis_KE_Startup.s"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\Kinetis_KE_Startup.s"
# 51 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\Kinetis_KE_Startup.s"
  .syntax unified

  .global Reset_Handler
  .extern _vectors

  .section .init, "ax"
  .thumb_func

  .equ VTOR_REG, 0xE000ED08
  .equ FPU_CPACR_REG, 0xE000ED88





Reset_Handler:


  ldr r0, =__RAM_segment_end__
  ldr r1, =0x7
  bics r0, r1
  mov sp, r0




  ldr r0, =SystemInit
  blx r0
  .pushsection .init_array, "aw", %init_array
  .word SystemCoreClockUpdate
  .popsection
# 107 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\Kinetis_KE_Startup.s"
  ldr r0, =VTOR_REG



  ldr r1, =_vectors

  str r1, [r0]
# 127 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\Kinetis_KE\\Source\\Kinetis_KE_Startup.s"
  b _start
