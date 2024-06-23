/*
 * KEYPAD.h
 *
 * Created: 5/4/2024 1:20:59 AM
 *  Author: melaa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "..\INC\STD_TYPES.h"
#include "..\MCAL\DIO_INT.h"
void Keypad_inti(void);
u8 Keypad_ReadKey(void);
typedef struct {
	char keypad_rows;
	char keypad_cols;
	DIO_Pin_t*p;
	u8* key;
}keypad_t;
extern const keypad_t keypad_struct;
extern const u8 keypad_arr[4][4];

#endif /* KEYPAD_H_ */