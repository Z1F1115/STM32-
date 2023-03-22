/*********************************************
*	文件名称：led.c
*	文件描述：测试STM32机械臂开发板的LED和BEEP
*	引脚定义：
* 		      LED4	  接PB10引脚
* 		      LED5    接PB11引脚
*			  BEEP    接PB2引脚
*   编写时间：2023-03-08      
* 	注意事项：
*			 1.LED引脚输出低电平则亮，反之灭
*			 2.BEEP引脚输出高电平则响，反之灭
*********************************************/
#include "stm32f10x.h"
#include "bsp_gpio.h"
void Delay(int u);

int main(void){
	
	//1.硬件初始化
	Led_Init();//LED
	Beep_Init();//蜂鸣器
	
	while(1){
		Delay(500);
		//led输出低电平 灯亮 
		LED4_SET(1);//LED1
		LED5_SET(0);//LED2
		//蜂鸣器输出高电平 响
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

