#include "stm32f10x.h"             
#include "stm32f10x_gpio.h"       
#include "stm32f10x_rcc.h"        


void delay_ms(uint16_t x);
void taoxung(void);
void led( void);
int main(){
	while(1){
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
	delay_ms(500);
	GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	delay_ms (500);}
}
void delay_ms(uint16_t x ){
	uint16_t s,d;
	for(s=0; s< x; s++){
		for(d=0; d < 0xAFF; d++);
	}
}
void taoxung(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
}
void led(void){
	GPIO_InitTypeDef led;
	led.GPIO_Pin = GPIO_Pin_13;
	led.GPIO_Mode = GPIO_Mode_Out_PP;
	led.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&led);
}

