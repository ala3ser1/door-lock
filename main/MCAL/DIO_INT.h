#ifndef DIO_INT_H_
#define DIO_INT_H_
#include "..\INC\STD_TYPES.h"
#include "..\INC\MemMap.h"
typedef enum{
	PIND0=0,
	PIND1=1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	
	
	
	PINC0=8,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	
	
	PINB0=16,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	
	
	PINA0=24,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	TOTAL_PIN
	
	}DIO_Pin_t;
	

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_status_t;
typedef enum{
	LOW,
	HIGH
	}VOLT_T;
	
	
	typedef enum{
	PORTA=0x3b,
	PORTB=0x38,
	PORTC=0x35,
	PORTD=0x32,
    }DIO_Port_t;
	
#define PIN_NUM (8)
#define CON_PIN_NUM (32)
#define PORT_REG_NUM (0X3)
#define FIRST_PIN_REG (0X30)
#define PIN_DDR_DIFFRENCE (0X1)
#define PIN_PORT_DIFFRENCE (0X2)
void DIO_WritePin(DIO_Pin_t pin,VOLT_T volt);
VOLT_T DIO_ReadPin(DIO_Pin_t pin);
void DIO_WritePort(DIO_Port_t port,u8 data);
u8 DIO_ReadPort(DIO_Port_t port);
 extern const DIO_status_t PinConfigratoin[TOTAL_PIN];
 void DIO_PinInti(void);
#endif /* DIO_INT_H_ */