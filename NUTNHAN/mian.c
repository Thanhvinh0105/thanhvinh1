#include<STM32F10x.h>
#include<stm32F10x_rcc.h>
#include<stm32f10x_gpio.h>

void rcc (void);
void led (void);
void delay_ms (uint16_t x);
void nutnhan (void);

int main(){
	rcc();
	led();
	nutnhan();

	while(1){
if(! GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_11)){
	GPIO_ResetBits(GPIOC, GPIO_Pin_0);
   delay_ms(1000);
		}
else { GPIO_SetBits(GPIOC, GPIO_Pin_13);
	   delay_ms(1000);
		}
	}}
void rcc (void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	}
void nutnhan(void){
	GPIO_InitTypeDef nt;
	nt.GPIO_Mode = GPIO_Mode_IPU;
	nt.GPIO_Pin = GPIO_Pin_11;
	nt.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&nt);
	}
void led (void){
	GPIO_InitTypeDef led13;
	led13.GPIO_Mode = GPIO_Mode_Out_PP;
	led13.GPIO_Pin = GPIO_Pin_13;
	led13.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &led13);
	}
void delay_ms(uint16_t x ){
	uint16_t s,d;
	for(s=0; s< x; s++){
		for(d=0; d < 0xAFF; d++);
	}
}
