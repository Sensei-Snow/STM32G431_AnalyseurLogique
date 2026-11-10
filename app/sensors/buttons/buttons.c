/**
 *******************************************************************************
 * @file 				buttons.c
 * @author 				Arthur Retaillaud
 * @creation_date 		04/11/2026
 * @update_date			04/11/2026
 * @see					buttons.h
 * @brief				Implémentation des fonctionnalités liées aux boutons poussoirs.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdbool.h>

#include "stm32g4xx_hal.h"
#include "stm32g4_systick.h"
#include "stm32g4_gpio.h"
#include "buttons.h"

/* **************************************************** Private macros *************************************************** */
#define GPIO_BUTTON_STARTSTOP GPIOB
#define PIN_BUTTON_STARTSTOP GPIO_PIN_0

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
void BUTTONS_init(void)
{
	BSP_GPIO_pin_config(GPIO_BUTTON_STARTSTOP, PIN_BUTTON_STARTSTOP, GPIO_MODE_INPUT, GPIO_PULLUP, GPIO_SPEED_FREQ_HIGH, GPIO_NO_AF);
	BSP_systick_add_callback_function(&BUTTONS_process_ms);
}

bool BUTTON_startstop_read(void)
{
	return !HAL_GPIO_ReadPin(GPIO_BUTTON_STARTSTOP, PIN_BUTTON_STARTSTOP);
}

void BUTTONS_update(button_e * button_startstop_event)
{
	static bool previous_button_startstop = false;

	*button_startstop_event = BUTTON_NO_EVENT;

	if(!t)
	{
		t = 10;
		bool current_button_startstop = 	!HAL_GPIO_ReadPin(GPIO_BUTTON_STARTSTOP, 	PIN_BUTTON_STARTSTOP);

		if (current_button_startstop != previous_button_startstop) {
			*button_startstop_event = current_button_startstop ? BUTTON_PRESS_EVENT : BUTTON_RELEASE_EVENT;
			previous_button_startstop = current_button_startstop;
		}
	}
}
