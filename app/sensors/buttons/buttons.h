/**
 *******************************************************************************
 * @file 				buttons.h
 * @author 				Arthur Retaillaud
 * @creation_date 		04/11/2026
 * @update_date			11/11/2026
 * @see					buttons.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées aux boutons poussoirs.
 *******************************************************************************
*/

#pragma once


/* ******************************************************* Includes ****************************************************** */
#include <stdbool.h>

#include "../../utils/utils.h"

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
 * @return		STATE_OK si l'initialisation s'est bien déroulée et STATE_WARNING si la fonction de callback n'a pas pu être ajoutée
 */
Execution_State BUTTONS_init(void);

/**
 * @brief		Lecture de la pression sur un bouton
 * @return		true si le bouton est appuyé et false dans le cas inverse
 */
bool BUTTON_startstop_read(void);

/**
 * @brief		Lecture de l'état d'un bouton
 * @param		button_startstop_event : Pointeur vers la variable qui contient l'état du bouton
 */
void BUTTONS_update(button_e * button_startstop_event);
