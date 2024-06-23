/*
 * LCD_INT.h
 *
 * Created: 4/26/2024 11:09:03 AM
 *  Author: melaa
 */ 


#ifndef LCD_INT_H_
#define LCD_INT_H_

#include "..\INC\STD_TYPES.h"
#define F_CPU 8000000
#include <util/delay.h>

#include "..\MCAL\DIO_INT.h"
#include "..\CFG\LCD_CFG.h"
/*
void lcdInti(void);
void lcdClear(void);
void lcdData(u8 letter);
void lcdNum(s32 num);
void lcdData(u8 letter);
void lcdSentence(pu8 letter);
typedef enum{
	CELL0,
	CELL1,
	CELL2,
	CELL3,
	CELL4,
	CELL5,
	CELL6,
	CELL7,
	CELL8,
	CELL9,
	CELL10,
	CELL11,
	CELL12,
	CELL13,
	CELL14,
	CELL15
	}lcd_cell_t;
	
typedef enum{
	LINE0,
	LINE1

	}lcd_line_t;
	
typedef enum{
	RS,
	E,
	D4,
	D5,
	D6,
	D7
	}lcd_pins_t;
void LCD_SetCursor(lcd_line_t line ,lcd_cell_t cell);
void LCD_ClearCursor(lcd_line_t line ,lcd_cell_t cell,u8 numOfCells);
extern DIO_Pin_t lcdArray[6];*/

void LCD_Init(void);

void LCD_WriteString(u8*str);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumber(s32 num);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);

/* line 0:1 cell 0:15*/
void LCD_SetCursor(u8 line ,u8 cell);

void LCD_ClearCursor(u8 line,u8 cell,u8 NofCells);

void LCD_WriteStringCursor(u8 line,u8 cell,u8 *str);

void LCD_CustomChar(u8 address,u8*pattern);



/* move on LCD*/

void LCD_Clear(void);


#endif /* LCD_INT_H_ */