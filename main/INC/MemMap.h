

#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "STD_TYPES.h"
#define ADMUX (*(u8 volatile*)0x27)
#define ADCSRA (*(u8 volatile*)0x26)  
#define  ADCL (*(u8 volatile*)0x24)
#define  ADCH (*(u8 volatile*)0x25)
#define  ADC (*(u16 volatile*)0x24)

#define EECR   (*(u8 volatile* )0x3c)
#define EEDR   (*(u8 volatile*)0x3d)
#define EEAR   (*(u16 volatile*)0x3e)

#define PIND  (*(volatile pu8)0X30)
#define DDRD  (*(volatile pu8)0X31)
#define PRTD (*(volatile pu8)0X32)


#define PINC  (*(volatile pu8)0X33)
#define DDRC  (*(volatile pu8)0X34)
#define PRTC (*(volatile pu8)0X35)


#define PINB  (*(volatile pu8)0X36)
#define DDRB  (*(volatile pu8)0X37)
#define PRTB (*(volatile pu8)0X38)


#define PINA  (*(volatile pu8)0X39)
#define DDRA  (*(volatile pu8)0X3A)
#define PRTA (*(volatile pu8)0X3B)




#endif /* MEMMAP_H_ */