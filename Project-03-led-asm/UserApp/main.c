
#include <stdint.h>


#define PERIPH_BASE 	(0x40000000UL)
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE 	(AHBPERIPH_BASE  + 0x00001000UL)
#define RCC_APB2ENR_offset (0x18)

#define GPIOA_BASE 	(APB2PERIPH_BASE + 0x00000800UL)
#define GPIO_CRL_offset (0x00)
#define GPIO_CRH_offset (0x04)
#define GPIO_ODR_offset (0x0C)

void delay(uint32_t n)
{
	while(n--);
}

int main(void)
{
	// 使能GPIOA
	uint32_t *p;
	
	p = (uint32_t *)(RCC_BASE + RCC_APB2ENR_offset);
	*p |= (1 << 2);
	
	// 设置GPIOA8为输出引脚
	p = (uint32_t *)(GPIOA_BASE + GPIO_CRH_offset);
	*p |= (1 << 0);
	
	p = (uint32_t *)(GPIOA_BASE + GPIO_ODR_offset);
	
	while (1) 
	{
		// 设置GPIOA8输出为 1
		*p |= (uint32_t)(1 << 8);
		delay(100000);
		// 设置GPIOA8输出为 0
		*p &= ~(uint32_t)(1 << 8);
		delay(100000);
	}
}


