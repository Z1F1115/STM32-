#ifndef __BSP_BEEP_H__
#define __BSP_BEEP_H__
#include "stm32f10x.h"

//控制开关；1开，0关
#define  BEEP_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_2) : GPIO_ResetBits(GPIOB,GPIO_Pin_2)

//控制翻转
#define	 digitalHi(p,i)		  {p->BSRR=i;}	 //输出为高电平		
#define  digitalLo(p,i)		  {p->BRR=i;}	 //输出低电平
#define  digitalToggle(p,i)   {p->ODR ^=i;}  //输出反转状态
#define  BEEP_TOGGLE()      digitalToggle(GPIOB,GPIO_Pin_2)

void Beep_Init(void);

#endif
