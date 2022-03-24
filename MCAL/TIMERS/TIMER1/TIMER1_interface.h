#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H
/*****************************************************************/
/*					 Wave generation mode enum					 	 */
/*****************************************************************/
typedef enum
{
	/*Default Top Size*/
	T1_normal	=0x00,
	T1_PWM_PhaseCorrect_8bit	=0x01,
	T1_PWM_PhaseCorrect_9bit	=0x02,
	T1_PWM_PhaseCorrect_10bit	=0x03,
	T1_CTC_OCR	=0x08,
	T1_PWM_Fast_8bit	=0x09,
	T1_PWM_Fast_98bit	=0x0A,
	T1_PWM_Fast_10bit	=0x0B,

	/*Active TOP Size*/
	T1_PWM_FrequencyCorrect_ICR	=0x10,
	T1_PWM_FrequencyCorrect_OCR	=0x11,
	T1_PWM_PhaseCorrect_ICR =0x12,
	T1_PWM_PhaseCorrect_OCR	=0x13,
	T1_CTC_ICR	=0x18,
	T1_PWM_Fast_ICR	=0x1A,
	T1_PWM_Fast_OCR	=0x1B
}enum_waveT1;
/*****************************************************************/
/*					 Compare output mode  enum						 */
/*****************************************************************/
typedef enum
{
	OC1_disconnected=0x00,
	/*Non-PWM modes*/
	OC1_ToggleOnCompareMatch	=0x50,
	OC1_ClrOnCompareMatch	=0xA0,
	OC1_SetOnCompareMatch	=0xF0,
	/*Fast PWM modes */
	OC1A_ToggleOnCompareMatch	=0x50,
	OC1_ClrOnCompareMatch_SetAtTOP	=0xA0,
	OC1_SetOnCompareMatch_ClrAtTOP	=0xF0,
	/*Correct PWM modes */
	//OC1A_ToggleOnCompareMatch	=0x50,
	OC1_ClrOnIncrement_SetOnDecrement	=0xA0,
	OC1_SetOnIncrement_ClrOnDecrement	=0xF0

}enum_comT1;
/*****************************************************************/
/*    				 Clock select enum 											 */
/*****************************************************************/
typedef enum
{
	T1_CLK_Off=0x00,
	T1_CLK_sys=0x01,
	/*Prescaler division factors*/
	T1_CLK_8=0x02,
	T1_CLK_64=0x03,
	T1_CLK_256=0x04,
	T1_CLK_1024=0x05,
	T1_EXT_fallingEdge=0x06,
	T1_EXT_risingEdge=0x07
}enum_ClockT1;
/*****************************************************************/
/*   				 Interrupt State enum 										 */
/*****************************************************************/
typedef enum
{
	T1_Int_overflow=0x04,
	T1_Int_CompareMatchB=0x08,
	T1_Int_CompareMatchA=0x10,
	T1_Int_InputCapture=0x20,
	T1_Int_All=0x3C
}enum_InterruptStateT1;
/*****************************************************************/
/*					 Interrupts Flags enum										 */
/*****************************************************************/
typedef enum
 {
	T1_Flag_overflow=0x04,
	T1_Flag_CompareMatchB=0x08,
	T1_Flag_CompareMatchA=0x10,
	T1_Flag_InputCapture=0x20
}enum_flagsT1;
/*****************************************************************/
/*					Input Capture Sense control enum 					 */
/*****************************************************************/
typedef enum {
	IC_FaliingEdge=0x00,
	IC_RisingEdge=0x80
}enum_ICSC;
/*****************************************************************/
/*						Prototypes							    					 */
/*****************************************************************/
void TIMER1_vdState(enum_ClockT1 	Copy_enuClock);
void TIMER1_vdInit(enum_waveT1  	Copy_enuWave,  enum_comT1  	Copy_enuCom );
void TIMER1_vdInterruptEnable(enum_InterruptStateT1 	Copy_enuInterruptState);
void TIMER1_vdInterruptDisable(enum_InterruptStateT1 Copy_enuInterruptState);
void TIMER1_vdPreloading(u16 Copy_u16Value);
void TIMER1_vdSetICRA(u16 Copy_u16Value);
void TIMER1_vdSetOCR1A(u16 Copy_u16Value);
void TIMER1_vdSetOCR1B(u16 Copy_u16Value);
void TIMER1_u8PoolFlag(enum_flagsT1 Copy_enuFlags);
void ICU_vdSelectEdge(enum_ICSC);
u16   ICU_GetValue(void);
#endif
