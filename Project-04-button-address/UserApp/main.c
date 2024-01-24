
//#include <stdint.h>
typedef unsigned int uint32_t;

#define PERIPH_BASE 	(0x40000000UL)
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE 	(AHBPERIPH_BASE  + 0x00001000UL)
#define RCC_APB2ENR_offset (0x18)

#define GPIOA_BASE 	(APB2PERIPH_BASE + 0x00000800UL)
#define GPIOD_BASE 	(APB2PERIPH_BASE + 0x00001400UL)
#define GPIO_CRL_offset (0x00)
#define GPIO_CRH_offset (0x04)
#define GPIO_IDR_offset (0x08)
#define GPIO_ODR_offset (0x0C)

void delay(uint32_t n)
{
	while(n--);
}

int main(void)
{
	
	uint32_t *p;
	uint32_t *p_key;
	uint32_t *p_led;
	
	// 使能GPIOA
	p = (uint32_t *)(RCC_BASE + RCC_APB2ENR_offset);
	*p |= (1 << 2);
	
	// 设置GPIOA8 通用输出/上拉/速度10MHz
	p = (uint32_t *)(GPIOA_BASE + GPIO_CRH_offset);
	*p &= (0xFFFFFFF0); //清零最低4bit
	*p |= (0x00000001); //最低4bit为0b0001 = 0x1
	// 设置GPIOA15 浮动输入
	*p &= (0x0FFFFFFF); //清零最高4bit
	*p |= (0x80000000); //最高4bit 为 0b1000 = 0x8
	
	// PA8 LED0
	p_led = (uint32_t *)(GPIOA_BASE + GPIO_ODR_offset);
	// PA15 KEY1
	p_key = (uint32_t *)(GPIOA_BASE + GPIO_IDR_offset);
	
	while (1) {
		
		if(*p_key & 0x00008000) {
			*p_led |= (uint32_t)(1 << 8);
		}else {
			*p_led &= ~(uint32_t)(1 << 8);
		}
	}
}


