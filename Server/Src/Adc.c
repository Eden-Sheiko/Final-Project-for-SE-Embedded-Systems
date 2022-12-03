#include "../Inc/Adc.h"

/*
 * ADC - PA_0
 * connected to 3v3 GPIO
 * the signal should be between
 * ~3900 to ~4100
 * if yes the function return True
 * ELSE FALSE
 *
 */

volatile double AD_RES = FALSE;

uint8_t ADC_main() {
	HAL_ADC_Start(ADC_1);
	AD_RES = HAL_ADC_GetValue(ADC_1);
	while (TRUE) {
		if (AD_RES < TOP_LIMIT && AD_RES > BOTTOM_LIMIT) {
			printf("True\r\n");
			printf("ADC value = %ld \r\n", HAL_ADC_GetValue(ADC_1));
			return TRUE;
		}
		printf("ADC value = %ld \r\n", HAL_ADC_GetValue(ADC_1));
		return 0xff;
	}

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {

	AD_RES = HAL_ADC_GetValue(ADC_1);
}

