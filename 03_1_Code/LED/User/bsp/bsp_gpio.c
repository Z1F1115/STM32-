#include "bsp_gpio.h"

/*
SetBits - 高电平
ResetBits - 低电平
*/

// LED引脚初始化
void Led_Init(void){

    GPIO_InitTypeDef GPIO_InitStruct;

    // 1. 开启GPIOB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    // 2. 配置LED引脚
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // 推挽输出
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;        // 引脚定义
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; // 输出速率

    // 3. 引脚初始化
    GPIO_Init(GPIOB, &GPIO_InitStruct);

    // 4. LED空闲状态 输出低电平 LED亮
//  GPIO_ResetBits(GPIOB, GPIO_Pin_10); 
//	GPIO_ResetBits(GPIOB, GPIO_Pin_11); 
	
	//LED灭
	GPIO_SetBits(GPIOB, GPIO_Pin_10);
	GPIO_SetBits(GPIOB, GPIO_Pin_11);
}


//蜂鸣器输出高电平响
void Beep_Init(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// 1. 开启GPIOB时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// 2. 配置蜂鸣器引脚
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;  // 推挽输出
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;        // 引脚定义
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; // 输出速率
	
	// 3. 引脚初始化
    GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	// 4. 蜂鸣器空闲状态 输出高电平 蜂鸣器响
//  GPIO_SetBits(GPIOB, GPIO_Pin_2);
	
	// 蜂鸣器不响
	GPIO_ResetBits(GPIOB, GPIO_Pin_2);
}
