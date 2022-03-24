#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "SPI_register.h"
#include "SPI_interface.h"

/*****************************************************************/
/*						SPI initialize 												     			*/
/*****************************************************************/
void SPI_vdInit(enum_mstr   Copy_enuMstrMode,		enum_clkPolarity Copy_enuPolarity, 	enum_clkPhase Copy_enuPhase , 	enum_clkRate Copy_enuRate){
	/*set Data Direction to LSB 1st sent*/
	CLR_BIT(SPCR,SPCR_DORD);

	/*Set clock Phase */
	if (Copy_enuPhase==leading_sample)
		CLR_BIT(SPCR,SPCR_CPHA);
	else if (Copy_enuPhase==leading_setup)
		CLR_BIT(SPCR,SPCR_CPHA);

	/*Set clock polarity*/
	if (Copy_enuPolarity==rising_faling)
		CLR_BIT(SPCR,SPCR_CPOL);
	else if (Copy_enuPolarity==faling_rising)
		SET_BIT(SPCR,SPCR_CPOL);

	/*set Master/Slave mode */
	if (Copy_enuMstrMode==master)
		SET_BIT(SPCR,SPCR_MSTR);
	else if (Copy_enuMstrMode==slave)
		CLR_BIT(SPCR,SPCR_MSTR);

	/*set clock*/
	SPCR &= ~((1<<SPCR_SPR0) | (1<<SPCR_SPR1));
	CLR_BIT(SPSR,SPSR_SPI2X);
	SPCR |= (Copy_enuRate  &   ((1<<SPCR_SPR0) | (1<<SPCR_SPR1)));
	SPSR |= Copy_enuRate>>4;

	/*Enable SPI*/
	SET_BIT(SPCR,SPCR_SPE);

}
/*****************************************************************/
/*						Disable SPI												     			*/
/*****************************************************************/
void SPI_vdDisable(void){
	CLR_BIT(SPCR,SPCR_SPE);
}
/*****************************************************************/
/*						Master Send Data									   			    */
/*****************************************************************/
u8 SPI_u8MasterDataRW(u8 Copy_u8Setup){
	SPDR=Copy_u8Setup;
	while (GET_BIT(SPSR,SPSR_SPIF)==0);
	return Copy_u8Setup;
}
/*****************************************************************/
/*						Slave Read Data										    		    */
/*****************************************************************/
u8 SPI_u8SlaveDataRead(void){
	while (GET_BIT(SPSR,SPSR_SPIF)==0);
	return SPDR;
}
/*****************************************************************/
/*						Slave Data Write										     			*/
/*****************************************************************/
void SPI_vdSlaveDataWrite(u8 Copy_u8Data){
	while (GET_BIT(SPSR,SPSR_SPIF)==0);
	SPDR=Copy_u8Data;
}

/*****************************************************************/
/*						Enable SPI Interrupt										     		*/
/*****************************************************************/
void SPI_vdInterruptEnable(void){
	SET_BIT(SPCR,SPCR_SPIE);
}
/*****************************************************************/
/*						Disable SPI Interrupt										     	*/
/*****************************************************************/
void SPI_vdInterruptDisable(void){
	CLR_BIT(SPCR,SPCR_SPIE);
}




