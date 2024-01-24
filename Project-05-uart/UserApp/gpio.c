#include "main.h"
#include "gpio.h"

void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{

	if (PinState != GPIO_PIN_RST) 
	{
		GPIOx->BSRR = (uint32_t)GPIO_Pin;
	}
	else 
	{
		GPIOx->BRR = (uint32_t)GPIO_Pin;
	}
}

GPIO_PinState GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	return (GPIOx->IDR & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RST;
}
