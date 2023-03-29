/*********************************************
*	�ļ����ƣ�led.c
*	�ļ�����������STM32��е�ۿ������LED
*	���Ŷ��壺
* 		      LED4	  ��PB10����
* 		      LED5    ��PB11����
*   ��дʱ�䣺2021-09-09      
* 	ע�����LED��������͵�ƽ��������֮��
*********************************************/
#include "head.h"

int main()
{
	uint32_t count = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // �жϷ���
	//1.Ӳ����ʼ��
	Led_Init();
	Beep_Init();
	bsp_exti_init();
	while(1)
	{
		bsp_delay_us(500000);
		LED4_SET(0);
		LED5_SET(1);
		BEEP_SET(0);
		bsp_delay_us(500000);
		LED4_SET(1);
		LED5_SET(0);
		BEEP_SET(0);
	}

}


