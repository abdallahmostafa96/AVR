
#ifndef STD_MACROS_H_
#define STD_MACROS_H_


#include <avr/io.h>   // this file include all register addresses macros like DDRA
#define F_CPU 8000000UL // set the frequency of microcontroller
#include <util/delay.h> // this header include all delay function like _delay_ms
#include <avr/interrupt.h> // this header is necessary when you deal with interrupt

#define Null       ((void *)0x00)
#define Pressed    		 0
#define NotPressed     1

#define Set_Bit(REG,BIT) (REG |= 1<<BIT)
#define Clr_Bit(REG,BIT) (REG &= ~(1<<BIT))
#define Tog_BIT(REG,BIT) (REG ^= 1<<BIT)
#define Get_Bit(REG,BIT)  ((REG >> BIT) & 1)

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short int u16;
typedef signed short int s16;

typedef unsigned long int u32;
typedef signed long int s32;

typedef float f32;
typedef double f64;


#endif /* STD_MACROS_H_ */
