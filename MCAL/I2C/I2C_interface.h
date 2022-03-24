#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H


//typedef enum {
//	Start_True=0x08,
//	RepeatedStart_true=0x10,
//
//	MT_Slave_Ack=0x18,
//	MT_Slave_NAck=0x20,
//	MT_Data_Ack=0x28,
//	MT_Data_NAck=0x30,
//	MT_ArbLost=0x38,
//
//	MR_ArbLost=0x38,
//	MR_Slave_Ack=0x40,
//	MR_Slave_NAck=0x48,
//	MR_Data_Ack=0x50,
//	MR_Data_NAck=0x58,
//
//	SR_Slav_Ack=0x60,
//	SR_ArbLost_OwnSlavW_Ack=0x68,
//	SR_Gc_Slav_Ack=0x70,
//	SR_ArbLost_Gc_Ack=0x78,
//	SR_Data_Ack=0x80,
//	SR_Data_NAck=0x88,
//	SR_Gc_Data_Ack=0x90,
//	SR_Gc_Data_NAck=0x98,
//
//
//	ST_Slav_Ack=0xA8,
//	ST_ArbLost_OwnSlav_Ack=0xB0,
//	ST_Data_Ack=0xB8,
//	ST_Data_NAck=0xC0,
//
//}enum_TwiStatus;


typedef enum{
	MasterWrite,
	MasterRead
}enum_operation;

typedef enum {
	NoError,
	StartAckError_true,
	RepStartAckError_true,
	SendSlaveAddress_Error_exist,
	SendData_Error_exist,
	RecieveData_Error_exist,
}enum_ErrorStatus;


void TWI_vdInit(u8 Copy_u8Address);
u8 TWI_u8StartCondition(void);
u8 TWI_u8RepeatedStartCondition(void);
void  TWI_u8StopCondition(void);
u8 TWI_vdMasterSendAddress(u8 Copy_u8Address , enum_operation Copy_enuOperation);
u8   TWI_u8MasterSendData( u8 Copy_u8Data);
u8   TWI_u8MasterRecieveData( u8 * Pu8_Data );
void TWI_vdAckEnable(void);
void TWI_vdAckDisable(void);

#endif
