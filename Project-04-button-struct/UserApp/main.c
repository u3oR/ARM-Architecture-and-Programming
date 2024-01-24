
#include <stdint.h>
#include "main.h"


void Delay(uint32_t n)
{
	while(n--);
}

void GPIO_Init()
{
	// 使能GPIOA GPIOD
	__RCC_GPIOA_CLK_ENABLE();
	__RCC_GPIOD_CLK_ENABLE();
	// 设置GPIOA8 通用输出/上拉/速度10MHz
	// 设置GPIOD2 通用输出/上拉/速度10MHz
	GPIOA->CRH |= (0x0001 << 0);
	GPIOD->CRL |= (0x0001 << 8);
}

void UART_Init()
{
	// 使能GPIOA USART1
	__RCC_USART1_CLK_ENABLE();
	__RCC_GPIOA_CLK_ENABLE();
	// 设置PA9  USART1_TX 功能输出/上拉/速度10MHz
	// 设置PA10 USART1_RX 功能输出/上拉/速度10MHz
	GPIOA->CRH |= (1 << 4); // PA9
	GPIOA->CRH |= (1 << 8); // PA10
}

int main(void)
{

	GPIO_Init();
	//UART_Init();

	while (1) {
		// 设置PA8输出为 1; 设置PD2输出为 0
		GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_RST);
		GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_SET);
		Delay(500000);
		// 设置PA8输出为 0; 设置PD2输出为 1
		GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_SET);
		GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_RST);
		Delay(500000);
	}
}


