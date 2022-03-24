#ifndef WD_TIMER_REGISTER_H
#define WD_TIMER_REGISTER_H


/************************************************************************/
					/*Watchdog Timer Control Register*/
/************************************************************************/
#define WDTCR			*((volatile u8*)0x41)
#define WDTCR_WDTOE				  4 /*Watchdog Turn-off Enable*/
#define WDTCR_WDE                 3 /*Watchdog Enable*/
#define WDTCR_WDP2                2 /*Watchdog Timer Prescaler 2*/
#define WDTCR_WDP1                1 /*Watchdog Timer Prescaler 1*/
#define WDTCR_WDP0                0 /*Watchdog Timer Prescaler 0*/

#endif
