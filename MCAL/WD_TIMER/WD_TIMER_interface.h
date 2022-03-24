#ifndef WD_TIMER_INTERFACE_H
#define WD_TIMER_INTERFACE_H


/***************************************/
/*					Time period			  	   */
/**************************************/
typedef enum {
	ms_16_3,
	ms_32_5,
	ms_65,
	sec_0_13,
	sec_0_26,
	sec_0_52,
	sec_1_0,
	sec_2_1
}enum_time;


/********************************************************************/
/*									    Prototypes										   */
/********************************************************************/
void WDTCR_vdEnable(void);
void WDTCR_vdSetTime(enum_time Copy_enuTimeTime);
void WDTCR_vdSleep(void);




#endif
