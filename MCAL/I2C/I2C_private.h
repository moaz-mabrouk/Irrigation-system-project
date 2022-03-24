#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H
/* TWI states */
/*** For Master mode ****/
#define   START_ACK            0x08
#define   REP_START_ACK        0x10
#define   SLAVE_W_ACK          0x18
#define   SLAVE_W_NACK         0x20
#define   SLAVE_DATA_ACK       0x28
#define   SLAVE_DATA_NACK      0x30
#define   SLAVE_R_ACK          0x40
#define   SLAVE_R_NACK         0x48
#define   MASTER_R_DATA_ACK    0x50
#define   MASTER_R_DATA_NACK   0x58

/*** For Slave mode ****/
#define   SLAVE_ADDRESS_W_ACK  0x60
#define   SLAVE_GEN_CALL_ACK   0x70
#define   SLAVE_DATA_REC_ACK   0x80
#define   SLAVE_DATA_REC_NACK  0x88


#define  TWSR_MASK   0xF8
#define POOL_FLAG  while ( GET_BIT(TWCR , TWCR_TWINT) ==0 )

#define STATUS	(TWSR & 0xF8)
#define CLR_TWINT	SET_BIT(TWCR,TWCR_TWINT)
#endif
