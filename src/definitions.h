#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <stdint.h>

#ifdef __GNUC__
    #define ASM __asm__ __volatile__
    #define __NAKED __attribute__((naked))
    #define __NAKED_ISR __attribute__((naked, isr))
    #define NOP ASM("NOP")
#else
    #error "You should use `arm-none-eabi` toolchain"
#endif // __GNUC__

#define is ==
#define is_not !=
#define and &&
#define or ||

typedef uint8_t TaskID;
typedef unsigned char byte;
#define BYTE_LENGTH 8

// pointer of function represent the deinitation function of the drivers
typedef void (*__Driver_deinit_func)(int, TaskID);

// maximum number of Tasks
#define NUM_OF_TASKS 10

#endif // DEFINITIONS_H_
