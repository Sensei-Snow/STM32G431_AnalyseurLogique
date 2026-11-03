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
	//-- Initializations -----------------------------------
	HAL_Init();
	BSP_GPIO_enable();

	return 0;
}
