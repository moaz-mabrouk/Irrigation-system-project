#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../MCAL/I2C/I2C_interface.h"

void EEPROM_vdSendData(u8 Copy_u8Block, u8 Copy_u8Address, u8 Copy_u8Data){
	Copy_u8Block = (0b10101<<3) | (Copy_u8Block) ;
	TWI_u8StartCondition();
	TWI_vdMasterSendAddress(Copy_u8Block, MasterWrite);
	TWI_u8MasterSendData(Copy_u8Address);
	TWI_u8MasterSendData(Copy_u8Data);
	TWI_u8StopCondition();
}
u8	EEPROM_vdReadData(u8 Copy_u8Block, u8 Copy_u8Address){
	u8 Data=0;
	Copy_u8Address |=Copy_u8Block<<6;
	Copy_u8Block = (0b10101<<4) | (Copy_u8Block<<1) | 0;
	TWI_u8StartCondition();
	TWI_vdMasterSendAddress(Copy_u8Block, MasterWrite);
	TWI_u8MasterSendData(Copy_u8Address);
	TWI_u8RepeatedStartCondition();
	TWI_vdMasterSendAddress(Copy_u8Block, MasterRead);
	TWI_u8MasterRecieveData(&Data);
	TWI_u8StopCondition();
	return Data;
}
