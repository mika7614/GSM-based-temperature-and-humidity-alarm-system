#include "main.h"
/*
PA9-USART1-TX
PA10--USART1-RX
*/
void Usart_Config(u32 brr)
{
	float DIV=0;
	u16 DIV_m;//��ʾ����
	u16 DIV_f=0;//��ʾС��
	RCC->APB2ENR|=1<<2|1<<14;//��A�˿ںʹ���1ʱ��
	GPIOA->CRH&=~(0xff<<4);
	GPIOA->CRH|=0x4b<<4;//����Ϊ����
	
	USART1->CR1=0;//�ֳ�����ֹ��żУ��
	USART1->CR2=0;//ֹͣλΪ1λ
	USART1->CR1|=0x3<<2;//�������ͽ�����ʹ��
	//���ڲ�����
	DIV=72000000/(16.0*brr);
	DIV_m=(u16)DIV;
	DIV_f=(DIV-DIV_m)*16+0.5;
	USART1->BRR=DIV_m<<4|DIV_f;
	
	USART1->CR1|=1<<13;//����ʹ��
}
//�ı�printf�Ĵ�ӡ����
int fputc(int c,FILE* fp)
{
	while((USART1->SR&1<<6)==0);
	USART1->DR=c;
	return c;
}
