
#include "DIO_PRIVATE.h"
#include "DIO_INT.h"
#include "..\CFG\DIO_CFG.h"

/*pin ddr port*/
static void DIO_IntiPin(DIO_Pin_t pin,DIO_status_t statues)
{
	pu8 port=((volatile pu8)FIRST_PIN_REG)+((pin/PIN_NUM)*PORT_REG_NUM);
	pin=pin%PIN_NUM;
	switch (statues)
	{
		case INFREE:
		CLR_BIT(*(port+PIN_DDR_DIFFRENCE),pin);
		CLR_BIT(*(port+PIN_PORT_DIFFRENCE),pin);
		break;
		case INPULL:
		CLR_BIT(*(port+PIN_DDR_DIFFRENCE),pin);
		SET_BIT(*(port+PIN_PORT_DIFFRENCE),pin);
		break;
		case OUTPUT:
		SET_BIT(*(port+PIN_DDR_DIFFRENCE),pin);
		CLR_BIT(*(port+PIN_PORT_DIFFRENCE),pin);
		break;
		default:
		break;
	}
}
void DIO_WritePin(DIO_Pin_t pin,VOLT_T volt)
{
	pu8 port=((volatile pu8)FIRST_PIN_REG)+((pin/PIN_NUM)*PORT_REG_NUM);
	pin=pin%PIN_NUM;
	port=port+PIN_PORT_DIFFRENCE;
	switch (volt)
	{
		case HIGH:
		SET_BIT(*(port),pin);
		break;
		case LOW:
		CLR_BIT(*(port),pin);
		break;	
	}
}
VOLT_T DIO_ReadPin(DIO_Pin_t pin)
{
	pu8 port=((volatile pu8)FIRST_PIN_REG)+((pin/PIN_NUM)*PORT_REG_NUM);
	pin=pin%PIN_NUM;
	VOLT_T ret=GET_BIT(*(port),pin);
	return ret;
}
void DIO_WritePort(DIO_Port_t port,u8 data)
{
	*(volatile pu8)port=data;
}
u8 DIO_ReadPort(DIO_Port_t port)
{
	volatile pu8 p=(pu8)port-PIN_PORT_DIFFRENCE;
	return *p;
}
void DIO_PinInti(void)
{
	DIO_Pin_t i;
	for(i=0;i<TOTAL_PIN;i++)
	{
		DIO_IntiPin(i,PinConfigratoin[i]);
	}
}