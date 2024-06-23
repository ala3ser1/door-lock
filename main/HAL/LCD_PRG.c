
#include "LCD_INT.h"
#include "..\CFG\LCD_CFG.h"
#include "..\HAL\LCD_PRIVATE.h"
/*
static u8 i;
#define  LCD_PINS_NUM 4
#if LCD_PINS_NUM==8
#define LCD_PORT PORTA
#define LCD_E PINB0
#define LCD_RS PINB1
void LCD_SetCursor(lcd_line_t line ,lcd_cell_t cell)
{
	switch(line)
	{
		case 0:
		LcdIns(0x80+cell);
		break;
		case 1:
		LcdIns(0xc0+cell);
		break;
	}
}
void lcdClear(void)
{
	LcdIns(0x01);
	_delay_ms(2);
}

 void LcdIns(u8 command)
{
	DIO_WritePin(LCD_RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(LCD_E,HIGH);
	_delay_us(1);
	DIO_WritePin(LCD_E,LOW);
	_delay_us(45);
}

void lcdInti(void)
{
	LcdIns(0x38);//0x38 try it
	LcdIns(0x0E);
	lcdClear();
	LcdIns(0x03);
	_delay_ms(2);	
}
void lcdData(u8 letter)
{
	DIO_WritePin(LCD_RS,HIGH);
	DIO_WritePort(LCD_PORT,letter);
	DIO_WritePin(LCD_E,HIGH);
	_delay_us(1);
	DIO_WritePin(LCD_E,LOW);
	_delay_us(45);
}
#elif LCD_PINS_NUM==4
void lcd_WritePort(u8 num)
{
	DIO_WritePin(lcdArray[D4],GET_BIT(num,4));
	DIO_WritePin(lcdArray[D5],GET_BIT(num,5));
	DIO_WritePin(lcdArray[D6],GET_BIT(num,6));
	DIO_WritePin(lcdArray[D7],GET_BIT(num,7));
}
void LCD_SetCursor(lcd_line_t line ,lcd_cell_t cell)
{
	switch(line)
	{
		case 0:
		LcdIns(0x80+cell);
		break;
		case 1:
		LcdIns(0xc0+cell);
		break;
	}
}

 void LcdIns(u8 command)
{
	DIO_WritePin(lcdArray[RS],LOW);
	lcd_WritePort(command);
	DIO_WritePin(lcdArray[E],HIGH);
	_delay_ms(1);
	DIO_WritePin(lcdArray[E],LOW);
	_delay_ms(1);
}







void lcdInti(void)
{
	LcdIns(0x20);
	LcdIns(0x20);
	LcdIns(0x00);
	LcdIns(0x00);
	LcdIns(0xe0);
	LcdIns(0x00);
	LcdIns(0x10);
	LcdIns(0x00);
	LcdIns(0x60);
}
void lcdClear(void)
{
	LcdIns(0x00);
	LcdIns(0x10);
	_delay_ms(2);
}

void lcdData(u8 letter)
{
	DIO_WritePin(lcdArray[RS],HIGH);
	lcd_WritePort(letter);
	DIO_WritePin(lcdArray[E],HIGH);
	DIO_WritePin(lcdArray[E],LOW);
	lcd_WritePort(letter<<4);
	DIO_WritePin(lcdArray[E],HIGH);
	DIO_WritePin(lcdArray[E],LOW);
	_delay_ms(1);
}
#endif


void lcdNum(s32 num)
{
	u8 lcdArray[12];
	if(num==0)
	{
		lcdData('0');
	}
	else{
		if(GET_BIT(num,31))
		{
			lcdData('-');
			num=num*(-1);
		}else;
		numPakage(num,lcdArray);
		while(i!=0)
		{
			lcdData(lcdArray[--i]);
		}
	}
}

 void numPakage(s32 num,pu8 arr)
{
	i=0;
	while(num)
	{
		arr[i++]=(num%10)+'0';
		num=num/10;
	}
}
void lcdSentence(pu8 letter)
{
	u8 i=0;
	while(letter[i])
	{
		lcdData(letter[i++]);
	}
}
*/
#if  LCD_MODE==_8_BIT
void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	
	WriteIns(0x38);
	WriteIns(0x0c);//0x0e,0x0f
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);
}
#elif LCD_MODE==_4_BIT

void WriteIns(u8 ins)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,GET_BIT(ins,7));
	DIO_WritePin(D6,GET_BIT(ins,6));
	DIO_WritePin(D5,GET_BIT(ins,5));
	DIO_WritePin(D4,GET_BIT(ins,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,GET_BIT(ins,3));
	DIO_WritePin(D6,GET_BIT(ins,2));
	DIO_WritePin(D5,GET_BIT(ins,1));
	DIO_WritePin(D4,GET_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void WriteData(u8 ins)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,GET_BIT(ins,7));
	DIO_WritePin(D6,GET_BIT(ins,6));
	DIO_WritePin(D5,GET_BIT(ins,5));
	DIO_WritePin(D4,GET_BIT(ins,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,GET_BIT(ins,3));
	DIO_WritePin(D6,GET_BIT(ins,2));
	DIO_WritePin(D5,GET_BIT(ins,1));
	DIO_WritePin(D4,GET_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);
	WriteIns(0x28);
	WriteIns(0x0c);//0x0e,0x0f
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);
}

#endif








void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}

void LCD_WriteString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
	
}

void LCD_WriteNumber(s32 num)//-150
{
	u8 str[10];
	s8 i=0,j;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		LCD_WriteChar('-');
		num=-num;
	}
	while(num)
	{
		str[i++]=num%10+'0';
		num/=10;
	}
	for(j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
}

/* move on LCD*/

void LCD_Clear(void)
{
	WriteIns(0x01);
	_delay_ms(1);
	
}

void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(GET_BIT(num,i)+'0');
	}
	
}

void LCD_WriteHex(u8 num)
{
	u8 HN=num>>4;
	u8 LN=num&0x0f;
	
	if (HN<10)
	{
		LCD_WriteChar(HN+'0');
	}
	else
	{
		LCD_WriteChar(HN+'A'-10);
	}
	if (LN<10)
	{
		LCD_WriteChar(LN+'0');
	}
	else
	{
		LCD_WriteChar(LN+'A'-10);
	}
	
}


/* line 0:1 cell 0:15*/
void LCD_SetCursor(u8 line ,u8 cell)
{
	if (line==0)
	{
		WriteIns(cell+0x80);
	}
	else
	{
		WriteIns(cell+0x40+0x80);
	}
	
}

void LCD_ClearCursor(u8 line,u8 cell,u8 NofCells)
{
	LCD_SetCursor(line,cell);
	for (u8 i=0;i<NofCells;i++)
	{
		LCD_WriteChar(' ');
	}
	
}

void LCD_WriteStringCursor(u8 line,u8 cell,u8 *str)
{
	LCD_SetCursor(line,cell);
	LCD_WriteString(str);
}

