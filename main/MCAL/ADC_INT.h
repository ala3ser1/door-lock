/*
 * ADC_INT.h
 *
 * Created: 5/3/2024 2:48:56 PM
 *  Author: melaa
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_
#include "..\INC\STD_TYPES.h"
#include "..\INC\MemMap.h"
typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4,
	ADC_SCALER_8,
	ADC_SCALER_16,
	ADC_SCALER_32,
	ADC_SCALER_64,
	ADC_SCALER_128,
	}ADC_Prescaler_t;
typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
}ADC_Channel_t;
typedef enum{
	VREF_AREF=0,
	VREF_VCC=1,
	VREF_256=3
}ADC_VREF_t;
void ADC_Init(ADC_VREF_t vref,ADC_Prescaler_t scaler);
u16 ADC_Read(ADC_Channel_t ch);
void ADC_off(void);


#endif /* ADC_INT_H_ */