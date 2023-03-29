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

int main()
{
	uint32_t count = 0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 中断分组
	//1.硬件初始化
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


