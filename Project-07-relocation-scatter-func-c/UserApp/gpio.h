#ifndef GPIO_H
#define GPIO_H


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

void GPIO_Init(void);

#endif
