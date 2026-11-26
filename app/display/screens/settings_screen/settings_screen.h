/**
 *******************************************************************************
 * @file 				settings_screen.h
 * @author 				Arthur Retaillaud
 * @creation_date 		23/11/2026
 * @update_date			25/11/2026
 * @see					settings_screen.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées à l'écran de paramètres.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */
#include <stdint.h>

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Affiche la page 1 de l'écran de paramètres
 */
void draw_settings_screen_page1(void);

/**
 * @brief		Définis visuellement le protocole comme UART sur la page 1 de l'écran de paramètres
 */
void settings_screen_page1_set_uart(void);

/**
 * @brief		Définis visuellement le protocole comme I²C sur la page 1 de l'écran de paramètres
 */
void settings_screen_page1_set_i2c(void);

/**
 * @brief		Définis visuellement le protocole comme SPI sur la page 1 de l'écran de paramètres
 */
void settings_screen_page1_set_spi(void);

/**
 * @brief		Affiche la page 2 de l'écran de paramètres pour le protocole UART
 */
void draw_settings_screen_page2_uart(void);

void settings_screen_page2_set_rx_visual(uint8_t channel_rx);

void settings_screen_page2_set_tx_visual(uint8_t channel_tx);