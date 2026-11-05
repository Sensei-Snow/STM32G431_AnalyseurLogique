/**
 *******************************************************************************
 * @file 				buttons.h
 * @author 				Arthur Retaillaud
 * @creation_date 		04/11/2026
 * @update_date			04/11/2026
 * @see					buttons.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées aux boutons poussoirs.
 *******************************************************************************
*/

#pragma once


/* ******************************************************* Includes ****************************************************** */
#include <stdint.h>

#include "stm32g4_utils.h"
#include "stm32g4xx_hal.h"

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */
/**
 * @brief		Énumération de tout les états possibles d'un bouton
 */
typedef enum
{
	BUTTON_NO_EVENT,
	BUTTON_PRESS_EVENT,
	BUTTON_RELEASE_EVENT
}button_e;

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Initialisation des boutons au niveau des GPIO
 */
void BUTTONS_init(void);

/**
 * @brief		Lecture de la pression sur un bouton
 * @return		true si le bouton est appuyé et false dans le cas inverse
 */
bool BUTTON_startstop_read(void);

/**
 * @brief		Lecture de l'état d'un bouton
 * @param		Pointeur vers la variable qui contient l'état du bouton
 */
void BUTTONS_update(button_e * button_startstop_event);
