/**
 *******************************************************************************
 * @file 				internal_led.c
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			18/11/2026
 * @see					internal_led.h
 * @brief				Implémentation des fonctionnalités liées à la LED interne de la carte Nucléo.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

#include "stm32g4xx_hal.h"
#include "stm32g4_gpio.h"
#include "stm32g4_sys.h"
#include "internal_led.h"
#include "../../utils/logs/logs.h"

/* **************************************************** Private macros *************************************************** */
#define INTERNAL_LED_PIN		GPIO_PIN_8
#define INTERNAL_LED_GPIO		GPIOB
#define MODULE_NAME				"INTERNAL_LED"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
void INTERNAL_LED_init(void)
{
	LOGS_info(MODULE_NAME, "Setting GPIO configuration");
	BSP_GPIO_pin_config(INTERNAL_LED_GPIO, INTERNAL_LED_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH,GPIO_NO_AF);
}

void INTERNAL_LED_set(bool state)
{
	if(state == true)
	{
		LOGS_info(MODULE_NAME, "Power on");
		HAL_GPIO_WritePin(INTERNAL_LED_GPIO, INTERNAL_LED_PIN, 1);
	}
	else
	{
		LOGS_info(MODULE_NAME, "Power off");
		HAL_GPIO_WritePin(INTERNAL_LED_GPIO, INTERNAL_LED_PIN, 0);
	}
}

void INTERNAL_LED_blink(uint32_t nb_loop, uint32_t delay_ms)
{
	if(nb_loop == 0)
	{
		LOGS_info(MODULE_NAME, "Blinking to infinity");
		while(true) {
			HAL_GPIO_WritePin(INTERNAL_LED_GPIO, INTERNAL_LED_PIN, 1);
			HAL_Delay(delay_ms);
			HAL_GPIO_WritePin(INTERNAL_LED_GPIO, INTERNAL_LED_PIN, 0);
			HAL_Delay(delay_ms);
		}
	}
	else
	{
		char buffer_logtext[100];
		snprintf(buffer_logtext, sizeof(buffer_logtext), "Blinking for %lu times", (unsigned long)nb_loop);
		LOGS_info(MODULE_NAME, buffer_logtext);
		for(int i = 0; i < nb_loop; i++) {
			HAL_GPIO_WritePin(INTERNAL_LED_GPIO, INTERNAL_LED_PIN, 1);
			HAL_Delay(delay_ms);
			HAL_GPIO_WritePin(INTERNAL_LED_GPIO, INTERNAL_LED_PIN, 0);
			HAL_Delay(delay_ms);
		}
	}
}
