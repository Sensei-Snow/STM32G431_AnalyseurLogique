/**
 *******************************************************************************
 * @file 				internal_led.h
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			11/11/2026
 * @see					internal_led.h
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées à la LED interne de la carte Nucléo.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

#include <stdbool.h>
#include <stdint.h>

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Initialisation de la LED interne de la carte Nucléo au niveau des GPIO
 */
void INTERNAL_LED_init(void);

/**
 * @brief		Gestion de l'allumage de la LED interne de la carte Nucléo
 * @param		state : true pour allumer la LED et false pour l'éteindre
 */
void INTERNAL_LED_set(bool state);

/**
 * @brief		Clignotement à l'infi de la LED interne de la carte Nucléo
 */
void INTERNAL_LED_blink(uint32_t nb_loop, uint32_t delay_ms);
