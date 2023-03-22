#include "head.h"

//�жϷ�����
void EXTI15_10_IRQHandler(void)
{
    if (EXTI_GetFlagStatus(EXTI_Line12) != RESET) // �ж��Ƿ�Ϊexti-12�ж�
    {
        // ��������
        LED4_SET(0);
    }
    EXTI_ClearFlag(EXTI_Line12); // �ֶ�����жϱ�־
	
	if (EXTI_GetFlagStatus(EXTI_Line13) != RESET) // �ж��Ƿ�Ϊexti-13�ж�
    {
        // ��������
        LED4_SET(1);
    }
    EXTI_ClearFlag(EXTI_Line13);// �ֶ�����жϱ�־
	
	if (EXTI_GetFlagStatus(EXTI_Line14) != RESET) // �ж��Ƿ�Ϊexti-14�ж�
    {
        // ��������
        LED5_SET(0);
    }
    EXTI_ClearFlag(EXTI_Line14);// �ֶ�����жϱ�־
	
	if (EXTI_GetFlagStatus(EXTI_Line15) != RESET) // �ж��Ƿ�Ϊexti-15�ж�
    {
        // ��������
        LED5_SET(1);
    }
    EXTI_ClearFlag(EXTI_Line15);// �ֶ�����жϱ�־
	
}


void bsp_exti_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    EXTI_InitTypeDef EXTI_InitStruct = {0};
    NVIC_InitTypeDef NVIC_InitStruct = {0};

    // ��Ҫ��AFIO & GPIOBʱ�ӡ�
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
    // GPIO����
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU; // ��������ģʽ
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
    // GPIO��ʼ��
    GPIO_Init(GPIOB, &GPIO_InitStruct);
	
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource12); // ���ж���
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource13);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource15);

    // EXTI����
    EXTI_InitStruct.EXTI_Line = EXTI_Line12 | EXTI_Line13 | EXTI_Line14 | EXTI_Line15;             // key1,key2,key3,key4�ж���
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;               // ʹ���ⲿ�ж�
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;     // �ж��쳣
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling; // �½��ش���
    EXTI_Init(&EXTI_InitStruct);

    // NVIC����
    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;      // KEY1�ж�ͨ��
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;           // ʹ��ͨ��
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3; // ��ռ���ȼ�
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;        // �����ȼ�
    NVIC_Init(&NVIC_InitStruct);                           // ����NVIC�жϿ�����
	
}
