/**
 *******************************************************************************
 * @file 				home_screen.c
 * @author 				Arthur Retaillaud
 * @creation_date 		17/11/2026
 * @update_date			22/11/2026
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
#include "../images/image_button.h"
#include "../images/image_menu.h"
#include "../images/image_cross.h"
#include "../images/image_error.h"
#include "../images/image_settings.h"
#include "../images/image_information.h"

/* **************************************************** Private macros *************************************************** */
#define MODULE_NAME		"HOME_SCREEN"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */

void draw_home_screen_initial(void)
{
	LOGS_info(MODULE_NAME, "Drawing home_screen_initial");

	// Fond blanc
	ILI9341_Fill(ILI9341_COLOR_WHITE);

	// Bouton menu
	ILI9341_putImage_monochrome_v2(15, 12, 16, 16, image_menu, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);

	// Texte
	ILI9341_PutCentered(160, 123, "Aucun parametre", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_PutCentered(160, 148, "selectionne", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);

	// Icône d'erreur
	ILI9341_putImage_monochrome_v2(145, 84, 31, 31, image_error, ILI9341_COLOR_BLACK);
}

void draw_home_screen_incomplete_settings(void)
{
	LOGS_info(MODULE_NAME, "Drawing home_screen_incomplete_settings");

	// Fond blanc
	ILI9341_Fill(ILI9341_COLOR_WHITE);

	// Bouton menu
	ILI9341_putImage_monochrome_v2(15, 12, 16, 16, image_menu, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);

	// Texte
	ILI9341_PutCentered(160, 123, "Parametres", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_PutCentered(160, 148, "incomplets", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);

	// Icône d'erreur
	ILI9341_putImage_monochrome_v2(145, 84, 31, 31, image_error, ILI9341_COLOR_BLACK);
}

void draw_home_screen_ok(void)
{
	LOGS_info(MODULE_NAME, "Drawing home_screen_ok");

	// Fond blanc
	ILI9341_Fill(ILI9341_COLOR_WHITE);

	// Bouton menu
	ILI9341_putImage_monochrome_v2(15, 12, 16, 16, image_menu, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);

	// Texte
	ILI9341_PutCentered(160, 123, "Parametres", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_PutCentered(160, 148, "OK", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);

	// Icône d'erreur
	ILI9341_putImage_monochrome_v2(145, 84, 31, 31, image_error, ILI9341_COLOR_BLACK);
}

void draw_home_screen_menu(void)
{
	LOGS_info(MODULE_NAME, "Drawing home_screen_menu");

	// Fond blanc
	ILI9341_Fill(ILI9341_COLOR_WHITE);

	// Panel de fond gris
	ILI9341_DrawRoundFilledRectangle(0, 0, 159, 239, 20, COLOR_PANEL);
	ILI9341_DrawFilledRectangle(0, 0, 20, 239, COLOR_PANEL);

	// Bouton menu
	ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(15, 9, 16, 23, image_cross, ILI9341_COLOR_BLACK);

	// Séparateurs
	ILI9341_DrawLine(11, 49, 147, 49, ILI9341_COLOR_BLACK);
	ILI9341_DrawLine(11, 89, 147, 89, ILI9341_COLOR_BLACK);
	ILI9341_DrawLine(11, 129, 147, 129, ILI9341_COLOR_BLACK);

	// Icônes
	ILI9341_putImage_monochrome_v2(11, 61, 16, 16, image_settings, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(11, 102, 15, 16, image_information, ILI9341_COLOR_BLACK);

	// Textes
	ILI9341_Puts(32, 61, "Parametres", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
	ILI9341_Puts(32, 102, "Infos", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
}
