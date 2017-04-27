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
    #error "You should use `arm-none-eabi` toolchain"
#endif // __GNUC__

#define is ==
#define EQUAL ==
#define NOT_EQUAL !=
#define is_not !=
#define and &&
#define or ||
#define ADDR_OF(ptr) &(ptr)

#define SWAP(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)

typedef uint8_t TaskID;
typedef TaskID InitiatedDriverID_t;
#define TASKLESS 0
typedef unsigned char byte;
#define BYTE_LENGTH 8

// TODO: must be removed from here
#define SYS_CLK_SPEED 16E6

// Modules numbers
#define __PORTS_NUM 6
#define __UART_MODULES_NUM 9
#define __SPI_MODULES_NUM 5

#endif // DEFINITIONS_H_
