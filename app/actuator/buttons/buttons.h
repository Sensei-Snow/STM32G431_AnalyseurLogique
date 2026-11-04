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
typedef enum
{
	BUTTON_NO_EVENT,
	BUTTON_PRESS_EVENT,
	BUTTON_RELEASE_EVENT
}button_e;

/* *********************************************** Public functions declarations ***************************************** */
void BUTTONS_init(void);
bool BUTTON_startstop_read(void);
void BUTTONS_update(button_e * button_startstop_event);
