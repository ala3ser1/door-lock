/*
 * Keypad_Prg.c
 *
 * Created: 5/4/2024 1:20:45 AM
 *  Author: melaa
 */ 

#include "..\MCAL\DIO_INT.h"
#include "KEYPAD.h"
DIO_Pin_t*p;

void Keypad_inti(void)
{
	u8 row =keypad_struct.keypad_rows;
	//u8 col=keypad_struct.keypad_cols;
	DIO_Pin_t*p=keypad_struct.p;
	u8 i;
	for(i=0;i<row;i++)
	{
		DIO_WritePin(p[i],HIGH);
	}
}

u8 Keypad_ReadKey(void)
{
	u8 ret='t';
	u8 row =keypad_struct.keypad_rows;
	u8 col=keypad_struct.keypad_cols;
	DIO_Pin_t*p=keypad_struct.p;
	u8*arr=keypad_struct.key;
	u8 r,c;u8 i=row+col;
	for(r=0;r<row;r++)
	{
		DIO_WritePin(p[r],LOW);
		for(c=row;c<i;c++)
		{
			if(DIO_ReadPin(p[c])==LOW)
			{
				_delay_ms(15);
				if(DIO_ReadPin(p[c])==LOW)
				{
					while(DIO_ReadPin(p[c])==LOW);
					ret= arr[r*col+(c-row)];
					break;
				}
				
			}
		}
		DIO_WritePin(p[r],HIGH);
	}
	return ret;
}

