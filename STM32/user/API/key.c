#include "main.h"
//���ð���
void Key_Config(void)
{
	RCC->APB2ENR|=1<<2;//��A�˿�ʱ��
	GPIOA->CRL&=~(0xf<<0);
	GPIOA->CRL|=1<<2;//��������
}
u8 Key_Value(void)
{
		static u16 count=0;
	//��������
		if((GPIOA->IDR&1<<0)==0)
		{
			count++;
		}
		else		//�����ɿ�
		{
				//�̰�
				if(count>2&&count<50)
				{
					count=0;
					return 1;//��ʾ��������
				}
				else if(count>200)	//����
				{
					count=0;
					return 2;
				}
				count=0;
		}
	return 0;
}
