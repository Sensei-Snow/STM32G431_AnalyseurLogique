/**
 *******************************************************************************
 * @file 				TFTILI9341_driver_v2.c
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			22/11/2026
 * @see					TFTILI9341_driver_v2.h
 * @brief				Version 2 du driver fourni par l'ESEO pour l'écran TFTILI9341 car il est pété (oui oui le driver).
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdint.h>
#include <stdio.h>

#include "tft_ili9341/stm32g4_ili9341.h"
#include "TFTILI9341_driver_v2.h"
#include "../../utils/logs/logs.h"

/* **************************************************** Private macros *************************************************** */
#define MODULE_NAME		"TFTILI9341"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
uint16_t ILI9341_PutCentered(uint16_t center_x, uint16_t y, char *text, FontDef_t *font, uint16_t text_color, uint16_t color)
{
	char buffer_textlog_center[100];
	snprintf(buffer_textlog_center, sizeof(buffer_textlog_center), "Putting centered text on screen : center_x = %u, y = %u, text = %s, text_color = %u, color = %u", (unsigned int)center_x, (unsigned int)y, text, (unsigned int)text_color, (unsigned int)color);
	LOGS_info(MODULE_NAME, buffer_textlog_center);

    uint16_t width, height;
    ILI9341_GetStringSize(text, font, &width, &height);
    uint16_t x = center_x - width / 2;
    ILI9341_Puts(x, y, text, font, text_color, color);
    return x;
}

void ILI9341_DrawRoundFilledRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t radius, uint16_t color)
{
	char buffer_textlog_rectangle[100];
	snprintf(buffer_textlog_rectangle, sizeof(buffer_textlog_rectangle), "Drawing round filled rectangle image on screen : x0 = %u, y0 = %u, x1 = %u, y1 = %u, radius = %u, color = %u", (unsigned int)x0, (unsigned int)y0, (unsigned int)x1, (unsigned int)y1, (unsigned int)radius, (unsigned int)color);
	LOGS_info(MODULE_NAME, buffer_textlog_rectangle);

    ILI9341_DrawFilledRectangle(x0 + radius, y0, x1 - radius, y1, color);
    ILI9341_DrawFilledRectangle(x0, y0 + radius, x0 + radius - 1, y1 - radius, color);
    ILI9341_DrawFilledRectangle(x1 - radius + 1, y0 + radius, x1, y1 - radius, color);
    ILI9341_DrawFilledCircle(x0 + radius, y0 + radius, radius, color);
    ILI9341_DrawFilledCircle(x1 - radius, y0 + radius, radius, color);
    ILI9341_DrawFilledCircle(x0 + radius, y1 - radius, radius, color);
    ILI9341_DrawFilledCircle(x1 - radius, y1 - radius, radius, color);
}

void ILI9341_putImage_monochrome_v2(int16_t x0, int16_t y0, int16_t width, int16_t height, const uint8_t *bmp, uint16_t color)
{
	char buffer_textlog_image[100];
	snprintf(buffer_textlog_image, sizeof(buffer_textlog_image), "Putting monochrome image on screen : x0 = %u, y0 = %u, width = %u, height = %u, color = %u", (unsigned int)x0, (unsigned int)y0, (unsigned int)width, (unsigned int)height, (unsigned int)color);
	LOGS_info(MODULE_NAME, buffer_textlog_image);

	int16_t byteWidth = (width + 7) / 8;
    for (int16_t j = 0; j < height; j++) {
        int16_t i = 0;
        while (i < width) {
            if (bmp[j * byteWidth + i / 8] & (0x80 >> (i & 7)))
            {
                int16_t start = i;
                while (i < width && (bmp[j * byteWidth + i / 8] & (0x80 >> (i & 7))))
                    i++;
                ILI9341_DrawFilledRectangle(x0 + start, y0 + j, x0 + i - 1, y0 + j, color);
            }
            else
            {
                i++;
            }
        }
    }
}
