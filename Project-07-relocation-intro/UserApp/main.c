
#include <stdint.h>
#include <string.h>
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
	GPIOA->CRH &= (0xFFFFFFF0);
	GPIOA->CRH |= (0x00000001);
	// 设置GPIOD2 通用输出/上拉/速度10MHz
	GPIOD->CRL &= (0xFFFFF0FF);
	GPIOD->CRL |= (0x00000100);
	
	GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_SET);
	GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_SET);
}

void UART_Init()
{
	// 使能GPIOA USART1
	__RCC_USART1_CLK_ENABLE();
	__RCC_GPIOA_CLK_ENABLE();
	// 设置PA9  USART1_TX 功能输出/上拉/速度10MHz 0b1001 = 0x9
	GPIOA->CRH &= 0xFFFFFF0F;
	GPIOA->CRH |= 0x00000090;
	// 设置PA10 USART1_RX 浮动输入 0b0100 = 0x4
	GPIOA->CRH &= 0xFFFFF0FF;
	GPIOA->CRH |= 0x00000400;
	
	// 设置波特率 115200 = FCLK/(16 * USARTDIV)
	// FCLK = 8000000 USARTDIV = 4.3402 ~ 4.34
	// USARTDIV 整数部分: 4 
	// USARTDIV 小数部分: 0.34 * 16 = 5.44 ~ 5
	USART1->BRR = (uint16_t)((4 << 4) + 5);
	
	// 设置数据格式 8n1 8数据位 无校验位 1停止位
	// CR1[13:0] = 0bXX10_0000_0000_1100 = 0x200C
	USART1->CR1 = 0x200C;
	// CR2[14:0] = 0bX000_0000_0000_0000 = 0x0000
	USART1->CR2 = 0x0000;

}

int putc(char c)
{
	// while (USART1->SR->TXE == 0);
	// 等待SR寄存器TXE位 为 1
	while((USART1->SR & (1 << 7)) == 0);
	
	USART1->DR = c;
	
	return c;
}


int getc()
{
	
	// while (USART1->SR->TXE == 0);
	// 等待SR寄存器RXNE位 为 1
	while((USART1->SR & (1 << 5)) == 0);
	
	return USART1->DR;
}



const char c1 = '3';
static char c2 = 'R';

int main(void)
{	
	const char *s = "Hello World!\n";
	GPIO_Init();
	UART_Init();
	GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_RST);
	GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_RST);
	
	// 初始化全局变量 c2 (可读可写的数据段需要重定位)
	char *p = (char *)0x20000000;
	*p = '3';
	// 打印字符
	putc(c1);
	putc(c2);
	
	while(1);

}


