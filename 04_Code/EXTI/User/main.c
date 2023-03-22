/*********************************************
*	文件名称：led.c
*	文件描述：测试STM32机械臂开发板的LED
*	引脚定义：
* 		      LED4	  接PB10引脚
* 		      LED5    接PB11引脚
*   编写时间：2021-09-09      
* 	注意事项：LED引脚输出低电平则亮，反之灭
*********************************************/
#include "head.h"

//LED引脚初始化
void Led_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	
	//1. 开启GPIOB时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    
	//2. 配置LED引脚
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;				//推挽输出
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10 | GPIO_Pin_11;		//引脚定义
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;				//输出速率

	//3. 引脚初始化
	GPIO_Init(GPIOB, &GPIO_InitStructure);							
    
	//4. LED空闲状态 输出高电平 LED灭
    LED4_SET(1);
    LED5_SET(1);
}
int main()
{
	//1.硬件初始化
	Led_Init();
	bsp_exti_init();
	while(1)
	{
			//led输出低电平 灯亮 
//			LED4_SET(0);
//			LED5_SET(0);
	}

}


