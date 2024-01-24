
#include <stdint.h>
#include "main.h"


void delay(uint32_t n)
{
	while(n--);
}


int user_main(void)
{
	// 使能GPIOA
	__RCC_GPIOA_CLK_ENABLE();
	
	// 设置GPIOA8为输出引脚
	// GPIO_Init();
	GPIOA->CRH |= (1 << 0);
	
	while (1) {
		// 设置GPIOA8输出为 1
		GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_Pin_SET);
		delay(500000);
		// 设置GPIOA8输出为 0
		GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_Pin_RST);
		delay(500000);
	}
}


