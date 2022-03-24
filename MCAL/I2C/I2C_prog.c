/*
 * I2C_prog.c
 *
 *  Created on: Feb 26, 2022
 *      Author: Moaz Mahmoud
 */
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "I2C_register.h"
#include "I2C_interface.h"
#include "I2C_private.h"

/************************************************************************/
				/*TWI initialization */
/************************************************************************/
void TWI_vdInit(u8 Copy_u8Address){
	/*Set baud Rate*/
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS0);
	TWBR=2;
	/*Set Slave Address*/
	if(Copy_u8Address){
		TWAR=(Copy_u8Address<<1);
	}
	/*enable TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
}
/************************************************************************/
				/*Generate Start Condition  */
/************************************************************************/
u8 TWI_u8StartCondition(void){
	u8 error =StartAckError_true;

	/**Set Start Condition bit*/
	SET_BIT(TWCR , TWCR_TWSTA);
	/**Clear TWINT Flag */
	CLR_TWINT;
	/**Pool on TWINT Flag*/
	POOL_FLAG;
	/**Check Error Status*/
	if (  STATUS!=START_ACK ){
		error=NoError;
	}
	return error;
}
/************************************************************************/
				/*Generate Repeated Start Condition  */
/************************************************************************/
u8 TWI_u8RepeatedStartCondition(void){
	u8 error =RepStartAckError_true;
	/**Set Start Condition bit*/
	SET_BIT(TWCR , TWCR_TWSTA);
	/**Clear TWINT Flag */
	CLR_TWINT;
	/**Pool on TWINT Flag*/
	POOL_FLAG;
	/**Check Error Status*/
	if (  STATUS!=REP_START_ACK ){
		error=NoError;
	}
	return error;
}
/************************************************************************/
				/*Generate Stop Condition*/
/************************************************************************/
void TWI_u8StopCondition(void){
	/*Set Stop Condition Bit*/
	SET_BIT(TWCR,TWCR_TWSTO);
	/*Clear TWINT Flag */
	CLR_TWINT;
	/*Pool on TWINT Flag*/
	POOL_FLAG;
}
/************************************************************************/
				/*Master Mode Send Slave Address*/
/************************************************************************/
u8 TWI_vdMasterSendAddress(u8 Copy_u8Address , enum_operation Copy_enuOperation){
	u8 error=SendSlaveAddress_Error_exist;;

	/**Set Operation As Read or Write */
		TWDR =(Copy_u8Address <<1)	|  Copy_enuOperation;
	/**Clear Start Bit Generator */
	CLR_BIT(TWCR,TWCR_TWSTA );
	/**Clear TWINT Flag */
	CLR_TWINT;
	/**Pool on TWINT Flag*/
	POOL_FLAG
	/**Check Error Status*/
	if (  STATUS ==SLAVE_W_ACK || STATUS==SLAVE_R_NACK || STATUS==SLAVE_R_ACK || STATUS==SLAVE_R_NACK  ){
		error=NoError;
	}
	return error;
}
/************************************************************************/
				/*Master Mode  Send Data To Slave*/
/************************************************************************/
u8   TWI_u8MasterSendData( u8 Copy_u8Data){
	u8 error=SendData_Error_exist;
	/**Load Data in TWDR*/
	TWDR = Copy_u8Data;
	/**Clear TWINT Flag */
	CLR_TWINT;
	/**Pool on TWINT Flag*/
	POOL_FLAG
	/**Check Error Status*/
	if (  STATUS ==SLAVE_DATA_ACK  || STATUS ==SLAVE_DATA_NACK ){
		error=NoError;
	}
	return error;
}
/************************************************************************/
				/*Master Mode  Receive Data From Slave*/
/************************************************************************/
u8   TWI_u8MasterRecieveData( u8 * Pu8_Data ){
	u8 error=RecieveData_Error_exist;
	/**Clear TWINT Flag */
	CLR_TWINT;
	/**Pool on TWINT Flag*/
	POOL_FLAG;
	/**Receive Data*/
	*Pu8_Data=TWDR;
	/**Check Error Status*/
	if (STATUS ==MASTER_R_DATA_ACK || STATUS== MASTER_R_DATA_NACK){
		error=NoError;
	}
	return error;
}

/************************************************************************/
				/*Enable / Disable Ack bit generator*/
/************************************************************************/
void TWI_vdAckEnable(void){
	SET_BIT(TWCR,TWCR_TWEA);
}
void TWI_vdAckDisable(void){
	CLR_BIT(TWCR,TWCR_TWEA);
}












///************************************************************************/
//				/*Slave Mode Send  Data To Master*/
///************************************************************************/
//u8 TWI_vdSlaveSend(u8 Copy_u8Data);
///************************************************************************/
//				/*Slave Mode Receive Data From Master*/
///************************************************************************/
//
//u8   TWI_u8SlaveRecive(void);
//
///************************************************************************/
//				/*Set Slave Address*/
///************************************************************************/
//void TWI_vdSetSlaveAddress(u8 Copy_u8Address){
//TWAR=Copy_u8Address;

