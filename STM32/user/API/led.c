#include "main.h"
//PB5ͨ���������
void LED_Config(void)
{
	RCC->APB2ENR|=3<<2|1<<6;//��B�˿�ʱ��
	GPIOB->CRL|=0x3<<20;//���ģʽ50MHz
	GPIOB->CRL&=~(0x3<<22);//����ģʽ
	
	GPIOE->CRL|=0x3<<20;//���ģʽ50MHz
	GPIOE->CRL&=~(0x3<<22);
	
	GPIOA->CRL|=0x33<<20;//���ģʽ50MHz
	GPIOA->CRL&=~(0x33<<22);

}
//ʵ������us
void delay_nus(uint32_t nus)
{
	while(nus--)
		delay_1us();
}
