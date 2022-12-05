#include "../Inc/Adc.h"

volatile double AD_RES = FALSE;

uint8_t ADC_test() {
	HAL_ADC_Start(ADC_1);
	AD_RES = HAL_ADC_GetValue(ADC_1);
	while (TRUE) {
		if (AD_RES < TOP_LIMIT && AD_RES > BOTTOM_LIMIT) {
			printf("True\r\n");
			printf("ADC value = %ld \r\n", HAL_ADC_GetValue(ADC_1));
			return TRUE;
		}
		printf("ADC value = %ld \r\n", HAL_ADC_GetValue(ADC_1));
		printf("False\r\n");
		return FAIL;
	}

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {

	AD_RES = HAL_ADC_GetValue(ADC_1);
}

