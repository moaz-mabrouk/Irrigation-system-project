#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H


/*****************************************************************/
/*					 Wave generation mode enum					 		  */
/*****************************************************************/
typedef enum {
	T0_Normal_GenerationMode=0x00,
	T0_PWM_PhaseCorrect=0x40,
	T0_CTC_GenerationMode=0x08,
	T0_PWM_Fast=0x48
}enum_waveT0;
/*****************************************************************/
/*					 Compare output mode  enum						  */
/*****************************************************************/
typedef enum {
	/*Non-PWM Mode*/
	OC0_disconnected=0x00,
	OC0_ToggleOnCompareMatch=0x10,
	OC0_ClrOnCompareMatch=0x20,
	OC0_SetOnCompareMatch=0x30,
	/*Fast PWM Mode*/
	OC0_ClrOnCompareMatch_SetAtTOP=0x20,
	OC0_SetOnCompareMatch_ClrAtTOP=0x30,
	/*Phase correct PWM Mode*/
	OC0_ClrOnIncrement_SetOnDecrement=0x20,
	OC0_SetOnIncrement_ClrOnDecrement=0x30

}enum_comT0;
/*****************************************************************/
/*    				 Clock select enum 											  */
/*****************************************************************/
typedef enum {
	T0_CLK_Off=0x00,
	T0_CLK_sys=0x01,
	/*Prescaler division factors*/
	T0_CLK_8=0x02,
	T0_CLK_64=0x03,
	T0_CLK_256=0x04,
	T0_CLK_1024=0x05,
	T0_EXT_fallingEdge=0x06,
	T0_EXT_risingEdge=0x07
}enum_ClockT0;
/*****************************************************************/
/*   				 Interrupt State enum 										  */
/*****************************************************************/
typedef enum {
	T0_Int_overflow=0x01,
	T0_Int_CompareMatch=0x02,
	T0_Int_All=0x03
}enum_InterruptStateT0;
/*****************************************************************/
/*					 Interrupts Flags enum						 				  */
/*****************************************************************/
typedef enum {
	T0_Flag_Overflow,
	T0_Flag_CompareMatch
}enum_flagsT0;
/*****************************************************************/
/*						Prototypes							     					  */
/*****************************************************************/
void TIMER0_vdState(enum_ClockT0 Copy_enuClock);
void TIMER0_vdInit(enum_waveT0 Copy_enuWave,  enum_comT0 Copy_enuCom );
void TIMER0_vdPreloading(u8 Copy_u8Value);
void TIMER0_vdOutputCompareValue(u8 Copy_u8Value);
void TIMER0_vdInterruptEnable(enum_InterruptStateT0 Copy_enuInterruptState);
void TIMER0_vdInterruptDisable(enum_InterruptStateT0 Copy_enuInterruptState);
void TIMER0_vdOverFlowCallback( void (*callback)(void) );
void TIMER0_vdCompareMatchCallback( void (*callback)(void) );
void TIMER0_u8PoolFlag(enum_flagsT0 Copy_enuFlags);


#endif
