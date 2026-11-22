/**
 *******************************************************************************
 * @file 				TFTILI9341_driver_v2.h
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			22/11/2026
 * @see					TFTILI9341_driver_v2.c
 * @brief				Fichier d'en-tête pour la version 2 du driver fourni par l'ESEO pour l'écran TFTILI9341 car il est pété (oui oui le driver).
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

/* ***************************************************** Public macros *************************************************** */
#define COLOR_PANEL 	0xDEDB

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Affichage d'un texte centré horizontalement sur l'écran TFTILI9341
 * @param		center_x : Coordonnée x du centre
 * @param		y : Coordonnée y du texte
 * @param		text : Pointeur vers le texte à afficher
 * @param		font : Pointeur vers la police d'écriture à utiliser
 * @param		text_color : Couleur du texte
 * @param		color : Couleur du fond du texte
 * @return		entier positif de la coordonnée x où a été placé le texte
 */
uint16_t ILI9341_PutCentered(uint16_t center_x, uint16_t y, char *text, FontDef_t *font, uint16_t text_color, uint16_t color);

/**
 * @brief		Affichage d'un rectangle rempli arrondi sur l'écran TFTILI9341
 * @param		x0 : Coordonnée x du coin supérieur gauche du rectangle
 * @param		y0 : Coordonnée y du coin supérieur gauche du rectangle
 * @param		x1 : Coordonnée x du coin inférieur droit du rectangle
 * @param		y1 : Coordonnée y du coin inférieur droit du rectangle
 * @param		radius : Pourcentage d'arrondissement des coins du rectangle
 * @param		color : Couleur du rectangle
 */
void ILI9341_DrawRoundFilledRectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t radius, uint16_t color);

/**
 * @brief		Affichage d'une image monochrome sur l'écran TFTILI9341 (sans devoir mettre une image avec une taille multiple de 8 mdr)
 * @param		x0 : Coordonnée x de l'emplacement de l'image
 * @param		y0 : Coordonnée y de l'emplacement de l'image
 * @param		width : Largeur de l'image
 * @param		height : Longueur de l'image
 * @param		bmp : Pointeur vers l'image BMP
 * @param		color : Couleur de l'image
 */
void ILI9341_putImage_monochrome_v2(int16_t x0, int16_t y0, int16_t width, int16_t height, const uint8_t *bmp, uint16_t color);
