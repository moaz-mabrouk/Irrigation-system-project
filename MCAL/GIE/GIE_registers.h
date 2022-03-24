#ifndef GIE_REGISTERS_H
#define GIE_REGISTERS_H

/**************************************/
/***Global Interrupt enable register***/
/**************************************/
#define SREG  *((volatile u8*)0x5f)
#define SREG_IBIT	7

#endif	
