/**
 *******************************************************************************
 * @file 				start_screen.c
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			11/11/2026
 * @see					start_screen.h
 * @brief				Implémentation des fonctionnalités liées à l'affichage de l'écran de démarrage.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include "tft_ili9341/stm32g4_ili9341.h"
#include "../../TFTILI9341_driver_v2/TFTILI9341_driver_v2.h"
#ifndef PROGMEM
#define PROGMEM
#endif
#include "images/image_frame.h"
#include "images/image_logo_eseo.h"

/* **************************************************** Private macros *************************************************** */
#define SPACE_WIDTH 		119
#define SPACE_HEIGHT 		33
#define LOGO_ESEO_WIDTH  	187
#define LOGO_ESEO_HEIGHT	68

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
void draw_start_screen(void)
{
    ILI9341_Fill(ILI9341_COLOR_WHITE);

    ILI9341_Puts(81, 12, "Retaillo", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
    ILI9341_Puts(158, 42, "Studio", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);

    ILI9341_putImage_monochrome_v2(136, 41, SPACE_WIDTH, SPACE_HEIGHT, image_frame, ILI9341_COLOR_BLACK);
    ILI9341_putImage_monochrome_v2(65, 11, SPACE_WIDTH, SPACE_HEIGHT, image_frame, ILI9341_COLOR_BLACK);

    ILI9341_Puts(39, 96, "Analyseur logique 3000", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);

    ILI9341_putImage(67, 147, LOGO_ESEO_WIDTH, LOGO_ESEO_HEIGHT,
                     (const int16_t *)image_logo_eseo,
					 LOGO_ESEO_WIDTH * LOGO_ESEO_HEIGHT);
}
