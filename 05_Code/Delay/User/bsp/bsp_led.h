#ifndef __BSP_LED_H__
#define __BSP_LED_H__
#include "stm32f10x.h"

//���ƿ��أ�0����1��
#define  LED4_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_10) : GPIO_ResetBits(GPIOB,GPIO_Pin_10)
#define  LED5_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_11) : GPIO_ResetBits(GPIOB,GPIO_Pin_11)

//���Ʒ�ת
#define	 digitalHi(p,i)		  {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define  digitalLo(p,i)		  {p->BRR=i;}	 //����͵�ƽ
#define  digitalToggle(p,i)   {p->ODR ^=i;}  //�����ת״̬
#define  LED4_TOGGLE()      digitalToggle(GPIOB, GPIO_Pin_10)
#define  LED5_TOGGLE()      digitalToggle(GPIOB, GPIO_Pin_11)

void Led_Init(void);

#endif
