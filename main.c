
#include "main.h"              

uint32_t msTick;

void pwm_test2(){

	RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOB , ENABLE );
	RCC_AHB1PeriphClockCmd ( RCC_AHB1Periph_GPIOD , ENABLE );
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_TIM10 , ENABLE );

	GPIO_InitTypeDef gp;
	gp.GPIO_Mode = GPIO_Mode_AF ;
	gp.GPIO_OType = GPIO_OType_PP ;
	gp.GPIO_PuPd = GPIO_PuPd_UP ;
	gp.GPIO_Pin = GPIO_Pin_8 ;
	gp.GPIO_Speed = GPIO_Speed_100MHz ;
	GPIO_Init ( GPIOB , &gp );
	GPIO_PinAFConfig ( GPIOB , GPIO_PinSource8 , GPIO_AF_TIM10 );


	TIM_TimeBaseInitTypeDef timb;
	TIM_OCInitTypeDef timoc;

	timb.TIM_ClockDivision = 0;
	timb.TIM_CounterMode = TIM_CounterMode_Up ;
	timb.TIM_Period = 249;
	timb.TIM_Prescaler = 524 ;
	TIM_TimeBaseInit ( TIM10 , &timb );

	timoc.TIM_OCMode = TIM_OCMode_PWM1 ;
	timoc.TIM_OCNPolarity = TIM_OCPolarity_High ;
	timoc.TIM_OutputState = ENABLE ;
	timoc.TIM_Pulse = 50;
	TIM_OC1Init ( TIM10 , & timoc );

	TIM_OC1PreloadConfig ( TIM10, TIM_OCPreload_Enable );
	TIM_ARRPreloadConfig ( TIM10 , ENABLE );

	TIM_Cmd ( TIM10 , ENABLE );
}
void delay(int ms );
int flag = 1;

int main () {

	SysTick_Config( SystemCoreClock / 1000 );
	SystemCoreClockUpdate();
	pwm_test2();

	while ( 1 ) {

		delay( 50);
		if ( flag == 1 ) {
			TIM10->ARR -=1 ;
		} 
		else if ( flag == 0 ) {
			TIM10->ARR+= 1;
		}

		if ( TIM10->ARR == 32 | TIM10->ARR == 250) {
			flag ^= 0x01;
		}
	}
}

void delay(int ms ){
	
	uint32_t crr= msTick;
	
	while( msTick - crr < ms ){
	__nop();
	}

}
void SysTick_Handler(){


msTick++;

}
