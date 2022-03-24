#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "WD_TIMER_register.h"
#include "WD_TIMER_interface.h"


/*****************************************************************/
/*			Enable WDT and set period to 16.3 Ms				 */
/*****************************************************************/
void WDTCR_vdEnable(void){
	SET_BIT(WDTCR,WDTCR_WDE);
}

/*****************************************************************/
/*			Enable WDT and set predefined period				 */
/*****************************************************************/
void WDTCR_vdSetTime(enum_time Copy_enuTimeTime){
	SET_BIT(WDTCR,WDTCR_WDE);
	WDTCR &=  ~(  (1<<WDTCR_WDP0)|(1<<WDTCR_WDP1)|(1<<WDTCR_WDP2)  );
	WDTCR|=Copy_enuTimeTime;
}

/*****************************************************************/
/*				Disable WDT (make it sleep)								  */
/*****************************************************************/
void WDTCR_vdSleep(void){
	WDTCR |= (1<<WDTCR_WDE)|(1<<WDTCR_WDTOE);
}
