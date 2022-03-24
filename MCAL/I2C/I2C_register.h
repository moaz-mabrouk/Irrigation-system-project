#ifndef I2C_REGISTER_H
#define I2C_REGISTER_H

/************************************************************************/
								/*TWI Bit Rate Register */
/************************************************************************/
#define TWBR 				*((volatile u8 *)0x20)

/************************************************************************/
								/*TWI Control Register*/
/************************************************************************/
#define TWCR 				*((volatile u8 *)0x56)
#define TWCR_TWINT					7 /*TWI Interrupt Flag*/
#define TWCR_TWEA					6 /*TWI Enable Acknowledge Bit*/
#define TWCR_TWSTA         	     	5 /*TWI START Condition Bit*/
#define TWCR_TWSTO              	4 /*TWI STOP Condition Bit*/
#define TWCR_TWWC              		3 /*TWI Write Collision Flag*/
#define TWCR_TWEN					2 /*TWI Enable Bit*/
#define TWCR_TWIE						0 /*TWI Interrupt Enable*/

/************************************************************************/
								/*TWI Status Register*/
/************************************************************************/
#define TWSR 				*((volatile u8 *)0x21)
//#define TWSR_7			        			7 /*TWI Status*/
//#define TWSR_6			        			6 /*TWI Status*/
//#define TWSR_5                  			5 /*TWI Status*/
//#define TWSR_4                  			4 /*TWI Status*/
//#define TWSR_TWS                		3 /*TWI Status*/
#define TWSR_TWPS1			    	1 /*TWI Prescaler Bits*/
#define TWSR_TWPS0			    	0 /*TWI Prescaler Bits*/

/************************************************************************/
								/*TWI Data Register*/
/************************************************************************/
#define TWDR 		 		*((volatile u8 *)0x23)

/************************************************************************/
								/*TWI (Slave) Address Register*/
/************************************************************************/
#define TWAR				*((volatile u8 *)0x22)
#define TWAR_TWA						1 /*TWI (Slave) Address Register*/
#define TWAR_TWGCE				  	0 /*TWI General Call Recognition Enable Bit*/

#endif

