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
#define MODULE_NAME				"INFOS_SCREEN"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

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
    ILI9341_DrawRoundFilledRectangle(22, 49, 298, 225, 20, COLOR_PANEL);

    // Texte
    uint16_t x = ILI9341_PutCentered(160, 59, "Auteurs : - Arthur Retaillaud", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_Puts(x + 10 * 7, 70, "- Timeo Retailleau", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_PutCentered(160, 95,  "Projet realise a l'Ecole Superieure",   &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_PutCentered(160, 106, "d'Electronique de l'Ouest en 2026/2027.", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_PutCentered(160, 131, "Dans le contexte du cours de projet en", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_PutCentered(160, 142, "electronique encadre par M. Arboux.",   &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_PutCentered(160, 167, "Merci a tous les developpeurs des",     &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_PutCentered(160, 178, "bibliotheques utilisees.",              &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
    ILI9341_PutCentered(160, 203, "Et merci a vous qui utilisez ce projet!", &Font_7x10, ILI9341_COLOR_BLACK, COLOR_PANEL);
}
