#include "main.h"
//PB5通用推挽输出
void LED_Config(void)
{
	RCC->APB2ENR|=3<<2|1<<6;//打开B端口时钟
	GPIOB->CRL|=0x3<<20;//输出模式50MHz
	GPIOB->CRL&=~(0x3<<22);//推挽模式
	
	GPIOE->CRL|=0x3<<20;//输出模式50MHz
	GPIOE->CRL&=~(0x3<<22);
	
	GPIOA->CRL|=0x33<<20;//输出模式50MHz
	GPIOA->CRL&=~(0x33<<22);

}
//实现任意us
void delay_nus(uint32_t nus)
{
	while(nus--)
		delay_1us();
}
