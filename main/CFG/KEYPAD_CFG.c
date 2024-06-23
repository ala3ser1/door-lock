/*
 * KEYPAD_CFG.c
 *
 * Created: 5/4/2024 1:25:31 AM
 *  Author: melaa
 */ 
#include "..\HAL\KEYPAD.h"
#include "KEYPAD_CFG.h"

DIO_Pin_t keypad_pins[8]={
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PIND2,
	PIND3,
	PIND4,
	PIND5
	};

const u8 keypad_arr[4][4]={
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'c','0','=','+'},	
	};
const keypad_t keypad_struct={4,4,keypad_pins,(pu8)keypad_arr} ;/*rows colums &of keypad arr*/