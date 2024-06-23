/*
 * DOOR_LOCK.h
 *
 * Created: 5/4/2024 11:34:53 PM
 *  Author: melaa
 */ 


#ifndef DOOR_LOCK_H_
#define DOOR_LOCK_H_
#include "..\INC\STD_TYPES.h"
#include "..\MCAL\DIO_INT.h"
#include "..\HAL\KEYPAD.h"
#include "..\HAL\LCD_INT.h"
#include "..\HAL\MOTOR_INT.h"
#include "..\MCAL\EEPROM_INT.h"
typedef enum{
	CLOSED,
	OPENED

}Door_Status_t;
typedef enum{
	Right,
	WRONG

}Password_Statues_t;
typedef enum{
	OPEN,
	CLOSE,
	NOTHING
	}INDOOR_t;

void DOOR_Inti(void);
Password_Statues_t DOOR_ReadKeypad(void);
void DOOR_ResetPassword(void);
void DOOR_OpenedMode(void);
INDOOR_t INDOOR(void);
void DOOR_INTERRUPT(INDOOR_t temp,pu8 str);
#endif /* DOOR_LOCK_H_ */