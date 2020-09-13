# 1 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\read_accel.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\read_accel.c"
# 1 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h" 1
# 67 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
# 1 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 5.10a/include/stdint.h" 1 3 4
# 41 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 5.10a/include/stdint.h" 3 4

# 41 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 5.10a/include/stdint.h" 3 4
typedef signed char int8_t;
typedef unsigned char uint8_t;




typedef signed short int16_t;
typedef unsigned short uint16_t;





typedef signed int int32_t;
typedef unsigned int uint32_t;
# 68 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 5.10a/include/stdint.h" 3 4
typedef signed long long int64_t;
typedef unsigned long long uint64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int32_t int_fast8_t;
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef uint32_t uint_fast8_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef int32_t intptr_t;
typedef uint32_t uintptr_t;
# 118 "C:/Program Files/SEGGER/SEGGER Embedded Studio for ARM 5.10a/include/stdint.h" 3 4
typedef int64_t intmax_t;
typedef uint64_t uintmax_t;
# 68 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h" 2
# 86 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"

# 86 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef enum IRQn {

  NonMaskableInt_IRQn = -14,
  HardFault_IRQn = -13,
  SVCall_IRQn = -5,
  PendSV_IRQn = -2,
  SysTick_IRQn = -1,


  Reserved16_IRQn = 0,
  Reserved17_IRQn = 1,
  Reserved18_IRQn = 2,
  Reserved19_IRQn = 3,
  Reserved20_IRQn = 4,
  FTMRE_IRQn = 5,
  PMC_IRQn = 6,
  IRQ_IRQn = 7,
  I2C0_IRQn = 8,
  I2C1_IRQn = 9,
  SPI0_IRQn = 10,
  SPI1_IRQn = 11,
  UART0_IRQn = 12,
  UART1_IRQn = 13,
  UART2_IRQn = 14,
  ADC_IRQn = 15,
  ACMP0_IRQn = 16,
  FTM0_IRQn = 17,
  FTM1_IRQn = 18,
  FTM2_IRQn = 19,
  RTC_IRQn = 20,
  ACMP1_IRQn = 21,
  PIT_CH0_IRQn = 22,
  PIT_CH1_IRQn = 23,
  KBI0_IRQn = 24,
  KBI1_IRQn = 25,
  Reserved42_IRQn = 26,
  ICS_IRQn = 27,
  WDOG_IRQn = 28,
  PWT_IRQn = 29,
  MSCAN_RX_IRQn = 30,
  MSCAN_TX_IRQn = 31
} IRQn_Type;
# 149 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
# 1 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h" 1
# 163 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
# 1 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cmInstr.h" 1
# 61 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cmInstr.h"
# 1 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h" 1
# 40 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
# 58 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__( ( always_inline ) ) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}







__attribute__( ( always_inline ) ) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}







__attribute__( ( always_inline ) ) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}







__attribute__( ( always_inline ) ) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}







__attribute__( ( always_inline ) ) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}







__attribute__( ( always_inline ) ) static inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}
# 134 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__( ( always_inline ) ) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}







__attribute__( ( always_inline ) ) static inline uint32_t __get_PSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, psp\n" : "=r" (result) );
  return(result);
}







__attribute__( ( always_inline ) ) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0\n" : : "r" (topOfProcStack) : "sp");
}







__attribute__( ( always_inline ) ) static inline uint32_t __get_MSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, msp\n" : "=r" (result) );
  return(result);
}
# 188 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__( ( always_inline ) ) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0\n" : : "r" (topOfMainStack) : "sp");
}







__attribute__( ( always_inline ) ) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}







__attribute__( ( always_inline ) ) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 377 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __NOP(void)
{
  __asm volatile ("nop");
}






__attribute__((always_inline)) static inline void __WFI(void)
{
  __asm volatile ("wfi");
}







__attribute__((always_inline)) static inline void __WFE(void)
{
  __asm volatile ("wfe");
}






__attribute__((always_inline)) static inline void __SEV(void)
{
  __asm volatile ("sev");
}
# 420 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __ISB(void)
{
  __asm volatile ("isb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DSB(void)
{
  __asm volatile ("dsb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DMB(void)
{
  __asm volatile ("dmb 0xF":::"memory");
}
# 454 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{

  return __builtin_bswap32(value);






}
# 473 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rev16 %0, %1" : "=l" (result) : "l" (value) );
  return(result);
}
# 488 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline int32_t __REVSH(int32_t value)
{

  return (short)__builtin_bswap16(value);






}
# 508 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 530 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;




  int32_t s = 4 * 8 - 1;

  result = value;
  for (value >>= 1U; value; value >>= 1U)
  {
    result <<= 1U;
    result |= value & 1U;
    s--;
  }
  result <<= s;

  return(result);
}
# 1374 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/cmsis_gcc.h"
#pragma GCC diagnostic pop
# 62 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cmInstr.h" 2
# 164 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h" 2
# 1 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cmFunc.h" 1
# 165 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h" 2
# 258 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
typedef union
{
  struct
  {
    uint32_t _reserved0:28;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} APSR_Type;
# 288 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:23;
  } b;
  uint32_t w;
} IPSR_Type;
# 306 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
typedef union
{
  struct
  {
    uint32_t ISR:9;
    uint32_t _reserved0:15;
    uint32_t T:1;
    uint32_t _reserved1:3;
    uint32_t V:1;
    uint32_t C:1;
    uint32_t Z:1;
    uint32_t N:1;
  } b;
  uint32_t w;
} xPSR_Type;
# 345 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
typedef union
{
  struct
  {
    uint32_t nPRIV:1;
    uint32_t SPSEL:1;
    uint32_t _reserved1:30;
  } b;
  uint32_t w;
} CONTROL_Type;
# 376 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
typedef struct
{
  volatile uint32_t ISER[1U];
        uint32_t RESERVED0[31U];
  volatile uint32_t ICER[1U];
        uint32_t RSERVED1[31U];
  volatile uint32_t ISPR[1U];
        uint32_t RESERVED2[31U];
  volatile uint32_t ICPR[1U];
        uint32_t RESERVED3[31U];
        uint32_t RESERVED4[64U];
  volatile uint32_t IP[8U];
} NVIC_Type;
# 403 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
typedef struct
{
  volatile const uint32_t CPUID;
  volatile uint32_t ICSR;

  volatile uint32_t VTOR;



  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
        uint32_t RESERVED1;
  volatile uint32_t SHP[2U];
  volatile uint32_t SHCSR;
} SCB_Type;
# 520 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
typedef struct
{
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile const uint32_t CALIB;
} SysTick_Type;
# 745 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}







static inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}
# 769 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
static inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] & (1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
}







static inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}







static inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[0U] = (uint32_t)(1UL << (((uint32_t)(int32_t)IRQn) & 0x1FUL));
}
# 804 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
static inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) < 0)
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] = ((uint32_t)(((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
  else
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] = ((uint32_t)(((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] & ~(0xFFUL << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL))) |
       (((priority << (8U - 2)) & (uint32_t)0xFFUL) << ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL)));
  }
}
# 828 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
static inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) < 0)
  {
    return((uint32_t)(((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[( (((((uint32_t)(int32_t)(IRQn)) & 0x0FUL)-8UL) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
  else
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[ ( (((uint32_t)(int32_t)(IRQn)) >> 2UL) )] >> ( ((((uint32_t)(int32_t)(IRQn)) ) & 0x03UL) * 8UL) ) & (uint32_t)0xFFUL) >> (8U - 2)));
  }
}






static inline void NVIC_SystemReset(void)
{
  __DSB();

  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR = ((0x5FAUL << 16U) |
                 (1UL << 2U));
  __DSB();

  for(;;)
  {
    __NOP();
  }
}
# 885 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/CMSIS_4/CMSIS/Include/core_cm0plus.h"
static inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD = (uint32_t)(ticks - 1UL);
  NVIC_SetPriority (SysTick_IRQn, (1UL << 2) - 1UL);
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL = 0UL;
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL = (1UL << 2U) |
                   (1UL << 1U) |
                   (1UL );
  return (0UL);
}
# 150 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h" 2
# 1 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/system_MKE06Z4.h" 1
# 69 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/system_MKE06Z4.h"
extern uint32_t SystemCoreClock;
# 78 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/system_MKE06Z4.h"
void SystemInit (void);
# 87 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/system_MKE06Z4.h"
void SystemCoreClockUpdate (void);
# 151 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h" 2
# 201 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t CS;
  volatile uint8_t C0;
  volatile uint8_t C1;
  volatile uint8_t C2;
} ACMP_Type, *ACMP_MemMapPtr;
# 335 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t SC1;
  volatile uint32_t SC2;
  volatile uint32_t SC3;
  volatile uint32_t SC4;
  volatile const uint32_t R;
  volatile uint32_t CV;
  volatile uint32_t APCTL1;
  volatile uint32_t SC5;
} ADC_Type, *ADC_MemMapPtr;
# 503 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  union {
    struct {
      volatile uint16_t DATAL;
      volatile uint16_t DATAH;
    } ACCESS16BIT;
    volatile uint32_t DATA;
    struct {
      volatile uint8_t DATALL;
      volatile uint8_t DATALU;
      volatile uint8_t DATAHL;
      volatile uint8_t DATAHU;
    } ACCESS8BIT;
  };
  union {
    struct {
      volatile uint16_t GPOLYL;
      volatile uint16_t GPOLYH;
    } GPOLY_ACCESS16BIT;
    volatile uint32_t GPOLY;
    struct {
      volatile uint8_t GPOLYLL;
      volatile uint8_t GPOLYLU;
      volatile uint8_t GPOLYHL;
      volatile uint8_t GPOLYHU;
    } GPOLY_ACCESS8BIT;
  };
  union {
    volatile uint32_t CTRL;
    struct {
           uint8_t RESERVED_0[3];
      volatile uint8_t CTRLHU;
    } CTRL_ACCESS8BIT;
  };
} CRC_Type, *CRC_MemMapPtr;
# 739 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t PDOR;
  volatile uint32_t PSOR;
  volatile uint32_t PCOR;
  volatile uint32_t PTOR;
  volatile const uint32_t PDIR;
  volatile uint32_t PDDR;
  volatile uint32_t PIDR;
} FGPIO_Type, *FGPIO_MemMapPtr;
# 891 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t SC;
  volatile uint32_t CNT;
  volatile uint32_t MOD;
  struct {
    volatile uint32_t CnSC;
    volatile uint32_t CnV;
  } CONTROLS[6];
       uint8_t RESERVED_0[16];
  volatile uint32_t CNTIN;
  volatile uint32_t STATUS;
  volatile uint32_t MODE;
  volatile uint32_t SYNC;
  volatile uint32_t OUTINIT;
  volatile uint32_t OUTMASK;
  volatile uint32_t COMBINE;
  volatile uint32_t DEADTIME;
  volatile uint32_t EXTTRIG;
  volatile uint32_t POL;
  volatile uint32_t FMS;
  volatile uint32_t FILTER;
  volatile uint32_t FLTCTRL;
       uint8_t RESERVED_1[4];
  volatile uint32_t CONF;
  volatile uint32_t FLTPOL;
  volatile uint32_t SYNCONF;
  volatile uint32_t INVCTRL;
  volatile uint32_t SWOCTRL;
  volatile uint32_t PWMLOAD;
} FTM_Type, *FTM_MemMapPtr;
# 1473 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
       uint8_t RESERVED_0[1];
  volatile uint8_t FCCOBIX;
  volatile const uint8_t FSEC;
  volatile uint8_t FCLKDIV;
       uint8_t RESERVED_1[1];
  volatile uint8_t FSTAT;
       uint8_t RESERVED_2[1];
  volatile uint8_t FCNFG;
  volatile uint8_t FCCOBLO;
  volatile uint8_t FCCOBHI;
       uint8_t RESERVED_3[1];
  volatile uint8_t FPROT;
       uint8_t RESERVED_4[3];
  volatile const uint8_t FOPT;
} FTMRE_Type, *FTMRE_MemMapPtr;
# 1645 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t PDOR;
  volatile uint32_t PSOR;
  volatile uint32_t PCOR;
  volatile uint32_t PTOR;
  volatile const uint32_t PDIR;
  volatile uint32_t PDDR;
  volatile uint32_t PIDR;
} GPIO_Type, *GPIO_MemMapPtr;
# 1797 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t A1;
  volatile uint8_t F;
  volatile uint8_t C1;
  volatile uint8_t S;
  volatile uint8_t D;
  volatile uint8_t C2;
  volatile uint8_t FLT;
  volatile uint8_t RA;
  volatile uint8_t SMB;
  volatile uint8_t A2;
  volatile uint8_t SLTH;
  volatile uint8_t SLTL;
} I2C_Type, *I2C_MemMapPtr;
# 2032 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t C1;
  volatile uint8_t C2;
  volatile uint8_t C3;
  volatile uint8_t C4;
  volatile uint8_t S;
} ICS_Type, *ICS_MemMapPtr;
# 2164 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t SC;
} IRQ_Type, *IRQ_MemMapPtr;
# 2259 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t PE;
  volatile uint32_t ES;
  volatile uint32_t SC;
  volatile const uint32_t SP;
} KBI_Type, *KBI_MemMapPtr;
# 2383 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
       uint8_t RESERVED_0[8];
  volatile const uint16_t PLASC;
  volatile const uint16_t PLAMC;
  volatile uint32_t PLACR;
} MCM_Type, *MCM_MemMapPtr;
# 2493 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t CANCTL0;
  volatile uint8_t CANCTL1;
  volatile uint8_t CANBTR0;
  volatile uint8_t CANBTR1;
  volatile uint8_t CANRFLG;
  volatile uint8_t CANRIER;
  volatile uint8_t CANTFLG;
  volatile uint8_t CANTIER;
  volatile uint8_t CANTARQ;
  volatile const uint8_t CANTAAK;
  volatile uint8_t CANTBSEL;
  volatile uint8_t CANIDAC;
       uint8_t RESERVED_0[1];
  volatile uint8_t CANMISC;
  volatile const uint8_t CANRXERR;
  volatile const uint8_t CANTXERR;
  volatile uint8_t CANIDAR_BANK_1[4];
  volatile uint8_t CANIDMR_BANK_1[4];
  volatile uint8_t CANIDAR_BANK_2[4];
  volatile uint8_t CANIDMR_BANK_2[4];
  union {
    volatile uint8_t REIDR0;
    volatile uint8_t RSIDR0;
  };
  union {
    volatile uint8_t REIDR1;
    volatile uint8_t RSIDR1;
  };
  volatile uint8_t REIDR2;
  volatile uint8_t REIDR3;
  volatile uint8_t REDSR[8];
  volatile uint8_t RDLR;
       uint8_t RESERVED_1[1];
  volatile uint8_t RTSRH;
  volatile uint8_t RTSRL;
  union {
    volatile uint8_t TEIDR0;
    volatile uint8_t TSIDR0;
  };
  union {
    volatile uint8_t TEIDR1;
    volatile uint8_t TSIDR1;
  };
  volatile uint8_t TEIDR2;
  volatile uint8_t TEIDR3;
  volatile uint8_t TEDSR[8];
  volatile uint8_t TDLR;
  volatile uint8_t TBPR;
  volatile uint8_t TTSRH;
  volatile uint8_t TTSRL;
} MSCAN_Type, *MSCAN_MemMapPtr;
# 2978 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile const uint8_t BACKKEY0;
  volatile const uint8_t BACKKEY1;
  volatile const uint8_t BACKKEY2;
  volatile const uint8_t BACKKEY3;
  volatile const uint8_t BACKKEY4;
  volatile const uint8_t BACKKEY5;
  volatile const uint8_t BACKKEY6;
  volatile const uint8_t BACKKEY7;
       uint8_t RESERVED_0[5];
  volatile const uint8_t FPROT;
  volatile const uint8_t FSEC;
  volatile const uint8_t FOPT;
} NV_Type, *NV_MemMapPtr;
# 3141 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t CR;
} OSC_Type, *OSC_MemMapPtr;
# 3234 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t MCR;
       uint8_t RESERVED_0[252];
  struct {
    volatile uint32_t LDVAL;
    volatile const uint32_t CVAL;
    volatile uint32_t TCTRL;
    volatile uint32_t TFLG;
  } CHANNEL[2];
} PIT_Type, *PIT_MemMapPtr;
# 3362 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t SPMSC1;
  volatile uint8_t SPMSC2;
} PMC_Type, *PMC_MemMapPtr;
# 3466 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t IOFLT0;
  volatile uint32_t IOFLT1;
  volatile uint32_t PUE0;
  volatile uint32_t PUE1;
  volatile uint32_t PUE2;
  volatile uint32_t HDRVE;
} PORT_Type, *PORT_MemMapPtr;
# 3791 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t R1;
  volatile const uint32_t R2;
} PWT_Type, *PWT_MemMapPtr;
# 3910 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile const uint32_t ENTRY[1];
  volatile const uint32_t TABLEMARK;
       uint8_t RESERVED_0[4036];
  volatile const uint32_t SYSACCESS;
  volatile const uint32_t PERIPHID4;
  volatile const uint32_t PERIPHID5;
  volatile const uint32_t PERIPHID6;
  volatile const uint32_t PERIPHID7;
  volatile const uint32_t PERIPHID0;
  volatile const uint32_t PERIPHID1;
  volatile const uint32_t PERIPHID2;
  volatile const uint32_t PERIPHID3;
  volatile const uint32_t COMPID[4];
} ROM_Type, *ROM_MemMapPtr;
# 4079 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint32_t SC;
  volatile uint32_t MOD;
  volatile const uint32_t CNT;
} RTC_Type, *RTC_MemMapPtr;
# 4186 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile const uint32_t SRSID;
  volatile uint32_t SOPT0;
  volatile uint32_t SOPT1;
  volatile uint32_t PINSEL;
  volatile uint32_t PINSEL1;
  volatile uint32_t SCGC;
  volatile const uint32_t UUIDL;
  volatile const uint32_t UUIDML;
  volatile const uint32_t UUIDMH;
  volatile uint32_t CLKDIV;
} SIM_Type, *SIM_MemMapPtr;
# 4499 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t C1;
  volatile uint8_t C2;
  volatile uint8_t BR;
  volatile const uint8_t S;
       uint8_t RESERVED_0[1];
  volatile uint8_t D;
       uint8_t RESERVED_1[1];
  volatile uint8_t M;
} SPI_Type, *SPI_MemMapPtr;
# 4660 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t BDH;
  volatile uint8_t BDL;
  volatile uint8_t C1;
  volatile uint8_t C2;
  volatile const uint8_t S1;
  volatile uint8_t S2;
  volatile uint8_t C3;
  volatile uint8_t D;
} UART_Type, *UART_MemMapPtr;
# 4903 "D:/User Files/Documents/SEGGER Embedded Studio for ARM Projects/KE06Z_Tests/Kinetis_KE/CMSIS/Device/Include/MKE06Z4.h"
typedef struct {
  volatile uint8_t CS1;
  volatile uint8_t CS2;
  union {
    volatile uint16_t CNT;
    struct {
      volatile const uint8_t CNTH;
      volatile const uint8_t CNTL;
    } CNT8B;
  };
  union {
    volatile uint16_t TOVAL;
    struct {
      volatile uint8_t TOVALH;
      volatile uint8_t TOVALL;
    } TOVAL8B;
  };
  union {
    volatile uint16_t WIN;
    struct {
      volatile uint8_t WINH;
      volatile uint8_t WINL;
    } WIN8B;
  };
} WDOG_Type, *WDOG_MemMapPtr;
# 2 "D:\\User Files\\Documents\\SEGGER Embedded Studio for ARM Projects\\KE06Z_Tests\\read_accel.c" 2
