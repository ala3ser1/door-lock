/*
 * DOOR_LOCK.c
 *
 * Created: 5/4/2024 11:34:34 PM
 *  Author: melaa
 */ 
#include "..\INC\STD_TYPES.h"
#include "..\MCAL\DIO_INT.h"
#include "..\HAL\LCD_INT.h"
#include "..\MCAL\ADC_INT.h"
#include "DOOR_LOCK.h"
#include "..\HAL\MOTOR_INT.h"
#define PASSWORD_BYTE1 0
#define PASSWORD_BYTE2 1
#define PASSWORD_BYTE3 2
#define PASSWORD_BYTE4 3

static u32 pass=6500;
static u32 volatile pass_read;
Door_Status_t doorStatues;


void display_Password_word(void)
{
	LCD_Clear();
	LCD_WriteString((pu8)"password:");
	LCD_SetCursor(1,0);
}
Door_Status_t DOOR_STATUS(void)
{
	u16 volt;
	volt=ADC_Read(CH_0);
	if(volt<150)
	{
		doorStatues=CLOSED;
	}
	else
	{
		doorStatues=OPENED;
	}
	return doorStatues;
};
void DOOR_Inti(void)
{

	pass=0;
	pass=EEPROM_Read (PASSWORD_BYTE4);
	pass=(pass<<8)|(EEPROM_Read (PASSWORD_BYTE3));
	pass=(pass<<8)|(EEPROM_Read (PASSWORD_BYTE2));
	pass=(pass<<8)|(EEPROM_Read (PASSWORD_BYTE1));
	DOOR_STATUS();
	display_Password_word();
}
Password_Statues_t DOOR_ReadKeypad(void)
{
	INDOOR_t temp;
	u8 i=0;
	u8 key;
	Password_Statues_t ret;
	display_Password_word();
	pass_read=0;
	while(i<8)
	{
		temp=INDOOR();
		if(temp!=NOTHING)
		{
			DOOR_INTERRUPT(temp,"password:      ");
			LCD_SetCursor(1,i);
		}
		
		key=Keypad_ReadKey();
		if(key!='t')
		{
			if(key=='c')
			{
				pass_read=0;
				i=0;
				display_Password_word();	
			}
			else if((key<='9')&&(key>='0'))
			{
				LCD_WriteChar(key);
				pass_read=pass_read*10+(key-'0');
				i++;
			}
			else if(key=='=')
			{
				break;
			}
		}
	
		else
		{
			;
		}
	}
	if(pass==pass_read)
	{
		ret=Right;
	}
	else
	{
		ret=WRONG;
	}
	return ret;
}
INDOOR_t INDOOR(void)
{
	INDOOR_t ret=NOTHING;
	if(DIO_ReadPin(PINB2)==LOW)
	{
		
		_delay_ms(20);
		if(DIO_ReadPin(PINB2)==LOW)
		{
			while(DIO_ReadPin(PINB2)==LOW);
			if(doorStatues==OPENED)
			{
				ret = NOTHING;
			}
			else
			{
				ret = OPEN;
			}
		}
		
	}
	else if(DIO_ReadPin(PINB3)==LOW)
	{
		
		_delay_ms(20);
		if(DIO_ReadPin(PINB3)==LOW)
		{
			while(DIO_ReadPin(PINB3)==LOW);
			if(doorStatues==OPENED)
			{
				ret = CLOSE;
			}
			else
			{
				ret =NOTHING;
			}
		}
		
	}
	return ret;
}
void DOOR_INTERRUPT(INDOOR_t temp,pu8 str)
{
	
		if(temp==CLOSE)
		{
			LCD_SetCursor(0,0);
			LCD_WriteString("door close !!      ");
			MotorCCW(MOTOR0);
			_delay_ms(2000);
			doorStatues=CLOSED;
			MotorStop(MOTOR0);
			LCD_SetCursor(0,0);
			LCD_WriteString(str);
			
		}
		else if(temp==OPEN)
		{
			LCD_SetCursor(0,0);
			LCD_WriteString("door open !!     ");
			MotorCW(MOTOR0);
			_delay_ms(2000);
			doorStatues=OPENED;
			MotorStop(MOTOR0);
			LCD_SetCursor(0,0);
			LCD_WriteString(str);
			
		}	
	
}
void DOOR_ResetPassword(void)
{
	INDOOR_t temp;
	LCD_Clear();
	LCD_WriteString("new password:");
	LCD_SetCursor(1,0);
	u8 volatile i=0,key=0;
	u32 new_pass=0;
	while((i<8))
	{ 
		temp=INDOOR();
		if(temp!=NOTHING)
		{
			DOOR_INTERRUPT(temp,"new password:    ");
			LCD_SetCursor(1,i);
		}
		key=Keypad_ReadKey();
		if((key<='9')&&(key>='0'))
		{
			LCD_WriteChar(key);
			new_pass=(new_pass*10)+(key-'0');
			i++;
		}
		else if(key=='c')
		{
			return;
		}
		else if (key=='=')
		{
			
			break;
		}
	}
	pass=new_pass;
	LCD_Clear();
	LCD_WriteString("saving password..");
	EEPROM_Write(PASSWORD_BYTE1,(u8)new_pass);
	new_pass>>=8;
	EEPROM_Write(PASSWORD_BYTE2,(u8)new_pass);
	new_pass>>=8;
	temp=INDOOR();
	if(temp!=NOTHING)
	{
		DOOR_INTERRUPT(temp,"con new Password");
	}
	EEPROM_Write(PASSWORD_BYTE3,(u8)new_pass);
	new_pass>>=8;
	EEPROM_Write(PASSWORD_BYTE4,(u8)new_pass);
	_delay_ms(1000);
	if(temp!=NOTHING)
	{
		DOOR_INTERRUPT(temp,"saving password..   ");
	}
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("done");
	_delay_ms(500);
	
}

void DOOR_OpenedMode(void)
{
	u8 flag=0;
	INDOOR_t temp;
	u16 volatile count =0;
	u16 volatile i=0;
	u8 key;
	LCD_Clear();
	LCD_WriteString("select option   ");
	
	for(;count<100;count++)
	{
		
		for(i=0;i<30;i++)
		{
			temp=INDOOR();
			if(temp!=NOTHING)
			{
				DOOR_INTERRUPT(temp,"select option   ");
			}
			key=Keypad_ReadKey();
			if(key!='t')
			{
				if(key=='/')
				{
					DOOR_ResetPassword();
					LCD_Clear();
					LCD_WriteString("select option   ");
				}
				else if(key=='*')
				{
					
					if(doorStatues==CLOSED)
					{
						
						MotorCW(MOTOR0);
						doorStatues=OPENED;
						_delay_ms(2000);
						MotorStop(MOTOR0);
						LCD_SetCursor(1,0);
						LCD_WriteString("door opened");
						_delay_ms(1000);
						LCD_SetCursor(1,0);
						LCD_WriteString("                     ");
					}
					else
					{
						LCD_SetCursor(1,0);
						LCD_WriteString("door opened");
						_delay_ms(1000);
						LCD_SetCursor(1,0);
						LCD_WriteString("                     ");
					}
				}
				
				else if(key=='-')
				{
					if(doorStatues==CLOSED)
					{
						LCD_SetCursor(1,0);
						LCD_WriteString("door closed");
						_delay_ms(1000);
						LCD_SetCursor(1,0);
						LCD_WriteString("                     ");
						/*open door*/
					}
					else
					{
						MotorCCW(MOTOR0);
						doorStatues=CLOSED;
						_delay_ms(2000);
						MotorStop(MOTOR0);
						LCD_SetCursor(1,0);
						LCD_WriteString("door closed");
						_delay_ms(1000);
						LCD_SetCursor(1,0);
						LCD_WriteString("                     ");
					}
				}
				else if(key=='+')
				{
					if(doorStatues==CLOSED)
					{
						LCD_SetCursor(1,0);
						LCD_WriteString("door closed");
						_delay_ms(2000);
					}
					else
					{
						MotorCCW(MOTOR0);
						doorStatues=CLOSED;
						_delay_ms(2000);
						MotorStop(MOTOR0);
						LCD_SetCursor(1,0);
						LCD_WriteString("door closed");
						_delay_ms(1000);
					}
					return;
				}
				else if((key=='=')&&flag)
				{
					LCD_Clear();
					LCD_WriteString("(- or +) to close");
					while((key!='-')&&(key!='+'))
					{
						key=Keypad_ReadKey();
						temp=INDOOR();
						if(temp!=NOTHING)
						{
							DOOR_INTERRUPT(temp,"               ");
							break;
						}
					}
					LCD_Clear();
					count=1000;
					i=6;
				}
				
			}
			
			if((count==950)&&(doorStatues==OPENED))
			{
				LCD_SetCursor(0,0);
				LCD_WriteString("door will be closed");
				LCD_SetCursor(1,0);
				LCD_WriteString("press = to cancel");
				flag=1;
				
			}
			_delay_ms(1);
		}
	}
	
	if(doorStatues==OPENED)
	{
		LCD_Clear();
		LCD_WriteString("ten sec to close");
		LCD_SetCursor(1,0);
		LCD_WriteString("time:");
		for(i=10;i>0&&doorStatues==OPENED;i--)
		{
			temp=INDOOR();
			if(temp!=NOTHING)
			{
				DOOR_INTERRUPT(temp,"ten sec to close  ");
			}
			LCD_SetCursor(1,5);
			LCD_WriteNumber(i);
			LCD_WriteChar(' ');
			_delay_ms(1000);
		}
		if(doorStatues==OPENED)
		{
			MotorCCW(MOTOR0);
			doorStatues=CLOSED;
			_delay_ms(2000);
			MotorStop(MOTOR0);
			LCD_SetCursor(1,0);
			LCD_WriteString("door closed");
			_delay_ms(500);
			
		}
		
	}
	
}

