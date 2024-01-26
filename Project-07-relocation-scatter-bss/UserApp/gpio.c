#include "main.h"
#include "gpio.h"

void GPIO_Init()
{
	// 使能GPIOA GPIOD
	__RCC_GPIOA_CLK_ENABLE();
	__RCC_GPIOD_CLK_ENABLE();
	// 设置GPIOA8 通用输出/上拉/速度10MHz
	GPIOA->CRH &= (0xFFFFFFF0);
	GPIOA->CRH |= (0x00000001);
	// 设置GPIOD2 通用输出/上拉/速度10MHz
	GPIOD->CRL &= (0xFFFFF0FF);
	GPIOD->CRL |= (0x00000100);
	
	GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_SET);
	GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_SET);
}


