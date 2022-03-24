#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_vdSendData(u8 Copy_u8Block, u8 Copy_u8Address ,u8 Copy_u8Data);
u8	EEPROM_vdReadData(u8 Copy_u8Block, u8 Copy_u8Address);


#endif
