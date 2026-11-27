/**
 *******************************************************************************
 * @file 				program.c
 * @author 				Arthur Retaillaud
 * @creation_date 		15/11/2026
 * @update_date			27/11/2026
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
void reset_program(Program_t *program);

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */
void reset_program(Program_t *program)
{
	program->channel1 = NO_SIGNAL;
	program->channel2 = NO_SIGNAL;
	program->channel3 = NO_SIGNAL;
	program->channel4 = NO_SIGNAL;

	program->RX_used = false;
	program->TX_used = false;
	program->SDA_used = false;
	program->SCL_used = false;
	program->SCLK_used = false;
	program->MISO_used = false;
	program->MOSI_used = false;
	program->CS_used = false;
}

/* ********************************************** Public functions definitions ******************************************* */
Execution_State Program_Init(Program_t *program, uint32_t now_ms)
{
    if (program == NULL)
    {
    	LOGS_error(MODULE_NAME, "Program's structure nonexistent");
    	return EXECUTION_ERROR;
    }

    program->protocol = NO_PROTOCOL;
    program->channel1 = NO_SIGNAL;
    program->channel2 = NO_SIGNAL;
    program->channel3 = NO_SIGNAL;
    program->channel4 = NO_SIGNAL;

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

    //-- Definition of variables -----------------------------------
    bool entered = SM_ConsumeStateChange(&program->program_sm);

    Execution_State State_Buttons;
    int16_t x, y;

    //-- State machine -----------------------------------
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

				if (program->protocol == NO_PROTOCOL)
					draw_home_screen_initial();
				else if (program->channel1 == NO_SIGNAL && program->channel2 == NO_SIGNAL && program->channel3 == NO_SIGNAL && program->channel4 == NO_SIGNAL)
					draw_home_screen_incomplete_settings();
				else if (program->protocol == UART && (program->RX_used == false || program->TX_used == false))
					draw_home_screen_incomplete_settings();
				else if (program->protocol == I2C && (program->SDA_used == false || program->SCL_used == false))
					draw_home_screen_incomplete_settings();
				else if (program->protocol == SPI && (program->SCLK_used == false || program->MISO_used == false || program->MOSI_used == false || program->CS_used == false))
					draw_home_screen_incomplete_settings();
				else
					draw_home_screen_ok();
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
				else if (x > 2600 && x < 3050 && y > 2250 && y < 3750)
				{
					SM_SetState(&program->program_sm, STATE_SETTINGSSCREEN_PAGE1, now_ms);
					INTERNAL_LED_set(true);
				}
				else if (x > 2000 && x < 2450 && y > 2250 && y < 3750)
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

				if (program->protocol == UART)
					settings_screen_page1_set_uart_visual();
				else if (program->protocol == I2C)
					settings_screen_page1_set_i2c_visual();
				else if (program->protocol == SPI)
					settings_screen_page1_set_spi_visual();
			}

			if (XPT2046_getCoordinates(&x, &y, XPT2046_COORDINATE_RAW))
			{
				if (x > 3375 && x < 3500 && y > 3500 && y < 3800)
				{
					SM_SetState(&program->program_sm, STATE_HOMESCREEN_INITIAL, now_ms);
					INTERNAL_LED_set(true);
				}
				else if (x > 2200 && x < 2600 && y > 1350 && y < 2800)
				{
					program->protocol = UART;

					reset_program(program);

					settings_screen_page1_set_uart_visual();
				}
				else if (x > 1450 && x < 1900 && y > 1350 && y < 2800)
				{
					program->protocol = I2C;

					reset_program(program);

					settings_screen_page1_set_i2c_visual();
				}
				else if (x > 750 && x < 1150 && y > 1350 && y < 2800)
				{
					program->protocol = SPI;

					reset_program(program);

					settings_screen_page1_set_spi_visual();
				}
				else if (x > 1500 && x < 2000 && y > 300 && y < 600)
				{
					if (program->protocol == UART)
					{
						SM_SetState(&program->program_sm, STATE_SETTINGSSCREEN_PAGE2_UART, now_ms);
						INTERNAL_LED_set(true);
					}
					if (program->protocol == I2C)
					{
						SM_SetState(&program->program_sm, STATE_SETTINGSSCREEN_PAGE2_I2C, now_ms);
						INTERNAL_LED_set(true);
					}
					if (program->protocol == SPI)
					{
						SM_SetState(&program->program_sm, STATE_SETTINGSSCREEN_PAGE2_SPI, now_ms);
						INTERNAL_LED_set(true);
					}
				}
			}

			break;

		case STATE_SETTINGSSCREEN_PAGE2_UART:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_SETTINGSSCREEN_PAGE2_UART");

				INTERNAL_LED_set(false);

				draw_settings_screen_page2_uart();

				if (program->channel1 == RX)
					settings_screen_page2_set_rx_visual(1);
				else if (program->channel1 == TX)
					settings_screen_page2_set_tx_visual(1);

				if (program->channel2 == RX)
					settings_screen_page2_set_rx_visual(2);
				else if (program->channel2 == TX)
					settings_screen_page2_set_tx_visual(2);

				if (program->channel3 == RX)
					settings_screen_page2_set_rx_visual(3);
				else if (program->channel3 == TX)
					settings_screen_page2_set_tx_visual(3);

				if (program->channel4 == RX)
					settings_screen_page2_set_rx_visual(4);
				else if (program->channel4 == TX)
					settings_screen_page2_set_tx_visual(4);
			}

			if (XPT2046_getCoordinates(&x, &y, XPT2046_COORDINATE_RAW))
			{
				if (x > 3375 && x < 3500 && y > 3500 && y < 3800)
				{
					SM_SetState(&program->program_sm, STATE_HOMESCREEN_INITIAL, now_ms);
					INTERNAL_LED_set(true);
				}
				else if (x > 2250 && x < 2530 && y > 2100 && y < 2850)
				{
					if(program->channel1 != TX)
					{
						program->channel1 = RX;
						if (program->channel2 == RX)
							program->channel2 = NO_SIGNAL;
						if (program->channel3 == RX)
							program->channel3 = NO_SIGNAL;
						if (program->channel4 == RX)
							program->channel4 = NO_SIGNAL;

						program->RX_used = true;

						settings_screen_page2_set_rx_visual(1);
					}
				}
				else if (x > 2250 && x < 2530 && y > 950 && y < 1650)
				{
					if(program->channel1 != RX)
					{
						program->channel1 = TX;
						if (program->channel2 == TX)
							program->channel2 = NO_SIGNAL;
						if (program->channel3 == TX)
							program->channel3 = NO_SIGNAL;
						if (program->channel4 == TX)
							program->channel4 = NO_SIGNAL;

						program->TX_used = true;	

						settings_screen_page2_set_tx_visual(1);
					}
				}
				else if (x > 1700 && x < 1950 && y > 2100 && y < 2850)
				{
					if(program->channel2 != TX)
					{
						program->channel2 = RX;
						if (program->channel1 == RX)
							program->channel1 = NO_SIGNAL;
						if (program->channel3 == RX)
							program->channel3 = NO_SIGNAL;
						if (program->channel4 == RX)
							program->channel4 = NO_SIGNAL;

						program->RX_used = true;

						settings_screen_page2_set_rx_visual(2);
					}
				}
				else if (x > 1700 && x < 1950 && y > 950 && y < 1650)
				{
					if(program->channel2 != RX)
					{
						program->channel2 = TX;
						if (program->channel1 == TX)
							program->channel1 = NO_SIGNAL;
						if (program->channel3 == TX)
							program->channel3 = NO_SIGNAL;
						if (program->channel4 == TX)
							program->channel4 = NO_SIGNAL;

						program->TX_used = true;	

						settings_screen_page2_set_tx_visual(2);
					}
				}
				else if (x > 1180 && x < 1350 && y > 2100 && y < 2850)
				{
					if(program->channel3 != TX)
					{
						program->channel3 = RX;
						if (program->channel1 == RX)
							program->channel1 = NO_SIGNAL;
						if (program->channel2 == RX)
							program->channel2 = NO_SIGNAL;
						if (program->channel4 == RX)
							program->channel4 = NO_SIGNAL;

						program->RX_used = true;	

						settings_screen_page2_set_rx_visual(3);
					}
				}
				else if (x > 1180 && x < 1350 && y > 950 && y < 1650)
				{
					if(program->channel3 != RX)
					{
						program->channel3 = TX;
						if (program->channel1 == TX)
							program->channel1 = NO_SIGNAL;
						if (program->channel2 == TX)
							program->channel2 = NO_SIGNAL;
						if (program->channel4 == TX)
							program->channel4 = NO_SIGNAL;

						program->TX_used = true;	

						settings_screen_page2_set_tx_visual(3);
					}
				}
				else if (x > 600 && x < 900 && y > 2100 && y < 2850)
				{
					if(program->channel4 != TX)
					{
						program->channel4 = RX;
						if (program->channel1 == RX)
							program->channel1 = NO_SIGNAL;
						if (program->channel2 == RX)
							program->channel2 = NO_SIGNAL;
						if (program->channel3 == RX)
							program->channel3 = NO_SIGNAL;

						program->RX_used = true;	

						settings_screen_page2_set_rx_visual(4);
					}
				}
				else if (x > 600 && x < 900 && y > 950 && y < 1650)
				{
					if(program->channel4 != RX)
					{
						program->channel4 = TX;
						if (program->channel1 == TX)
							program->channel1 = NO_SIGNAL;
						if (program->channel2 == TX)
							program->channel2 = NO_SIGNAL;
						if (program->channel3 == TX)
							program->channel3 = NO_SIGNAL;

						program->TX_used = true;	

						settings_screen_page2_set_tx_visual(4);
					}
				}
				else if (x > 1500 && x < 2000 && y > 3500 && y < 3800)
				{
					SM_SetState(&program->program_sm, STATE_SETTINGSSCREEN_PAGE1, now_ms);
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