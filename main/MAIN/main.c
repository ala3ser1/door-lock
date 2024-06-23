
#include "..\MCAL\DIO_INT.h"
#include "..\HAL\MOTOR_INT.h"
#include "..\HAL\LCD_INT.h"
#include "..\MCAL\ADC_INT.h"
#include "..\HAL\KEYPAD.h"
#include "..\APP\DOOR_LOCK.h"
#include "..\MCAL\EEPROM_INT.h"


int main(void)
{
	u8 i;
	u16 blocktime;
	DIO_PinInti();
	LCD_Init();
	Keypad_inti();
	ADC_Init(VREF_VCC,ADC_SCALER_64);
	DOOR_Inti();
	INDOOR_t temp;

	while (1)
	{
		for(i=0;i<3;i++)
		{
			Password_Statues_t temp=DOOR_ReadKeypad();
			if(temp==Right)
			{
				break;
			}
			else if(i<2)
			{
				LCD_SetCursor(1,0);
				LCD_WriteString("try again");
				_delay_ms(500);
				LCD_SetCursor(1,0);
				LCD_WriteString("               ");
			}
		}
		if(i==3)
		{
			LCD_Clear();
			LCD_WriteString("blocked 5 MIN");
			u8 flag=1;
			for(i=5;i>=1&&flag;i--)
			{
				temp=INDOOR();
				if(temp!=NOTHING)
				{
					DOOR_INTERRUPT(temp,"password:");
					break;
				}
				LCD_SetCursor(0,8);
				LCD_WriteNumber(i);
				for(blocktime=0;blocktime<60;blocktime++)
				{
					_delay_ms(100);
					temp=INDOOR();
					if(temp!=NOTHING)
					{
						DOOR_INTERRUPT(temp,"password:");
						flag=0;
						break;
					}
				}
			}
			
		}
		else
		{
			DOOR_OpenedMode();
		}
	}
	return 0;
}

