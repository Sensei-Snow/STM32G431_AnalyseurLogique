/**
 *******************************************************************************
 * @file 				main.c
 * @author 				Arthur Retaillaud
 * @creation_date 		18/10/2026
 * @update_date			26/10/2026
 * @brief				Fichier principal de code de notre projet sur carte Nucléo STM32G431KB.
 *******************************************************************************
*/

#include "config.h"
#include "stm32g4_gpio.h"

int main(void)
{
	uint8_t u8_a = 0;
	uint8_t u8_b = 0;
	uint8_t u8_c = 0;

	//-- Initializations -----------------------------------
	HAL_Init();
	BSP_GPIO_enable();
	BSP_GPIO_pin_config(GPIOB, GPIO_PIN_8, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH,GPIO_NO_AF);

	//-- Addition ------------------------------------------

	u8_a = 10;
	u8_b = 20;

	u8_c = u8_a + u8_b;

	//-- Led enable / disable ------------------------------

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 1);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, 0);


	return ((int) u8_c);
}
