#include "head.h"
/*
SetBits - 高电平
ResetBits - 低电平
*/

// LED引脚初始化
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
