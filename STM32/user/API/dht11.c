#include "main.h"
//DHT11配置
//Mode=1,输出模式，Mode=0,输入模式
void DHT11_Mode(u8 mode)
{
	RCC->APB2ENR|=1<<2;//打开A端口时钟
	GPIOA->CRL&=~(0xf<<12);
	if(mode)
	{
		GPIOA->CRL|=0x3<<12;//输出
		GPIOA->ODR|=1<<3;
	}
	else
	{
		GPIOA->CRL|=1<<15;//上拉输入
		GPIOA->ODR|=1<<3;
	}
}
void DHT11_Value(u8 *Tem,u8 *RH)
{
	u8 i=0,j=0,str[5]={0};
	DHT11_Mode(1);//输出模式
	DHT11_State(0);//拉低
	delay_nms(20);
	DHT11_State(1);//拉高
	delay_nus(30);
	DHT11_Mode(0);//输入模式
	while(DHT11_SR());//等待拉低
	while(DHT11_SR()==0);//等待拉高
	for(i=0;i<5;i++)
	{
		for(j=0;j<8;j++)
		{
			while(DHT11_SR());//等待拉低
			while(DHT11_SR()==0);//等待拉高
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
