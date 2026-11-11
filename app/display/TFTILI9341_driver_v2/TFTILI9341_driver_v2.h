/**
 *******************************************************************************
 * @file 				TFTILI9341_driver_v2.c
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			11/11/2026
 * @see					TFTILI9341_driver_v2.h
 * @brief				Fichier d'en-tête pour la version 2 du driver fourni par l'ESEO pour l'écran TFTILI9341 car il est pété (oui oui le driver).
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Affichage d'une image monochrome sur l'écran TFTILI9341 (sans devoir mettre une image avec une taille multiple de 8 mdr)
 * @param		x0 : Coordonnée x de l'emplacement de l'image
 * @param		y0 : Coordonnée y de l'emplacement de l'image
 * @param		w : Largeur de l'image
 * @param		h : Longueur de l'image
 * @param		bmp : Pointeur vers l'image BMP
 * @param		color : Couleur de l'image
 */
void ILI9341_putImage_monochrome_v2(int16_t x0, int16_t y0, int16_t w, int16_t h, const uint8_t *bmp, uint16_t color);
