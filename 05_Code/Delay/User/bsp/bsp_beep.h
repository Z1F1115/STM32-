#ifndef __BSP_BEEP_H__
#define __BSP_BEEP_H__
#include "stm32f10x.h"

//���ƿ��أ�1����0��
#define  BEEP_SET(x)	(x) ? GPIO_SetBits(GPIOB,GPIO_Pin_2) : GPIO_ResetBits(GPIOB,GPIO_Pin_2)

//���Ʒ�ת
#define	 digitalHi(p,i)		  {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define  digitalLo(p,i)		  {p->BRR=i;}	 //����͵�ƽ
#define  digitalToggle(p,i)   {p->ODR ^=i;}  //�����ת״̬
#define  BEEP_TOGGLE()      digitalToggle(GPIOB,GPIO_Pin_2)

void Beep_Init(void);

#endif
