#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*****************************************************************/
/*					 Clock polarity enum					 					 */
/*****************************************************************/
typedef enum {
	rising_faling=0x00,
	faling_rising=0x08
}enum_clkPolarity;

/*****************************************************************/
/*					 Clock phase  enum					 						 */
/*****************************************************************/
typedef enum {
	leading_sample=0x00,
	leading_setup=0x04
}enum_clkPhase;

/*****************************************************************/
/*					 Clock rate  enum					 							 */
/*****************************************************************/
typedef enum{
	clk_4 = 0x00,
	clk_16 = 0x01,
	clk_64 = 0x02,
	clk_128 =0x03,
	clk_2 = 0x10,
	clk_8 = 0x11,
	clk_32 = 0x12,
	clk_64x2 = 0x13

}enum_clkRate;

/*****************************************************************/
/*					 Master/Slave mode enum							 	 */
/*****************************************************************/
typedef enum{
	slave=0x00,
	master=0x10

}enum_mstr;

/*****************************************************************/
/*						Prototypes												     */
/*****************************************************************/
void  SPI_vdInit(enum_mstr Copy_enuMstrMode, enum_clkPolarity Copy_enuPolarity, enum_clkPhase Copy_enuphase, enum_clkRate Copy_enuRate);
void  SPI_vdDisable(void);
u8     SPI_u8MasterDataRW(u8 Copy_u8Setup);
void  SPI_vdSlaveDataWrite(u8 Copy_u8Data);
u8     SPI_u8SlaveDataRead(void);
void SPI_vdInterruptEnable(void);
void SPI_vdInterruptDisable(void);

#endif
