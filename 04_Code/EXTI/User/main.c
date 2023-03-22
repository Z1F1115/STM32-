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

//LED���ų�ʼ��
void Led_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	
	//1. ����GPIOBʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
	//2. ����LED����
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;				//�������
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10 | GPIO_Pin_11;		//���Ŷ���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				//�������

	//3. ���ų�ʼ��
	GPIO_Init(GPIOB, &GPIO_InitStructure);							
    
	//4. LED����״̬ ����ߵ�ƽ LED��
    LED4_SET(1);
    LED5_SET(1);
}
int main()
{
	//1.Ӳ����ʼ��
	Led_Init();
	bsp_exti_init();
	while(1)
	{
			//led����͵�ƽ ���� 
//			LED4_SET(0);
//			LED5_SET(0);
	}

}


