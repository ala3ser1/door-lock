/*
 * ADC_PRG.c
 *
 * Created: 5/3/2024 2:50:20 PM
 *  Author: melaa

 */

#include "ADC_INT.h"
#include "..\MCAL\DIO_INT.h"
#define GET_BIT(x,y) (((x)>>(y))&1) 
#define ADEN 7
#define ADSC 6
#define REFS0 0
#define REFS1 1

void ADC_Init(ADC_VREF_t vref,ADC_Prescaler_t scaler)
{
	ADMUX=(ADMUX&0x3f)|(vref<<6);
	ADCSRA=(ADCSRA&0xf8)|scaler;
	SET_BIT(ADCSRA,ADEN);
}
void ADC_off(void)
{
	CLR_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(ADC_Channel_t ch)
{
	ADMUX=ADMUX&0b11100000;
	ADMUX=ADMUX|ch;
	SET_BIT(ADCSRA,ADSC);
	
	while(GET_BIT(ADCSRA,ADSC));
// 	DIO_WritePort(PORTD,GET_BIT(ADCSRA,ADSC));
// 	_delay_ms(1000);
// 	DIO_WritePort(PORTD,GET_BIT(ADCSRA,ADSC));
	return ADC;
}
