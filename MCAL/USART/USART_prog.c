#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "USART_register.h"
#include "USART_interface.h"
#include "USART_config.h"


void USART_vdInit(void){

	UBRRL=51;

	UCSRC=0|(1<<UCSRC_URSEL) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0);




	/*choose UCSRC*/
//	SET_BIT(UCSRC,UCSRC_URSEL);
	/*asynchronous mode */
//	CLR_BIT(UCSRC,UCSRC_UMSEL);

	/*no parity*/
//	CLR_BIT(UCSRC,UCSRC_UPM1);
//	CLR_BIT(UCSRC,UCSRC_UPM0);

	/*stop bit */
//	CLR_BIT(UCSRC,UCSRC_USBS);

	/*character size 8 bit */
//	SET_BIT(UCSRC,UCSRC_UCSZ1);
//	SET_BIT(UCSRC,UCSRC_UCSZ0);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/*baud rate */
//	CLR_BIT(UBRRH,UBRRH_URSEL);

	/*rx tx enable */
		SET_BIT(UCSRB,UCSRB_RXEN);
		SET_BIT(UCSRB,UCSRB_TXEN);

}
void USART_vdSend(u8 Copy_u8Data){
	while (GET_BIT(UCSRA,UCSRA_UDRE)==0);
		UDR=Copy_u8Data;

}
u8 USART_vdRecieve(void){
	u8 Copy_u8Data=0;
	while (GET_BIT(UCSRA,UCSRA_RXC)==0);
	Copy_u8Data=UDR;

	return Copy_u8Data;
}
