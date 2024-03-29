
#include <stdint.h>
#include "main.h"
#include "gpio.h"
#include "uart.h"
#include "my_string.h"

void Delay(uint32_t n)
{
	while(n--);
}

// 元素个数太少会被放在data段, 
static uint32_t test_data[3] = {0};

int main(void)
{	
	GPIO_Init();
	UART_Init();
	GPIO_WritePin(GPIOA, GPIO_Pin_8, GPIO_PIN_RST);
	GPIO_WritePin(GPIOD, GPIO_Pin_2, GPIO_PIN_RST);
	
	// 打印字符串
	puts("Hello World!\n");
	
	if(test_data[1] == 0) {
		puts("a[1] == 0\n");
	}else {
		puts("a[1] != 0\n");
	}
	
	while(1);

}


