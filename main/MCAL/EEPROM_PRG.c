/*
 * EEPROM_PRG.c
 *
 * Created: 5/4/2024 11:46:15 PM
 *  Author: melaa
 */ 
#include "..\INC\STD_TYPES.h"
#include "..\INC\MemMap.h"
#include "..\MCAL\EEPROM_INT.h"
void EEPROM_Write (unsigned int Address, unsigned char data)
{
	//  Wait for completion of previous write
	while(EECR & (1<<EEWE));
	// Set up Address and data Registers
	EEAR = Address;
	EEDR = data;
	//start EEPROM write by setting EEWE.
	EECR |= (1<<EEMWE); // Write logical one to EEPROM Master Write Enable
	EECR |= (1<<EEWE);  // Start Writing
	
}

unsigned char EEPROM_Read (unsigned int Address)
{
	//  Wait for completion of previous write
	while(EECR & (1<<EEWE));
	// Set up Address and data Registers
	EEAR = Address;

	// Start EEPROM Read by writing logical one to EERE
	EECR |= (1<<EERE);

	// Return value
	return EEDR;
}
