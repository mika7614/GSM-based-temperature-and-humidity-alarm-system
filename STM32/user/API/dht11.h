#ifndef _DHT11_H
#define _DHT11_H
#define DHT11_State(x) x?(GPIOA->ODR|=1<<3):(GPIOA->ODR&=~(1<<3))
#define DHT11_SR()		(GPIOA->IDR&1<<3)	
void DHT11_Value(u8 *Tem,u8 *RH);
#endif
