/**
 *******************************************************************************
 * @file 				TFTILI9341_driver_v2.c
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			11/11/2026
 * @see					TFTILI9341_driver_v2.h
 * @brief				Version 2 du driver fourni par l'ESEO pour l'écran TFTILI9341 car il est pété (oui oui le driver).
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include "tft_ili9341/stm32g4_ili9341.h"

/* **************************************************** Private macros *************************************************** */

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
void ILI9341_putImage_monochrome_v2(int16_t x0, int16_t y0, int16_t w, int16_t h, const uint8_t *bmp, uint16_t color)
{
    int16_t byteWidth = (w + 7) / 8;
    for (int16_t j = 0; j < h; j++) {
        int16_t i = 0;
        while (i < w) {
            if (bmp[j * byteWidth + i / 8] & (0x80 >> (i & 7)))
            {
                int16_t start = i;
                while (i < w && (bmp[j * byteWidth + i / 8] & (0x80 >> (i & 7))))
                    i++;
                ILI9341_DrawFilledRectangle(x0 + start, y0 + j, x0 + i - 1, y0 + j, color);
            }
            else
            {
                i++;
            }
        }
    }
