/**
 *******************************************************************************
 * @file 				program.c
 * @author 				Arthur Retaillaud
 * @creation_date 		15/11/2026
 * @update_date			22/11/2026
 * @see					program.h
 * @brief				Implémentation des fonctionnalités liées au programme principal.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdio.h>

#include "tft_ili9341/stm32g4_ili9341.h"
#include "tft_ili9341/stm32g4_xpt2046.h"
#include "program.h"
#include "../utils/state_machine/state_machine.h"
#include "../utils/logs/logs.h"
#include "../utils/utils.h"
#include "../display/display.h"
#include "../display/screens/start_screen/start_screen.h"
#include "../display/screens/home_screen/home_screen.h"
#include "../display/screens/infos_screen/infos_screen.h"
#include "../display/screens/settings_screen/settings_screen.h"
#include "../sensors/buttons/buttons.h"
#include "../actuators/internal_led/internal_led.h"

/* ******************************************************* Includes ****************************************************** */
#define MODULE_NAME		"PROGRAM"

/* **************************************************** Private macros *************************************************** */

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
Execution_State Program_Init(Program_t *program, uint32_t now_ms)
{
    if (program == NULL)
    {
    	LOGS_error(MODULE_NAME, "Program's structure nonexistent");
    	return EXECUTION_ERROR;
    }

    LOGS_info(MODULE_NAME, "Initialization of program's state machine");
    if (SM_Init(&program->program_sm, STATE_INIT, now_ms) == EXECUTION_OK)
    {
    	LOGS_info(MODULE_NAME, "Program's state machine initialized");
        return EXECUTION_OK;
    }
    else
    {
    	LOGS_error(MODULE_NAME, "State machine not initialized");
        return EXECUTION_ERROR;
    }
}


Execution_State Program_Update(Program_t *program, uint32_t now_ms)
{
    if (program == NULL)
    {
    	LOGS_error(MODULE_NAME, "Program's structure nonexistent");
    	return EXECUTION_ERROR;
    }

    bool entered = SM_ConsumeStateChange(&program->program_sm);

    Execution_State State_Buttons;
    int16_t x, y;

    switch (SM_GetState(&program->program_sm))
    {
        case STATE_INIT:
            if (entered)
            {
                LOGS_info(MODULE_NAME, "First loop in STATE_INIT");

                INTERNAL_LED_set(false);

                DISPLAY_init();
                XPT2046_init();
                State_Buttons = BUTTONS_init();
            }

            if (State_Buttons == EXECUTION_OK)
            {
            	SM_SetState(&program->program_sm, STATE_STARTSCREEN, now_ms);
            	INTERNAL_LED_set(true);
            }
            else
            {
            	SM_SetState(&program->program_sm, STATE_WARNING, now_ms);
            	INTERNAL_LED_set(true);
            }

            break;

        case STATE_STARTSCREEN:
            if (entered)
            {
            	LOGS_info(MODULE_NAME, "First loop in STATE_STARTSCREEN");

            	INTERNAL_LED_set(false);

            	draw_start_screen();

            	// Rouge
            	//ILI9341_DrawFilledRectangle(0, 0, 50, 50, 0xF800);
            	// Vert
            	//ILI9341_DrawFilledRectangle(50, 0, 100, 50, 0x07E0);
            	// Bleu
            	//ILI9341_DrawFilledRectangle(100, 0, 150, 50, 0x001F);
            }

            if (SM_HasTimedOut(&program->program_sm, 5000, now_ms))
            {
            	SM_SetState(&program->program_sm, STATE_HOMESCREEN_INITIAL, now_ms);
            	INTERNAL_LED_set(true);
            }

            break;

        case STATE_HOMESCREEN_INITIAL:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_HOMESCREEN_INITIAL");

				INTERNAL_LED_set(false);

				draw_home_screen_initial();
			}

			if (XPT2046_getCoordinates(&x, &y, XPT2046_COORDINATE_RAW))
			{
				if (x > 3375 && x < 3500 && y > 3500 && y < 3800)
				{
					SM_SetState(&program->program_sm, STATE_HOMESCREEN_MENU, now_ms);
					INTERNAL_LED_set(true);
				}
			}

			break;

        case STATE_HOMESCREEN_MENU:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_HOMESCREEN_MENU");

				INTERNAL_LED_set(false);

				draw_home_screen_menu();
			}

			if (XPT2046_getCoordinates(&x, &y, XPT2046_COORDINATE_RAW))
			{
				if (x > 3375 && x < 3500 && y > 3500 && y < 3800)
				{
					SM_SetState(&program->program_sm, STATE_HOMESCREEN_INITIAL, now_ms);
					INTERNAL_LED_set(true);
				}
				else if (x > 2800 && x < 3100 && y > 2200 && y < 3500)
				{
					SM_SetState(&program->program_sm, STATE_SETTINGSSCREEN_PAGE1, now_ms);
					INTERNAL_LED_set(true);
				}
				else if (x > 2300 && x < 2600 && y > 2200 && y < 3500)
				{
					SM_SetState(&program->program_sm, STATE_INFOSCREEN, now_ms);
					INTERNAL_LED_set(true);
				}
			}

			break;

        case STATE_INFOSCREEN:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_INFOSCREEN");

				INTERNAL_LED_set(false);

				draw_infos_screen();
			}

			if (XPT2046_getCoordinates(&x, &y, XPT2046_COORDINATE_RAW))
			{
				if (x > 3375 && x < 3500 && y > 3500 && y < 3800)
				{
					SM_SetState(&program->program_sm, STATE_HOMESCREEN_INITIAL, now_ms);
					INTERNAL_LED_set(true);
				}
			}

			break;

        case STATE_SETTINGSSCREEN_PAGE1:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_SETTINGSSCREEN_PAGE1");

				INTERNAL_LED_set(false);

				draw_settings_screen_page1();
			}

			if (XPT2046_getCoordinates(&x, &y, XPT2046_COORDINATE_RAW))
			{
				if (x > 3375 && x < 3500 && y > 3500 && y < 3800)
				{
					SM_SetState(&program->program_sm, STATE_HOMESCREEN_INITIAL, now_ms);
					INTERNAL_LED_set(true);
				}
			}

			break;

        case STATE_DONE:
            if (entered)
            {
            	LOGS_info(MODULE_NAME, "First loop in STATE_DONE");

            	INTERNAL_LED_blink(0, 300);
            }

            // Attente d'une éventuelle réinitialisation

            break;

        case STATE_WARNING:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_WARNING");

				INTERNAL_LED_blink(0, 300);
			}

			// Attente d'une éventuelle réinitialisation

			break;

        case STATE_ERROR:
            if (entered)
            {
            	LOGS_info(MODULE_NAME, "First loop in STATE_ERROR");

            	INTERNAL_LED_blink(0, 300);
            }

            // Attente d'une éventuelle réinitialisation

            break;

        default:
            SM_SetState(&program->program_sm, STATE_ERROR, now_ms);

            break;

        return EXECUTION_OK;
    }
}
