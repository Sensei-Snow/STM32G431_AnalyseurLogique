/**
 *******************************************************************************
 * @file 				buttons.c
 * @author 				Arthur Retaillaud
 * @creation_date 		04/11/2026
 * @update_date			15/11/2026
 * @see					buttons.h
 * @brief				Implémentation des fonctionnalités liées aux boutons poussoirs.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdbool.h>
#include <stdio.h>

#include "stm32g4xx_hal.h"
#include "stm32g4_gpio.h"
#include "stm32g4_systick.h"
#include "buttons.h"
#include "../../utils/utils.h"
#include "../../utils/logs/logs.h"

/* **************************************************** Private macros *************************************************** */
#define GPIO_BUTTON_STARTSTOP		GPIOB
#define PIN_BUTTON_STARTSTOP		GPIO_PIN_0
#define MODULE_NAME					"BUTTONS"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */
void BUTTONS_process_ms(void);

/* ************************************************** Private variables ************************************************** */
static volatile uint32_t t = 0;

/* ********************************************** Private functions definitions ****************************************** */
void BUTTONS_process_ms(void)
{
	if(t)
		t--;
}

/* ********************************************** Public functions definitions ******************************************* */
Execution_State BUTTONS_init(void)
{
	LOGS_info(MODULE_NAME, "Setting GPIO configuration");
	BSP_GPIO_pin_config(GPIO_BUTTON_STARTSTOP, PIN_BUTTON_STARTSTOP, GPIO_MODE_INPUT, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);

	LOGS_info(MODULE_NAME, "Adding callback function");
	if (BSP_systick_add_callback_function(&BUTTONS_process_ms))
	{
		LOGS_info(MODULE_NAME, "Found place for callback function");
		return STATE_OK;
	}
	else
	{
		LOGS_warning(MODULE_NAME, "No place found for callback function");
		return STATE_WARNING;
	}
}

bool BUTTON_startstop_read(void)
{
	LOGS_info(MODULE_NAME, "Reading state of start/stop button");
	bool state = !HAL_GPIO_ReadPin(GPIO_BUTTON_STARTSTOP, PIN_BUTTON_STARTSTOP);

	char buffer_logtext_read[32];
	snprintf(buffer_logtext_read, sizeof(buffer_logtext_read), "State read is : %u", (unsigned int)state);
	LOGS_info(MODULE_NAME, buffer_logtext_read);

	return state;
}

void BUTTONS_update(button_e *button_startstop_event)
{
	LOGS_info(MODULE_NAME, "Setting blank event for start/stop button");
	static bool previous_button_startstop = false;

	*button_startstop_event = BUTTON_NO_EVENT;

	if(!t)
	{
		t = 10;
		bool current_button_startstop = !HAL_GPIO_ReadPin(GPIO_BUTTON_STARTSTOP, PIN_BUTTON_STARTSTOP);

		if (current_button_startstop != previous_button_startstop)
		{
			LOGS_info(MODULE_NAME, "Detecting different event for start/stop button");

			if (current_button_startstop)
			{
			    *button_startstop_event = BUTTON_PRESS_EVENT;
			    LOGS_info(MODULE_NAME, "Updating event to BUTTON_PRESS_EVENT");
			}
			else
			{
			    *button_startstop_event = BUTTON_RELEASE_EVENT;
			    LOGS_info(MODULE_NAME, "Updating event to BUTTON_RELEASE_EVENT");
			}

			previous_button_startstop = current_button_startstop;
		}
	}
}
