#ifndef __BSP_LED_H__
#define __BSP_LED_H__
#include "stm32f10x.h"

//控制开关；0开，1关
#define  LED4_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_10) : GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define  LED5_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_11) : GPIO_ResetBits(GPIOB,GPIO_Pin_11)

//控制翻转
#define	 digitalHi(p,i)		  {p->BSRR=i;}	 //输出为高电平		
#define  digitalLo(p,i)		  {p->BRR=i;}	 //输出低电平
#define  digitalToggle(p,i)   {p->ODR ^=i;}  //输出反转状态
#define  LED4_TOGGLE()      digitalToggle(GPIOB, GPIO_Pin_10)
#define  LED5_TOGGLE()      digitalToggle(GPIOB, GPIO_Pin_11)

void Led_Init(void);

#endif
