
#include <stdint.h>
#include "main.h"
#include "gpio.h"
#include "uart.h"
#include "my_string.h"

void Delay(uint32_t n)
{
	while(n--);
}

volatile uint32_t test_data = 0;

int main(void)
{	
	GPIO_Init();
	UART_Init();
	GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_RST);
	GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_RST);
	
	// 打印字符串
	puts("Hello World!\n");
	
	if(test_data == 0) {
		puts("a == 0\n");
	}else {
		puts("a != 0\n");
	}
	
	while(1);

}


