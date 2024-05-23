#include "main.h"
//配置按键
void Key_Config(void)
{
	RCC->APB2ENR|=1<<2;//打开A端口时钟
	GPIOA->CRL&=~(0xf<<0);
	GPIOA->CRL|=1<<2;//浮空输入
}
u8 Key_Value(void)
{
		static u16 count=0;
	//按键按下
		if((GPIOA->IDR&1<<0)==0)
		{
			count++;
		}
		else		//按键松开
		{
				//短按
				if(count>2&&count<50)
				{
					count=0;
					return 1;//表示按键按下
				}
				else if(count>200)	//长按
				{
					count=0;
					return 2;
				}
				count=0;
		}
	return 0;
}
