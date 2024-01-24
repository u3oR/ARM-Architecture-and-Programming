#ifndef GPIO_H
#define GPIO_H

#include "main.h"

#define GPIO_Pin_2  (1 << 2)
#define GPIO_Pin_8  (1 << 8)
#define GPIO_Pin_9  (1 << 9)
#define GPIO_Pin_10 (1 << 10)
#define GPIO_Pin_15 (1 << 15)

typedef enum
{
  GPIO_PIN_RST = 0u,
  GPIO_PIN_SET
} GPIO_PinState;


void GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
GPIO_PinState GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif
