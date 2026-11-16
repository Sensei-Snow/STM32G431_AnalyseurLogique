/**
 *******************************************************************************
 * @file 				state_machine.h
 * @author 				Arthur Retaillaud
 * @creation_date 		15/11/2026
 * @update_date			15/11/2026
 * @see					state_machine.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées à la gestion de machines à états.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */
#include <stdint.h>
#include <stdbool.h>

#include "../utils.h"

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */
typedef struct
{
    uint32_t state;
    uint32_t previous_state;

    uint32_t state_timestamp;

    bool state_changed;

} StateMachine_t;

/* *********************************************** Public functions declarations ***************************************** */
//-- Initialization -----------------------------------
/**
 * @brief		Initialise la machine à états
 * @param		sm : Pointeur vers la machine à états
 * @param		initial_state : État initial de la machine à états
 * @param		now_ms : Temps en milisecondes
 * @return		EXECUTION_OK si la machine à états s'est initialisée et EXECUTION_ERROR si la machine à états n'a pas été créée
 */
Execution_State SM_Init(StateMachine_t *sm, uint32_t initial_state, uint32_t now_ms);

//-- States management -----------------------------------
/**
 * @brief		Définis le prochain état de la machine à états
 * @param		sm : Pointeur vers la machine à états
 * @param		new_state : Nom du prochain état
 * @param		now_ms : Temps en milisecondes
 * @return		EXECUTION_OK si le prochain état peut être changé ou EXECUTION_ERROR si la machine à états n'a pas été créée ou le prochain état est le même que celui actuel
 */
Execution_State SM_SetState(StateMachine_t *sm, uint32_t new_state, uint32_t now_ms);

/**
 * @brief		Vérifie l'état actuel
 * @param		sm : Pointeur vers la machine à états
 * @param		state : État à comparer avec celui actuel de la machine à états
 * @return		true si l'état en paramètre est le même que celui actuel de la machine à états, sinon false
 */
bool SM_IsState(const StateMachine_t *sm, uint32_t state);

/**
 * @brief		Obtenir l'état actuel
 * @param		sm : Pointeur vers la machine à états
 * @return		État actuel de la machine à états
 */
uint32_t SM_GetState(const StateMachine_t *sm);

/**
 * @brief		Obtenir l'état précédent
 * @param		sm : Pointeur vers la machine à états
 * @return		État précédent de la machine à états
 */
uint32_t SM_GetPreviousState(const StateMachine_t *sm);

//-- Time management -----------------------------------
/**
 * @brief		Obtenir le temps d'exécution de l'état actuel
 * @param		sm : Pointeur vers la machine à états
 * @param		now_ms : Temps en milisecondes
 */
uint32_t SM_GetStateDuration(const StateMachine_t *sm, uint32_t now_ms);

/**
 * @brief		Vérifie si un certains temps s'est écoulé dans létat
 * @param		sm : Pointeur vers la machine à états
 * @param		timeout_ms : Temps en milisecondes à attendre dans l'état actuel de la machine à états
 * @param		now_ms : Temps en milisecondes
 * @return		true si le temps donné en pramètre s'est écoulé dans l'état sinon false
 */
bool SM_HasTimedOut(const StateMachine_t *sm, uint32_t timeout_ms, uint32_t now_ms);

//-- Transitions management -----------------------------------
/**
 * @brief		Vérifie si une transition d'états à eu lieu dans la machine à états
 * @param		sm : Pointeur vers la machine à états
 * @return		true si ce n'est pas le même état sinon false
 */
bool SM_ConsumeStateChange(StateMachine_t *sm);
