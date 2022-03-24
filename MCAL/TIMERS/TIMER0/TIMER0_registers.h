#ifndef TIMER0_REGISTERS_H
#define TIMER0_REGISTERS_H
/************************************************************************/
				/*Timer/Counter Control Register */
/************************************************************************/
#define TCCR0		*((volatile u8 *)0x53)
#define TCCR0_CS00			    0 /*Clock select*/
#define TCCR0_CS01			    1 /*Clock select*/
#define TCCR0_CS02			    2 /*Clock select*/
#define TCCR0_WGM01			    3 /*Waveform Generation Mode*/
#define TCCR0_COM00			    4 /*Compare Match Output Mode*/
#define TCCR0_COM01			    5 /*Compare Match Output Mode*/
#define TCCR0_WGM00			    6 /*Waveform Generation Mode*/
#define TCCR0_FOC0			    7 /*Force Output Compare*/

/************************************************************************/
				/*Timer/Counter Interrupt Mask Register*/
/************************************************************************/
#define TIMSK		*((volatile u8 *)0x59)
#define TIMSK_TOIE0		 		0 /*Timer/Counter0 Overflow Interrupt Enable*/
#define TIMSK_OCIE0		 		1 /*Timer/Counter0 Output Compare Match Interrupt Enable*/

#define TIMSK_TOIE2				6
#define TIMSK_OCIE2				7

/************************************************************************/
				/*Timer/Counter Interrupt Flag Register*/
/************************************************************************/
#define TIFR		*((volatile u8 *)0x58)
#define TIFR_TOV0			    0 /*Timer/Counter0 Overflow Flag*/
#define TIFR_OCF0			    1 /*Output Compare Flag 0*/

#define TIFR_TOV2			    6
#define TIFR_OCF2			    7

/************************************************************************/
				/*Timer/Counter Register*/
/************************************************************************/
#define TCNT0		*((volatile u8 *)0x52)

/************************************************************************/
				/*Output Compare Register*/
/************************************************************************/
#define OCR0		*((volatile u8 *)0x5c)
#endif


