
#include <stdint.h>
#include "main.h"
#include "gpio.h"
#include "uart.h"
#include "my_string.h"

void Delay(uint32_t n)
{
	while(n--);
}

const char *str = "i am 3oR.\n";

int user_main(void)
{	
	GPIO_Init();
	UART_Init();
	GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_RST);
	GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_RST);
	
	// 打印字符串
	// "Hello World!\n" 这段字符串的地址使用相对偏移地址获取, 实际的获取位置还在Flash中
	puts("\nHello World!\n");
	
	// str 会被链接到内存但内存未被初始化 因而无法打印
//	puts("i am 3oR.\n");
	puts(str);
	
	
	while(1);

}


