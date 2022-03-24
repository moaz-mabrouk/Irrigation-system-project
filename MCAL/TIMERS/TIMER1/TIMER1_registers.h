#ifndef TIMER1_REGISTERS_H
#define TIMER1_REGISTERS_H
/************************************************************************/
				/*Timer/Counter Control Register */
/************************************************************************/
#define TCCR1A		*((volatile u8 *)0x4f)
#define TCCR1A_WGM10			0 /*Waveform Generation Mode*/
#define TCCR1A_WGM11			1 /*Waveform Generation Mode*/
#define TCCR1A_FOC1B			2 /*Force Output Compare for Channel B*/
#define TCCR1A_FOC1A			3 /*Force Output Compare for Channel A*/
#define TCCR1A_COM1B0			4 /*Compare Output Mode for Channel B*/
#define TCCR1A_COM1B1			5 /*Compare Output Mode for Channel B*/
#define TCCR1A_COM1A0			6 /*Compare Output Mode for Channel A*/
#define TCCR1A_COM1A1			7 /*Compare Output Mode for Channel A*/

/************************************************************************/
				/*Timer/Counter Control Register */
/************************************************************************/
#define TCCR1B		*((volatile u8 *)0x4E)
#define TCCR1B_CS10				0 /*Input Capture Noise Canceler*/
#define TCCR1B_CS11				1 /*Input Capture Edge Select*/
#define TCCR1B_CS12				2 /*Waveform Generation Mode*/
#define TCCR1B_WGM12			3 /*Waveform Generation Mode*/
#define TCCR1B_WGM13			4 /*Clock Select*/
#define TCCR1B_ICES1			6 /*Clock Select*/
#define TCCR1B_ICNC1			7 /*Clock Select*/

/************************************************************************/
				/*Timer/Counter Interrupt Mask Register*/
/************************************************************************/
#define TIMSK		*((volatile u8 *)0x59)
#define TIMSK_TOIE1				2 /*Timer/Counter1, Overflow Interrupt Enable*/
#define TIMSK_OCIE1B			3 /*Timer/Counter1, Output Compare B Match Interrupt Enable*/
#define TIMSK_OCIE1A			4 /*Timer/Counter1, Output Compare A Match Interrupt Enable*/
#define TIMSK_TICIE1			5 /*Timer/Counter1, Input Capture Interrupt Enable*/

/************************************************************************/
				/*Timer/Counter Interrupt Flag Register*/
/************************************************************************/
#define TIFR		*((volatile u8 *)0x58)
#define TIFR_TOV1			    2 /*Timer/Counter1, Overflow Flag*/
#define TIFR_OCF1B			    3 /*Timer/Counter1, Output Compare B Match Flag*/
#define TIFR_OCF1A			    4 /*Timer/Counter1, Output Compare A Match Flag*/
#define TIFR_ICF1			    5 /*Timer/Counter1, Input Capture Flag*/

/************************************************************************/
				/*Timer/Counter Register*/
/************************************************************************/
#define TCNT1H		*((volatile u8 *)0x4D) /*Counter Register High Byte*/
#define TCNT1L		*((volatile u8 *)0x4C) /*Counter Register Low Byte*/


/************************************************************************/
				/*Output Compare Register*/
/************************************************************************/
#define OCR1AH		*((volatile u8 *)0x4B) /*Output Compare Register A High Byte*/
#define OCR1AL		*((volatile u16*)0x4A) /*Output Compare Register A Low Byte*/
#define OCR1BH		*((volatile u8 *)0x49) /*Output Compare Register B High Byte*/
#define OCR1BL		*((volatile u8 *)0x48) /*Output Compare Register B Low Byte*/


/************************************************************************/
				/*Input Capture Register*/
/************************************************************************/
#define ICR1H		*((volatile u8 *)0x47) /*Input Capture Register High Byte*/
#define ICR1L		*((volatile u16 *)0x46) /*Input Capture Register Low Byte*/

#endif
