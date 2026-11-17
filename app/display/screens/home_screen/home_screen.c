/**
 *******************************************************************************
 * @file 				home_screen.c
 * @author 				Arthur Retaillaud
 * @creation_date 		17/11/2026
 * @update_date			17/11/2026
 * @see					home_screen.h
 * @brief				Implémentation des fonctionnalités liées à l'écran d'accueil
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include "tft_ili9341/stm32g4_ili9341.h"
#include "../../TFTILI9341_driver_v2/TFTILI9341_driver_v2.h"
#include "home_screen.h"
#include "../../../utils/logs/logs.h"
#ifndef PROGMEM
#define PROGMEM
#endif
#include "images/image_button.h"
#include "images/image_menu.h"
#include "images/image_error.h"

/* **************************************************** Private macros *************************************************** */
#define MODULE_NAME		"HOME_SCREEN"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */

void draw_home_screen_initial(void)
{
	LOGS_info(MODULE_NAME, "Drawing screen");

	ILI9341_Fill(ILI9341_COLOR_WHITE);

	ILI9341_putImage_monochrome_v2(15, 12, 16, 16, image_menu, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);

	ILI9341_Puts(77, 123, "Aucun parametre", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_Puts(99, 148, "selectionne", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);

	ILI9341_putImage_monochrome_v2(145, 84, 31, 31, image_error, ILI9341_COLOR_BLACK);
}
