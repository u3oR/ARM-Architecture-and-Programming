
#include <stdint.h>
#include "main.h"


void GPIO_Init()
{
	// 使能GPIOA GPIOD
	__RCC_GPIOA_CLK_ENABLE();
	__RCC_GPIOD_CLK_ENABLE();
	// 设置GPIOA8  通用输出/上拉/速度10MHz
	GPIOA->CRH &= 0xFFFFFFF0;
	GPIOA->CRH |= 0x00000001;
	// 设置GPIOD2  通用输出/上拉/速度10MHz
	GPIOD->CRL &= 0xFFFFF0FF;
	GPIOD->CRL |= 0x00000100;
	// 设置GPIOA15 浮动输入
	GPIOA->CRH &= 0x0FFFFFFF;
	GPIOA->CRH |= 0x80000000;
}

int main(void)
{

	GPIO_Init();
	
	while (1) {

		if(GPIO_ReadPin(GPIOA, GPIO_Pin_15) == 0) {
			// 设置PA8输出为 0; 设置PD2输出为 1
			GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_RST);
			GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_SET);
		}else {
			// 设置PA8输出为 1; 设置PD2输出为 0
			GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_SET);
			GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_RST);
		}
	}
}


