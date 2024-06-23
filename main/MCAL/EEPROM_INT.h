/*
 * EEPROM_INT.h
 *
 * Created: 5/4/2024 11:45:55 PM
 *  Author: melaa
 */ 


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#define EEWE 1
#define EEMWE 2
#define EERE 0
void EEPROM_Write (unsigned int Address, unsigned char data);
unsigned char EEPROM_Read (unsigned int Address);
#endif /* EEPROM_INT_H_ */