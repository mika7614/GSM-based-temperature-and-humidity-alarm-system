#include "main.h"
//DHT11����
//Mode=1,���ģʽ��Mode=0,����ģʽ
void DHT11_Mode(u8 mode)
{
	RCC->APB2ENR|=1<<2;//��A�˿�ʱ��
	GPIOA->CRL&=~(0xf<<12);
	if(mode)
	{
		GPIOA->CRL|=0x3<<12;//���
		GPIOA->ODR|=1<<3;
	}
	else
	{
		GPIOA->CRL|=1<<15;//��������
		GPIOA->ODR|=1<<3;
	}
}
void DHT11_Value(u8 *Tem,u8 *RH)
{
	u8 i=0,j=0,str[5]={0};
	DHT11_Mode(1);//���ģʽ
	DHT11_State(0);//����
	delay_nms(20);
	DHT11_State(1);//����
	delay_nus(30);
	DHT11_Mode(0);//����ģʽ
	while(DHT11_SR());//�ȴ�����
	while(DHT11_SR()==0);//�ȴ�����
	for(i=0;i<5;i++)
	{
		for(j=0;j<8;j++)
		{
			while(DHT11_SR());//�ȴ�����
			while(DHT11_SR()==0);//�ȴ�����
			delay_nus(35);
			str[i]|=((DHT11_SR()&1<<3)>>3)<<(7-j);
		}
	}
	if(((str[0]+str[1]+str[2]+str[3])&0xff)==str[4])
	{
		*Tem=str[2];
		*RH=str[0];
	}
}
