#include "uart.h"
#include "main.h"


int putc(char c)
{
	// while (USART1->SR->TXE == 0);
	// 等待SR寄存器TXE位 为 1
	while((USART1->SR & (1 << 7)) == 0);
	
	USART1->DR = c;
	
	return c;
}

void puts(const char *s)
{
	while(*s != '\0') {
		putc(*s++);
	}
}

int getc()
{
	
	// while (USART1->SR->TXE == 0);
	// 等待SR寄存器RXNE位 为 1
	while((USART1->SR & (1 << 5)) == 0);
	
	return USART1->DR;
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
