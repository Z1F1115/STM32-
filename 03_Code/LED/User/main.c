/*********************************************
*	�ļ����ƣ�led.c
*	�ļ�����������STM32��е�ۿ������LED��BEEP
*	���Ŷ��壺
* 		      LED4	  ��PB10����
* 		      LED5    ��PB11����
*			  BEEP    ��PB2����
*   ��дʱ�䣺2023-03-08      
* 	ע�����
*			 1.LED��������͵�ƽ��������֮��
*			 2.BEEP��������ߵ�ƽ���죬��֮��
*********************************************/
#include "stm32f10x.h"
#include "bsp_gpio.h"
void Delay(int u);

int main(void){
	
	//1.Ӳ����ʼ��
	Led_Init();//LED
	Beep_Init();//������
	
	while(1){
		Delay(500);
		//led����͵�ƽ ���� 
		LED4_SET(1);//LED1
		LED5_SET(0);//LED2
		//����������ߵ�ƽ ��
		BEEP_SET(0);//BEEP
		
		Delay(500);
		LED4_SET(0);//LED1
		LED5_SET(1);//LED2
		BEEP_SET(0);
		Delay(500);
		
	}
	//return 0;
}

void Delay(int u)
{
	int i,j;
	for(i=0;i<u;i++)
		for(j=0;j<12000;j++);
	
}

