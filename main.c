
#include "main.h"              

uint32_t msTick;


void pwm_test1(){

	RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOD , ENABLE );
	RCC_APB1PeriphClockCmd ( RCC_APB1Periph_TIM4 , ENABLE );
	
	 GPIO_InitTypeDef gp;
	 TIM_TimeBaseInitTypeDef timb;
	 TIM_OCInitTypeDef timoc;
	 
	 
	 gp.GPIO_Mode = GPIO_Mode_AF;
	 gp.GPIO_OType = GPIO_OType_PP;
	 gp.GPIO_PuPd = GPIO_PuPd_UP;
	 gp.GPIO_Speed = GPIO_Speed_100MHz;
	 gp.GPIO_Pin = GPIO_Pin_12  | GPIO_Pin_13  | GPIO_Pin_14  | GPIO_Pin_15 ;
	 GPIO_Init ( GPIOD , & gp );
	 
	 GPIO_PinAFConfig ( GPIOD , GPIO_PinSource12 , GPIO_AF_TIM4 );
	 GPIO_PinAFConfig ( GPIOD , GPIO_PinSource13 , GPIO_AF_TIM4 );
	 GPIO_PinAFConfig ( GPIOD , GPIO_PinSource14 , GPIO_AF_TIM4 );
	 GPIO_PinAFConfig ( GPIOD , GPIO_PinSource15 , GPIO_AF_TIM4 );
	 
	 timb.TIM_Prescaler = 254 ;
	 timb.TIM_Period = 249;
	 timb.TIM_CounterMode = TIM_CounterMode_Up;
	 timb.TIM_ClockDivision = 0;
	 TIM_TimeBaseInit(TIM4 , &timb );
	 
	timoc.TIM_OCMode = TIM_OCMode_PWM1 ;
	timoc.TIM_OutputState = TIM_OutputNState_Enable ;
	timoc.TIM_Pulse = 200;
	timoc.TIM_OCPolarity = TIM_OCPolarity_High ;
	
	TIM_OC1Init( TIM4 , &timoc );
	TIM_OC1PreloadConfig(TIM4 , TIM_OCPreload_Enable );	
	
	TIM_OC2Init( TIM4 , &timoc );
	TIM_OC2PreloadConfig(TIM4 , TIM_OCPreload_Enable );	
				
	TIM_OC3Init( TIM4 , &timoc );
	TIM_OC3PreloadConfig(TIM4 , TIM_OCPreload_Enable );	
				
	TIM_OC4Init( TIM4 , &timoc );
	TIM_OC4PreloadConfig(TIM4 , TIM_OCPreload_Enable );	
	TIM_ARRPreloadConfig(TIM4, ENABLE);
	
	TIM_Cmd(TIM4, ENABLE);
}
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
	
//	delay( 20 );
//	TIM10->ARR = 240 ;
//	TIM4->ARR = 240 ;
//delay( 33 );
//	TIM10->ARR = 120 ;
//delay( 33 );
//	TIM10->ARR = 180 ;
//delay( 33 );
//	TIM10->ARR = 60 ;
//delay( 33 );
//	TIM10->ARR = 30 ;
//delay( 20 );
//	TIM10->ARR = 90 ;
//delay( 20 );
//	TIM10->ARR = 190 ;
//	delay( 20 );
//	TIM10->ARR = 100 ;
//delay( 20 );
//	TIM10->ARR = 240 ;
//delay( 20 );
//	TIM10->ARR = 240 ;
//delay( 20 );
//	TIM10->ARR = 70 ;
//delay( 20 );
//	TIM10->ARR = 45 ;
//delay( 20 );
//	TIM10->ARR = 34 ;
//delay( 20 );
//	TIM10->ARR = 56 ;
//delay( 20 );
//	TIM10->ARR = 67 ;
//delay( 20 );
//	TIM10->ARR = 78 ;
//		TIM4->ARR = 30 ;

//delay( 20 );
//	TIM10->ARR = 89 ;
//delay( 20 );
//	TIM10->ARR = 135 ;
//delay( 20 );
//	TIM10->ARR = 23 ;
//delay( 20 );
//	TIM10->ARR = 34 ;
//delay( 20 );
//	TIM10->ARR = 12 ;
//delay( 20 );
//	TIM10->ARR = 45 ;
//delay( 20 );
//	TIM10->ARR = 78 ;
//delay( 20 );
//	TIM10->ARR = 240 ;
//delay( 20 );
//	TIM10->ARR = 90 ;
//delay( 20 );
//	TIM10->ARR = 91 ;
//delay( 20 );
//	TIM10->ARR = 165 ;
//delay( 20 );
//	TIM10->ARR = 113 ;
//delay( 20 );
//	TIM10->ARR = 157 ;
//delay( 20 );
//	TIM10->ARR = 198 ;


	
	

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
