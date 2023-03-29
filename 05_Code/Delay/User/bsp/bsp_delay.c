#include "head.h"
/**
 * @description: 裸机延时
 * @return {*}
 * @param {uint32_t} ms
 */
void bsp_delay_ms(uint32_t ms)
{
    uint32_t i = 0;
    
    SysTick_Config(72000);  // 设置重装载寄存器的值, 1ms 计算72000
	
    for (i = 0; i < ms; i++) 
    {
        // 当计数器的值减小到 0 的时候， CRTL 寄存器的位 16 会置 1
        while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));      // CRTL 寄存器的位 16,硬件会自己清0
    }
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;  // 停止计时
}

/**
 * @description: 裸机延时
 * @return {*}
 * @param {uint32_t} us
 */
void bsp_delay_us(uint32_t us)
{
	uint32_t i = 0;
    
    SysTick_Config(72);  // 设置重装载寄存器的值, 1us 计算72000
	
    for (i = 0; i < us; i++) 
    {
        // 当计数器的值减小到 0 的时候， CRTL 寄存器的位 16 会置 1
        while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));      // CRTL 寄存器的位 16,硬件会自己清0
    }
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;  // 停止计时
}

