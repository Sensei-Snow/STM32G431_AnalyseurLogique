/**
 *******************************************************************************
 * @file 				settings_screen.c
 * @author 				Arthur Retaillaud
 * @creation_date 		23/11/2026
 * @update_date			23/11/2026
 * @see					settings_screen.h
 * @brief				Implémentation des fonctionnalités liées à l'écran de paramètres.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include "tft_ili9341/stm32g4_ili9341.h"
#include "../../TFTILI9341_driver_v2/TFTILI9341_driver_v2.h"
#include "settings_screen.h"
#include "../../../utils/logs/logs.h"
#ifndef PROGMEM
#define PROGMEM
#endif
#include "../images/image_cross.h"
#include "../images/image_button.h"
#include "../images/image_settings.h"
#include "../images/image_arrow_right.h"
#include "../images/image_frame_settingsscreen_page1.h"

/* **************************************************** Private macros *************************************************** */
#define MODULE_NAME				"SETTINGS_SCREEN"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
void draw_settings_screen_page1(void)
{
	LOGS_info(MODULE_NAME, "Drawing screen");

	// Fond blanc
	ILI9341_Fill(ILI9341_COLOR_WHITE);

	// Bouton fermer
	ILI9341_putImage_monochrome_v2(15, 9, 16, 23, image_cross, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);

	// Titre + icône
	ILI9341_Puts(206, 12, "Parametres", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_putImage_monochrome_v2(180, 12, 16, 16, image_settings, ILI9341_COLOR_BLACK);

	// Panel gris
	ILI9341_DrawRoundFilledRectangle(22, 49, 298, 225, 20, COLOR_PANEL);

	// Flèche de retour
	ILI9341_putImage_monochrome_v2(281, 121, 36, 30, image_arrow_right, ILI9341_COLOR_BLACK);

	// Titre du panneau
	ILI9341_PutCentered(160, 54, "Protocole", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);

	// Cadres des trois boutons
	ILI9341_putImage_monochrome_v2(95, 80, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(95, 128, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(96, 176, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);

	// Libellés
	ILI9341_PutCentered(160, 89, "UART", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
	ILI9341_PutCentered(160, 137, "I2C", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
	ILI9341_PutCentered(160, 185, "SPI", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
}
