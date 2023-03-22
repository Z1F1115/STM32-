#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__
#include "stm32f10x.h"

#define  LED4_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_10) : GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define  LED5_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_11) : GPIO_ResetBits(GPIOB,GPIO_Pin_11)
#define  BEEP_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_2) : GPIO_ResetBits(GPIOB,GPIO_Pin_2)

void Led_Init(void);
void Beep_Init(void);

#endif
