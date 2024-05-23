#include "main.h"
extern vu32 DHT11_time;
void call(void)
{
	while(1)
	{
		printf("AT\r\n");
		delay_nms(500);
		printf("ATD132xxxxxxx;\r\n");
		delay_nms(500);
	}
}
void send_message(void)
{
	printf("AT+CSCS=\"GSM\"\r\n");
	delay_nms(500);
	printf("AT+CMGF=1\r\n");
	delay_nms(500);	
	printf("AT+CMGS=\"132xxxxxxxx\"\r\n");
	delay_nms(500);
	printf("Temperature Warning!\x1a\r\n");
	delay_nms(500);
}
extern vu32 DHT_time;
int main()
{
	u8 Tem=0,RH=0,flag=0;
	u16 time=0;
	char str[30]={0};
	LED_Config();//LED初始化
	Key_Config();//按键初始化
	Usart_Config(9600);//串口初始化
	SysTick_Config(72000);
	//call();
	send_message();
	while(1)
	{		
		if(DHT_time>200)
		{
			DHT_time=0;
			DHT11_Value(&Tem,&RH);
			if(Tem>35||RH<15)
			{
				
			}
		}
		switch(flag)
		{
			case 0:break;
			case 1:sprintf(str,);      break;
		}
	}
}

