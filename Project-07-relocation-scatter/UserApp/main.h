#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

#define __IO volatile

typedef struct
{
	__IO uint32_t CRL;
	__IO uint32_t CRH;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t BRR;
	__IO uint32_t LCKR;

} GPIO_TypeDef;

typedef struct
{
	__IO uint32_t CR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t APB2RSTR;
	__IO uint32_t APB1RSTR;
	__IO uint32_t AHBENR;
	__IO uint32_t APB2ENR;
	__IO uint32_t APB1ENR;
	__IO uint32_t BDCR;
	__IO uint32_t CSR;

} RCC_TypeDef;

typedef struct
{
	__IO uint32_t SR; /* USART Status register */
	__IO uint32_t DR; /* USART Data register */
	__IO uint32_t BRR; /* USART Baud rate register */
	__IO uint32_t CR1; /* USART Control register 1 */
	__IO uint32_t CR2; /* USART Control register 2 */
	__IO uint32_t CR3; /* USART Control register 3 */
	__IO uint32_t GTPR; /* USART Guard time and prescaler register */
} USART_TypeDef;


/*!< Peripheral memory map */
#define PERIPH_BASE 	(0x40000000UL)
#define APB1PERIPH_BASE (PERIPH_BASE + 0X00000000UL)
#define APB2PERIPH_BASE (PERIPH_BASE + 0x00010000UL)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE	(AHBPERIPH_BASE  + 0x00001000UL)
#define GPIOA_BASE	(APB2PERIPH_BASE + 0x00000800UL)
#define GPIOD_BASE  (APB2PERIPH_BASE + 0x00001400UL)
#define USART1_BASE	(APB2PERIPH_BASE + 0x00003800UL)

#define RCC 	((RCC_TypeDef *)RCC_BASE)
#define GPIOA 	((GPIO_TypeDef *)(GPIOA_BASE))
#define GPIOD 	((GPIO_TypeDef *)(GPIOD_BASE))
#define USART1	((USART_TypeDef *)(USART1_BASE))


#define __RCC_GPIOA_CLK_ENABLE()  	RCC->APB2ENR |= (1 << 2)
#define __RCC_GPIOD_CLK_ENABLE()  	RCC->APB2ENR |= (1 << 5)
#define __RCC_USART1_CLK_ENABLE()	RCC->APB2ENR |= (1 << 14)

#define GPIO_Pin_2  (1 << 2)
#define GPIO_Pin_8  (1 << 8)
#define GPIO_Pin_9  (1 << 9)
#define GPIO_Pin_10 (1 << 10)
#define GPIO_Pin_15 (1 << 15)

#define GPIO_PIN_SET (1)
#define GPIO_PIN_RST (0)

#define GPIO_WritePin(GPIOx, GPIO_Pin, PinState) \
	do{ \
		if (PinState) \
			GPIOx->BSRR = (uint32_t)GPIO_Pin; \
		else \
			GPIOx->BRR  = (uint32_t)GPIO_Pin; \
	}while(0)

#define GPIO_ReadPin(GPIOx, GPIO_Pin) (GPIOx->IDR & GPIO_Pin)
	
#endif

