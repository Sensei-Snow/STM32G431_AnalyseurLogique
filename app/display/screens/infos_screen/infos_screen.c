/**
 *******************************************************************************
 * @file 				infos_screen.c
 * @author 				Arthur Retaillaud
 * @creation_date 		19/11/2026
 * @update_date			22/11/2026
 * @see					infos_screen.h
 * @brief				Implémentation des fonctionnalités liées à l'écran d'informations.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include "tft_ili9341/stm32g4_ili9341.h"
#include "../../TFTILI9341_driver_v2/TFTILI9341_driver_v2.h"
#include "infos_screen.h"
#include "../../../utils/logs/logs.h"
#ifndef PROGMEM
#define PROGMEM
#endif
#include "../images/image_button.h"
#include "../images/image_cross.h"
#include "../images/image_information.h"

/* **************************************************** Private macros *************************************************** */
#define COLOR_PANEL 0xDEDB

#define MODULE_NAME				"INFOS_SCREEN"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */
static uint16_t putsCentered(uint16_t cx, uint16_t y, char *str, FontDef_t *font,
                             uint16_t fg, uint16_t bg)
{
    uint16_t w, h;
    ILI9341_GetStringSize(str, font, &w, &h);
    uint16_t x = cx - w / 2;
    ILI9341_Puts(x, y, str, font, fg, bg);
    return x;
}

static void fillRoundRect(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,
                          uint16_t r, uint16_t color)
{
    ILI9341_DrawFilledRectangle(x0 + r, y0, x1 - r, y1, color);          /* bande centrale */
    ILI9341_DrawFilledRectangle(x0, y0 + r, x0 + r - 1, y1 - r, color);  /* bord gauche */
    ILI9341_DrawFilledRectangle(x1 - r + 1, y0 + r, x1, y1 - r, color);  /* bord droit */
    ILI9341_DrawFilledCircle(x0 + r, y0 + r, r, color);
    ILI9341_DrawFilledCircle(x1 - r, y0 + r, r, color);
    ILI9341_DrawFilledCircle(x0 + r, y1 - r, r, color);
    ILI9341_DrawFilledCircle(x1 - r, y1 - r, r, color);
}

/* ********************************************** Public functions definitions ******************************************* */
void draw_infos_screen(void)
{
    ILI9341_Fill(ILI9341_COLOR_WHITE);

    // Bouton fermer
    ILI9341_putImage_monochrome_v2(5, 5, 33, 33, image_button, ILI9341_COLOR_BLACK);
    ILI9341_putImage_monochrome_v2(15, 9, 16, 23, image_cross, ILI9341_COLOR_BLACK);

    // Titre + icône
    ILI9341_Puts(260, 12, "Infos", &Font_11x18, ILI9341_COLOR_BLACK, ILI9341_COLOR_WHITE);
    ILI9341_putImage_monochrome_v2(234, 12, 15, 16, image_information, ILI9341_COLOR_BLACK);

    //Panel de fond gris
    fillRoundRect(22, 49, 298, 225, 20, COLOR_PANEL);

    // Texte
    uint16_t x = putsCentered(160, 59, "Auteurs : - Arthur Retaillaud", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_Puts(x + 10 * 7, 70, "- Timeo Retailleau", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    putsCentered(160, 95,  "Projet realise a l'Ecole Superieure",   &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    putsCentered(160, 106, "d'Electronique de l'Ouest en 2026/2027.", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    putsCentered(160, 131, "Dans le contexte du cours de projet en", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    putsCentered(160, 142, "electronique encadre par M. Arboux.",   &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    putsCentered(160, 167, "Merci a tous les developpeurs des",     &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    putsCentered(160, 178, "bibliotheques utilisees.",              &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    putsCentered(160, 203, "Et merci a vous qui utilisez ce projet!", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
}
