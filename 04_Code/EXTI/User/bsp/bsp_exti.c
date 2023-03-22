#include "head.h"

//中断服务函数
void EXTI15_10_IRQHandler(void)
{
    if (EXTI_GetFlagStatus(EXTI_Line12) != RESET) // 判断是否为exti-12中断
    {
        // 按键动作
        LED4_SET(0);
    }
    EXTI_ClearFlag(EXTI_Line12); // 手动清除中断标志
	
	if (EXTI_GetFlagStatus(EXTI_Line13) != RESET) // 判断是否为exti-13中断
    {
        // 按键动作
        LED4_SET(1);
    }
    EXTI_ClearFlag(EXTI_Line13);// 手动清除中断标志
	
	if (EXTI_GetFlagStatus(EXTI_Line14) != RESET) // 判断是否为exti-14中断
    {
        // 按键动作
        LED5_SET(0);
    }
    EXTI_ClearFlag(EXTI_Line14);// 手动清除中断标志
	
	if (EXTI_GetFlagStatus(EXTI_Line15) != RESET) // 判断是否为exti-15中断
    {
        // 按键动作
        LED5_SET(1);
    }
    EXTI_ClearFlag(EXTI_Line15);// 手动清除中断标志
	
}


void bsp_exti_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    EXTI_InitTypeDef EXTI_InitStruct = {0};
    NVIC_InitTypeDef NVIC_InitStruct = {0};

    // 需要打开AFIO & GPIOB时钟。
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
    // GPIO配置
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU; // 上拉输入模式
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    // GPIO初始化
    GPIO_Init(GPIOB, &GPIO_InitStruct);
	
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12); // 绑定中断线
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource13);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource15);

    // EXTI配置
    EXTI_InitStruct.EXTI_Line = EXTI_Line12 | EXTI_Line13 | EXTI_Line14 | EXTI_Line15;             // key1,key2,key3,key4中断线
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;               // 使能外部中断
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;     // 中断异常
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling; // 下降沿触发
    EXTI_Init(&EXTI_InitStruct);

    // NVIC配置
    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;      // KEY1中断通道
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;           // 使能通道
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3; // 抢占优先级
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;        // 子优先级
    NVIC_Init(&NVIC_InitStruct);                           // 配置NVIC中断控制器
	
}
