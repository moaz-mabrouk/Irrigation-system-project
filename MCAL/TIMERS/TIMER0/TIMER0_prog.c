#include"../../../lib/STD_TYPES.h"
#include"../../../lib/BIT_MATH.h"
#include "TIMER0_interface.h"
#include "TIMER0_registers.h"



/*****************************************************************/
/*			For callback function (used in ISR)					 		 */
/*****************************************************************/
void (*pFuncTOVCallback)(void)=(void*)0;
void (*pFuncOCFCallback)(void)=(void*)0;
/*****************************************************************/
/*			Enable /Disable timer0 and select clock source		 */
/*****************************************************************/
void TIMER0_vdState(enum_ClockT0 Copy_enuClock){
	/*Select Clock Source*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
	TCCR0|=Copy_enuClock;
}
/*****************************************************************/
/*			Select wave type and compare output mode 			 */
/*****************************************************************/
void TIMER0_vdInit(enum_waveT0   Copy_enuWave,  enum_comT0   Copy_enuCom ){
	/*Setting wave generation mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	TCCR0|=Copy_enuWave;

	/*Setting Compare output match mode*/
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
	TCCR0|=Copy_enuCom;
}
/*****************************************************************/
/*			Preloading value to timer0 register 		 					 */
/*****************************************************************/
void TIMER0_vdPreloading(u8 Copy_u8Value){
	/*Preload Timer0 Register*/
	TCNT0=Copy_u8Value;
}
/*****************************************************************/
/*			Load the output compare match register				 */
/*****************************************************************/
void TIMER0_vdOutputCompareValue(u8 Copy_u8Value){
	/*Compare match Register load*/
	OCR0=Copy_u8Value;
}
/*****************************************************************/
/*			Enable interrupts for overflow and compare match */
/*****************************************************************/
void TIMER0_vdInterruptEnable(enum_InterruptStateT0   Copy_enuInterruptState){
	/*Enable Selected interrupt Sources*/
	CLR_BIT(TIMSK,TIMSK_TOIE0);
	CLR_BIT(TIMSK,TIMSK_OCIE0);
	TIMSK|=Copy_enuInterruptState;
}
/*****************************************************************/
/*		Disable interrupts for overflow and compare match	 */
/*****************************************************************/
void TIMER0_vdInterruptDisable(enum_InterruptStateT0   Copy_enuInterruptState){

	if (Copy_enuInterruptState==T0_Int_overflow){
		CLR_BIT(TIMSK,TIMSK_TOIE0);/*Clear overflow interrupt enable flag bit*/
	}else if (Copy_enuInterruptState==T0_Int_CompareMatch){
		CLR_BIT(TIMSK,TIMSK_OCIE0);/*Clear compare match interrupt enable flag bit*/
	}else{
		/*Clear Both compare match and overflow interrupt enable bits*/
		CLR_BIT(TIMSK,TIMSK_OCIE0);
		CLR_BIT(TIMSK,TIMSK_TOIE0);
	}
}
/*****************************************************************/
/*			Pool on interrupt flag								 				 */
/*****************************************************************/
void TIMER0_u8PoolFlag(enum_flagsT0   Copy_enuFlags){

	if (Copy_enuFlags==T0_Flag_Overflow){
		/*Pool on overflow flag then clear it*/
		while(GET_BIT(TIFR,TIFR_TOV0)==0);
		SET_BIT(TIFR,TIFR_TOV0);
	}else if (Copy_enuFlags==T0_Flag_CompareMatch){
		/*Pool on compare match flag then clear it*/
		while(GET_BIT(TIFR,TIFR_OCF0));
		SET_BIT(TIFR,TIFR_OCF0);
	}

}
/*****************************************************************/
/*			Callback for overflow interrupt						 		 */
/*****************************************************************/
void TIMER0_vdOverFlowCallback( void (*pFuncCallback)(void) ){
	pFuncTOVCallback=pFuncCallback;
}
/*****************************************************************/
/*			Callback for compare match interrupt				 		 */
/*****************************************************************/
void TIMER0_vdCompareMatchCallback( void (*pFuncCallback)(void) ){
	pFuncOCFCallback=pFuncCallback;
}
/*****************************************************************/
/*			Timer Overflow interrupt service routine 			 	 */
/*****************************************************************/
void __vector_11(void) __attribute__((signal));
void __vector_11(void){
	pFuncTOVCallback();
}
/*****************************************************************/
/*			Timer compare match interrupt service routine 		 */
/*****************************************************************/
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	pFuncOCFCallback();
}
