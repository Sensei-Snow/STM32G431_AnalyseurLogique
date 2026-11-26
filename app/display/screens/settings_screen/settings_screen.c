/**
 *******************************************************************************
 * @file 				settings_screen.c
 * @author 				Arthur Retaillaud
 * @creation_date 		23/11/2026
 * @update_date			25/11/2026
 * @see					settings_screen.h
 * @brief				Implémentation des fonctionnalités liées à l'écran de paramètres.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdint.h>

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
#include "../images/image_arrow_left.h"
#include "../images/image_frame_settingsscreen_page1.h"
#include "../images/image_frame_settingsscreen_page2.h"

/* **************************************************** Private macros *************************************************** */
#define MODULE_NAME				"SETTINGS_SCREEN"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
void draw_settings_screen_page1(void)
{
	LOGS_info(MODULE_NAME, "Drawing settings_screen_page1");

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

void settings_screen_page1_set_uart(void)
{
	LOGS_info(MODULE_NAME, "Setting UART as the selected protocol");

	// Cadres des trois boutons
	ILI9341_putImage_monochrome_v2(95, 80, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLUE2);
	ILI9341_putImage_monochrome_v2(95, 128, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(96, 176, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);

	// Libellés
	ILI9341_PutCentered(160, 89, "UART", &Font_11x18, ILI9341_COLOR_BLUE2, COLOR_PANEL);
	ILI9341_PutCentered(160, 137, "I2C", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
	ILI9341_PutCentered(160, 185, "SPI", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
}

void settings_screen_page1_set_i2c(void)
{
	LOGS_info(MODULE_NAME, "Setting I2C as the selected protocol");

	// Cadres des trois boutons
	ILI9341_putImage_monochrome_v2(95, 80, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(95, 128, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLUE2);
	ILI9341_putImage_monochrome_v2(96, 176, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);

	// Libellés
	ILI9341_PutCentered(160, 89, "UART", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
	ILI9341_PutCentered(160, 137, "I2C", &Font_11x18, ILI9341_COLOR_BLUE2, COLOR_PANEL);
	ILI9341_PutCentered(160, 185, "SPI", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
}

void settings_screen_page1_set_spi(void)
{
	LOGS_info(MODULE_NAME, "Setting SPI as the selected protocol");
	
	// Cadres des trois boutons
	ILI9341_putImage_monochrome_v2(95, 80, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(95, 128, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(96, 176, 130, 36, image_frame_settingsscreen_page1, ILI9341_COLOR_BLUE2);

	// Libellés
	ILI9341_PutCentered(160, 89, "UART", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
	ILI9341_PutCentered(160, 137, "I2C", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);
	ILI9341_PutCentered(160, 185, "SPI", &Font_11x18, ILI9341_COLOR_BLUE2, COLOR_PANEL);
}

void draw_settings_screen_page2_uart(void)
{
	LOGS_info(MODULE_NAME, "Drawing settings_screen_page2_uart");

	// Fond blanc
	ILI9341_Fill(ILI9341_COLOR_WHITE);

	// Bouton fermer
	ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);
	ILI9341_putImage_monochrome_v2(15, 9, 16, 23, image_cross, ILI9341_COLOR_BLACK);

	// Titre + icône
	ILI9341_Puts(206, 12, "Parametres", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
	ILI9341_putImage_monochrome_v2(180, 12, 16, 16, image_settings, ILI9341_COLOR_BLACK);

	// Panneau gris : x = 22..298, y = 49..225, rayon 20
	ILI9341_DrawRoundFilledRectangle(22, 49, 298, 225, 20, COLOR_PANEL);

	// Flèche de retour (à cheval sur le bord gauche du panneau)
	ILI9341_putImage_monochrome_v2(4, 121, 36, 30, image_arrow_left, ILI9341_COLOR_BLACK);

	// Titre du panneau (centré)
	ILI9341_PutCentered(160, 54, "Signaux logiques", &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);

	// Séparateurs
	for (uint16_t i = 0; i < 4; i++) {
		ILI9341_DrawLine(36, 81 + 36 * i, 282, 81 + 36 * i, ILI9341_COLOR_BLACK);
	}

	// Les 4 voies : numéro, cadre RX, cadre TX
	for (uint16_t i = 0; i < 4; i++) {
		uint16_t y = 91 + 36 * i;   // haut des cadres : 91, 127, 163, 199
		char num[2] = { (char)('1' + i), '\0' };

		// Numéro de voie
		ILI9341_Puts(58, y + 1, num, &Font_11x18, ILI9341_COLOR_BLACK, COLOR_PANEL);

		// Cadres RX / TX
		ILI9341_putImage_monochrome_v2(97, y, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, y, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);

		// Libellés centrés dans leurs cadres
		ILI9341_PutCentered(130, y + 4, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, y + 4, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
	}
}

void settings_screen_page2_set_rx_visual(uint8_t channel_rx)
{
	if (channel_rx == 1)
	{
		ILI9341_putImage_monochrome_v2(97, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);
		ILI9341_putImage_monochrome_v2(97, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);

		ILI9341_PutCentered(130, 95, "RX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
		ILI9341_PutCentered(130, 131, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 167, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 203, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
	}
	else if (channel_rx == 2)
	{
		ILI9341_putImage_monochrome_v2(97, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);
		ILI9341_putImage_monochrome_v2(97, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);

		ILI9341_PutCentered(130, 95, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 131, "RX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
		ILI9341_PutCentered(130, 167, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 203, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
	}
	else if (channel_rx == 3)
	{
		ILI9341_putImage_monochrome_v2(97, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);
		ILI9341_putImage_monochrome_v2(97, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		
		ILI9341_PutCentered(130, 95, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 131, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 167, "RX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
		ILI9341_PutCentered(130, 203, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
	}
	else if (channel_rx == 4)
	{
		ILI9341_putImage_monochrome_v2(97, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(97, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);
		
		ILI9341_PutCentered(130, 95, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 131, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 167, "RX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(130, 203, "RX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
	}
}

void settings_screen_page2_set_tx_visual(uint8_t channel_tx)
{
	if (channel_tx == 1)
	{
		ILI9341_putImage_monochrome_v2(193, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);
		ILI9341_putImage_monochrome_v2(193, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);

		ILI9341_PutCentered(226, 95, "TX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
		ILI9341_PutCentered(226, 131, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 167, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 203, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
	}
	else if (channel_tx == 2)
	{
		ILI9341_putImage_monochrome_v2(193, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);
		ILI9341_putImage_monochrome_v2(193, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);

		ILI9341_PutCentered(226, 95, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 131, "TX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
		ILI9341_PutCentered(226, 167, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 203, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
	}
	else if (channel_tx == 3)
	{
		ILI9341_putImage_monochrome_v2(193, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);
		ILI9341_putImage_monochrome_v2(193, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);

		ILI9341_PutCentered(226, 95, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 131, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 167, "TX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
		ILI9341_PutCentered(226, 203, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
	}
	else if (channel_tx == 4)
	{
		ILI9341_putImage_monochrome_v2(193, 91, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 127, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 163, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLACK);
		ILI9341_putImage_monochrome_v2(193, 199, 65, 18, image_frame_settingsscreen_page2, ILI9341_COLOR_BLUE2);

		ILI9341_PutCentered(226, 95, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 131, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 167, "TX", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
		ILI9341_PutCentered(226, 203, "TX", &Font_7x10, ILI9341_COLOR_BLUE2, COLOR_PANEL);
	}
}