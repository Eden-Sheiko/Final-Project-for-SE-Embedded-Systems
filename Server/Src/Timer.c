#include "../Inc/Timer.h"

volatile uint8_t timer_callback_success = FALSE; // interrupt flag timer
volatile uint8_t second = ZERO; // seconds
volatile uint8_t minute = ZERO; // minutes

uint8_t TIMER_main() {
	printf("Program start\r\n");
	HAL_TIM_Base_Start_IT(TIM_3);
	while (TRUE) {
		if (timer_callback_success) {
			printf("minute = %d  second = %d\n\r", minute, second);
			if(second == TIME){
				return TRUE;
			}
			timer_callback_success = FALSE;
		}
	}
}

// == Timer Callback ======================================
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timer_callback_success = TRUE;

	++second;
	if (second >= SEC_TO_MIN) {
		second = ZERO;
		++minute;
	}
}
