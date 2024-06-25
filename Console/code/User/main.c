#include "debug.h"

#define LED_Pin GPIO_Pin_7
#define LED_GPIO_Port GPIOC
#define PTT_OUT_1 GPIO_Pin_1
#define PTT_OUT_1_Port GPIOA
#define PTT_OUT_2 GPIO_Pin_2
#define PTT_OUT_2_Port GPIOA
#define LED_TX_A GPIO_Pin_5
#define LED_TX_A_Port GPIOC
#define LED_TX_B GPIO_Pin_6
#define LED_TX_B_Port GPIOC
#define LED_RX_A GPIO_Pin_5
#define LED_RX_A_Port GPIOD
#define LED_RX_B GPIO_Pin_6
#define LED_RX_B_Port GPIOD
#define OUT_1 GPIO_Pin_2
#define OUT_1_Port GPIOD
#define OUT_2 GPIO_Pin_3
#define OUT_2_Port GPIOD
#define OUT_3 GPIO_Pin_4
#define OUT_3_Port GPIOD


#define BTN_RX_A GPIO_Pin_0
#define BTN_RX_A_Port GPIOC
#define BTN_RX_B GPIO_Pin_1
#define BTN_RX_B_Port GPIOC
#define BTN_TX_A GPIO_Pin_2
#define BTN_TX_A_Port GPIOC
#define BTN_TX_B GPIO_Pin_3
#define BTN_TX_B_Port GPIOC
#define PTT_IN GPIO_Pin_4
#define PTT_IN_Port GPIOC



vu8 val;


void Timer2_INIT(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef TIMBase_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIMBase_InitStruct.TIM_Period = arr;
    TIMBase_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIMBase_InitStruct.TIM_Prescaler = psc;
    TIMBase_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM2, &TIMBase_InitStruct);

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 5;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
    TIM_Cmd(TIM2, ENABLE);
}

void GPIO_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = LED_Pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_GPIO_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PTT_OUT_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PTT_OUT_1_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PTT_OUT_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PTT_OUT_2_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_TX_A;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_TX_A_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_TX_B;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_TX_B_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_RX_A;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_RX_A_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_RX_B;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_RX_B_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = OUT_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT_1_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = OUT_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT_2_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = OUT_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT_3_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BTN_RX_A;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BTN_RX_A_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BTN_RX_B;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BTN_RX_B_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BTN_TX_A;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BTN_TX_A_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BTN_TX_B;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(BTN_TX_B_Port, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PTT_IN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(PTT_IN_Port, &GPIO_InitStructure);

    GPIO_WriteBit(PTT_OUT_1_Port, PTT_OUT_1, Bit_RESET);
    GPIO_WriteBit(PTT_OUT_2_Port, PTT_OUT_2, Bit_RESET);
    GPIO_WriteBit(LED_RX_A_Port, LED_RX_A, Bit_RESET);
    GPIO_WriteBit(LED_RX_B_Port, LED_RX_B, Bit_RESET);
    GPIO_WriteBit(LED_TX_A_Port, LED_TX_A, Bit_RESET);
    GPIO_WriteBit(LED_TX_B_Port, LED_TX_B, Bit_RESET);
    GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_RESET);
    GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_RESET);
    GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_RESET);

}


void SetLeds()
{
    if (!GPIO_ReadInputDataBit(BTN_RX_A_Port, BTN_RX_A)) GPIO_WriteBit(LED_RX_A_Port, LED_RX_A, Bit_SET);
    else GPIO_WriteBit(LED_RX_A_Port, LED_RX_A, Bit_RESET);
    if (!GPIO_ReadInputDataBit(BTN_RX_B_Port, BTN_RX_B)) GPIO_WriteBit(LED_RX_B_Port, LED_RX_B, Bit_SET);
    else GPIO_WriteBit(LED_RX_B_Port, LED_RX_B, Bit_RESET);
    if (!GPIO_ReadInputDataBit(BTN_TX_A_Port, BTN_TX_A)) GPIO_WriteBit(LED_TX_A_Port, LED_TX_A, Bit_SET);
    else GPIO_WriteBit(LED_TX_A_Port, LED_TX_A, Bit_RESET);
    if (!GPIO_ReadInputDataBit(BTN_TX_B_Port, BTN_TX_B)) GPIO_WriteBit(LED_TX_B_Port, LED_TX_B, Bit_SET);
    else GPIO_WriteBit(LED_TX_B_Port, LED_TX_B, Bit_RESET);
}

void SetOutsRX()
{
    GPIO_WriteBit(PTT_OUT_1_Port, PTT_OUT_1, Bit_RESET);
    GPIO_WriteBit(PTT_OUT_2_Port, PTT_OUT_2, Bit_RESET);
    if ((!GPIO_ReadInputDataBit(BTN_RX_A_Port, BTN_RX_A))&&(!GPIO_ReadInputDataBit(BTN_RX_B_Port, BTN_RX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_SET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_SET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_SET);
        }
    if ((!GPIO_ReadInputDataBit(BTN_RX_A_Port, BTN_RX_A))&&(GPIO_ReadInputDataBit(BTN_RX_B_Port, BTN_RX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_SET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_RESET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_RESET);
        }

    if ((GPIO_ReadInputDataBit(BTN_RX_A_Port, BTN_RX_A))&&(!GPIO_ReadInputDataBit(BTN_RX_B_Port, BTN_RX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_RESET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_SET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_RESET);
        }

    if ((GPIO_ReadInputDataBit(BTN_RX_A_Port, BTN_RX_A))&&(GPIO_ReadInputDataBit(BTN_RX_B_Port, BTN_RX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_RESET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_RESET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_RESET);
        }
}

void SetOutsTX()
{
    if ((!GPIO_ReadInputDataBit(BTN_TX_A_Port, BTN_TX_A))&&(!GPIO_ReadInputDataBit(BTN_TX_B_Port, BTN_TX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_SET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_SET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_SET);
          GPIO_WriteBit(PTT_OUT_1_Port, PTT_OUT_1, Bit_SET);
          GPIO_WriteBit(PTT_OUT_2_Port, PTT_OUT_2, Bit_SET);
        }
    if ((!GPIO_ReadInputDataBit(BTN_TX_A_Port, BTN_TX_A))&&(GPIO_ReadInputDataBit(BTN_TX_B_Port, BTN_TX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_SET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_RESET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_RESET);
          GPIO_WriteBit(PTT_OUT_1_Port, PTT_OUT_1, Bit_SET);
          GPIO_WriteBit(PTT_OUT_2_Port, PTT_OUT_2, Bit_RESET);
        }

    if ((GPIO_ReadInputDataBit(BTN_TX_A_Port, BTN_TX_A))&&(!GPIO_ReadInputDataBit(BTN_TX_B_Port, BTN_TX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_RESET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_SET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_RESET);
          GPIO_WriteBit(PTT_OUT_1_Port, PTT_OUT_1, Bit_RESET);
          GPIO_WriteBit(PTT_OUT_2_Port, PTT_OUT_2, Bit_SET);
        }

    if ((GPIO_ReadInputDataBit(BTN_TX_A_Port, BTN_TX_A))&&(GPIO_ReadInputDataBit(BTN_TX_B_Port, BTN_TX_B)))
        {
          GPIO_WriteBit(OUT_1_Port, OUT_1, Bit_RESET);
          GPIO_WriteBit(OUT_2_Port, OUT_2, Bit_RESET);
          GPIO_WriteBit(OUT_3_Port, OUT_3, Bit_RESET);
          GPIO_WriteBit(PTT_OUT_1_Port, PTT_OUT_1, Bit_RESET);
          GPIO_WriteBit(PTT_OUT_2_Port, PTT_OUT_2, Bit_RESET);
        }
}


int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_INIT();
    Timer2_INIT(999, 23999);

    while(1)
    {
        if (GPIO_ReadInputDataBit(PTT_IN_Port, PTT_IN))
        {
          SetLeds();
          SetOutsRX();
        }
        else
        {
          SetLeds();
          SetOutsTX();
        }

    }
}
