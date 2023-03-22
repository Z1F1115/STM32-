#ifndef __HEAD_H__
#define __HEAD_H__
#include "stm32f10x.h"
#include "bsp_exti.h"

#define  LED4_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_10) : GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define  LED5_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_11) : GPIO_ResetBits(GPIOB,GPIO_Pin_11)

#endif
