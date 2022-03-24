#include"../../../lib/BIT_MATH.h"
#include"../../../lib/STD_TYPES.h"
#include"TIMER1_registers.h"
#include "TIMER1_interface.h"

/*****************************************************************/
/*			Enable /Disable timer1 and select clock source		 */
/*****************************************************************/
void TIMER1_vdState(enum_ClockT1 	Copy_enuClock){
	TCCR1B &=~ ((1<<TCCR1B_CS10)		|	(1<<TCCR1B_CS11)		|	(1<<TCCR1B_CS12))	;
	TCCR1B |=(Copy_enuClock  & ((1<<TCCR1B_CS10)		|	(1<<TCCR1B_CS11)		|	(1<<TCCR1B_CS12))	 );
}
/*****************************************************************/
/*			Select wave type and compare output mode 			 */
/*****************************************************************/
void TIMER1_vdInit(enum_waveT1  	Copy_enuWave,  enum_comT1  	Copy_enuCom ){

	/*Assign wave generation mode bits in TCCR1A register */
	TCCR1A &= ~ ((1<<TCCR1A_WGM10)	|	(1<<TCCR1A_WGM11));
	TCCR1A   |= (Copy_enuWave & ((1<<TCCR1A_WGM10)		|	(1<<TCCR1A_WGM11)));

	/*Assign wave generation mode bits in TCCR1B register */
	TCCR1B &= ~ ((1<<TCCR1B_WGM12)		|	(1<<TCCR1B_WGM13));
	TCCR1B   |= (Copy_enuWave & ((1<<TCCR1B_WGM12)	|	(1<<TCCR1B_WGM13)));

	/*Assign Compare output mode bits in TCCR1A register */
	TCCR1A &= ~((1<<TCCR1A_COM1A0)	|	(1<<TCCR1A_COM1A1)	|	(1<<TCCR1A_COM1B0)	|	(1<<TCCR1A_COM1B1));
	TCCR1A |= (Copy_enuCom & ((1<<TCCR1A_COM1A0)	|	(1<<TCCR1A_COM1A1)	|	(1<<TCCR1A_COM1B0)	|	(1<<TCCR1A_COM1B1)) );

}
/*****************************************************************/
/*			Enable interrupts for overflow and compare match */
/*****************************************************************/
void TIMER1_vdInterruptEnable(enum_InterruptStateT1 	Copy_enuInterruptState){
	TIMSK |= (Copy_enuInterruptState & ((1<<TIMSK_OCIE1A)	|	(1<<TIMSK_OCIE1B)		|	(1<<TIMSK_TICIE1)	|	(1<<TIMSK_TOIE1)) );
}
/*****************************************************************/
/*		Disable interrupts for overflow and compare match	 */
/*****************************************************************/
void TIMER1_vdInterruptDisable(enum_InterruptStateT1 Copy_enuInterruptState){
	TIMSK &= ~(Copy_enuInterruptState & ((1<<TIMSK_OCIE1A)	|	(1<<TIMSK_OCIE1B)		|	(1<<TIMSK_TICIE1)	|	(1<<TIMSK_TOIE1)) );
}
/*****************************************************************/
/*			Preloading value to timer0 register 		 		 			 */
/*****************************************************************/
void TIMER1_vdPreloading(u16 Copy_u16Value){
	TCNT1L=Copy_u16Value;
}
/*****************************************************************/
/*			Set ICR value 															 */
/*****************************************************************/
void TIMER1_vdSetICRA(u16 Copy_u16Value){
	ICR1L=Copy_u16Value;
}
/*****************************************************************/
/*			Set OCR1A value 														 */
/*****************************************************************/
void TIMER1_vdSetOCR1A(u16 Copy_u16Value){
	OCR1AL=Copy_u16Value;
}
/*****************************************************************/
/*			Set OCR1B value 														 */
/*****************************************************************/
void TIMER1_vdSetOCR1B(u16 Copy_u16Value){
	OCR1BL=Copy_u16Value;
}
/*****************************************************************/
/*			Pool on interrupt flag								 				 */
/*****************************************************************/
void TIMER1_u8PoolFlag(enum_flagsT1 Copy_enuFlags){
	while (GET_BIT(TIFR,Copy_enuFlags)==0);
}
/*****************************************************************/
/*			Select the sense control edge of the ICU	 				 */
/*****************************************************************/
void ICU_vdSelectEdge(enum_ICSC Copy_enuICSCmode){
	TCCR1B |= (Copy_enuICSCmode ^ (1<<TCCR1B_ICES1));
}
/*****************************************************************/
/*			Get the Input Capture number of ticks						 */
/*****************************************************************/
u16   ICU_GetValue(void){
	u16 temp =ICR1L;
	return temp;
}





//void TIMER1_vdInit(void){
//	/*Select fast PWM Mode*/
//	CLR_BIT(TCCR1A,TCCR1A_WGM10);
//	SET_BIT(TCCR1A,TCCR1A_WGM11);
//
//	SET_BIT(TCCR1B,TCCR1B_WGM12);
//	SET_BIT(TCCR1B,TCCR1B_WGM13);
//	/**/
//	ICR1L =750;
//
//	/*Set fast PWM Non-inverted*/
//	SET_BIT(TCCR1A,TCCR1A_COM1A1);
//	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
//
//	/*set prescaler */
//	CLR_BIT(TCCR1B,TCCR1B_CS10);
//	SET_BIT(TCCR1B,TCCR1B_CS11);
//	CLR_BIT(TCCR1B,TCCR1B_CS12);
//}
//void TIMER1_vdSetICRA(u16 Copy_u16Value){
//	ICR1L=Copy_u16Value;
//}
//void TIMER1_vdSetOCR1(u16 Copy_u16Value){
//	OCR1AL=Copy_u16Value;
//}
