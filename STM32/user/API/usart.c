#include "main.h"
/*
PA9-USART1-TX
PA10--USART1-RX
*/
void Usart_Config(u32 brr)
{
	float DIV=0;
	u16 DIV_m;//表示整数
	u16 DIV_f=0;//表示小数
	RCC->APB2ENR|=1<<2|1<<14;//打开A端口和串口1时钟
	GPIOA->CRH&=~(0xff<<4);
	GPIOA->CRH|=0x4b<<4;//复用为串口
	
	USART1->CR1=0;//字长，禁止奇偶校验
	USART1->CR2=0;//停止位为1位
	USART1->CR1|=0x3<<2;//发送器和接收器使能
	//串口波特率
	DIV=72000000/(16.0*brr);
	DIV_m=(u16)DIV;
	DIV_f=(DIV-DIV_m)*16+0.5;
	USART1->BRR=DIV_m<<4|DIV_f;
	
	USART1->CR1|=1<<13;//串口使能
}
//改变printf的打印方向
int fputc(int c,FILE* fp)
{
	while((USART1->SR&1<<6)==0);
	USART1->DR=c;
	return c;
}
