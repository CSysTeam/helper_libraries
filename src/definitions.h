#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <stdint.h>
#include "config.h"

#ifdef __GNUC__
    #define ASM __asm__ __volatile__
    #define __NAKED __attribute__((naked))
    #define __NAKED_ISR __attribute__((naked, isr))
    #define NOP ASM("NOP")
#else
    #error "You must use `arm-none-eabi` toolchain"
#endif // __GNUC__

#define is          ==
#define EQUAL       ==
#define NOT_EQUAL   !=
#define is_not      !=
#define and         &&
#define or          ||
#define ADDR_OF(ptr) &(ptr)

// Just empty macros to divide header files delcarations and functions prototypes
// into two sections
#define PUBLIC
#define PRIVATE

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

#define TASKLESS 0
typedef unsigned char byte;
#define BYTE_LENGTH 8
typedef byte TaskID;

#define SYS_CLK_SPEED_IN_MHZ 16
#define SYS_CLK_SPEED (SYS_CLK_SPEED_IN_MHZ * 1E6)

#define EQUAL_PRIRITY_TIME_SLICE 1000

#endif // DEFINITIONS_H_
