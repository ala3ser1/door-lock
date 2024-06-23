/*
 * LCD_CFG.h
 *
 * Created: 4/26/2024 11:10:28 AM
 *  Author: melaa
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_
#include "..\MCAL\DIO_INT.h"
#include "..\HAL\LCD_INT.h"

#define  _4_BIT   1
#define  _8_BIT   2



#define  LCD_MODE  _4_BIT


#define  LCD_PORT   PA

#define  D7   PINA6
#define  D6   PINA5
#define  D5   PINA4
#define  D4   PINA3


#define  RS  PINA1
#define  EN  PINA2



#endif /* LCD_CFG_H_ */