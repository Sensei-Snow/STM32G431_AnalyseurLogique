/**
 *******************************************************************************
 * @file 				state_machine.c
 * @author 				Arthur Retaillaud
 * @creation_date 		15/11/2026
 * @update_date			16/11/2026
 * @see					state_machine.h
 * @brief				Implémentation des fonctionnalités liées à la gestion de machines à états.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdio.h>

#include "state_machine.h"
#include "../logs/logs.h"
#include "../utils.h"

/* ************************************************ Private type definition ********************************************** */
#define MODULE_NAME		"STATE MACHINE"

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
Execution_State SM_Init(StateMachine_t *sm, uint32_t initial_state, uint32_t now_ms)
{
    if (sm == NULL)
    {
    	LOGS_error(MODULE_NAME, "Machine à états inexistante");
        return EXECUTION_ERROR;
    }

    LOGS_info(MODULE_NAME, "Définition des paramètres de la structure de la machine à états");
    sm->state = initial_state;
    sm->previous_state = initial_state;
    sm->state_timestamp = now_ms;

    sm->state_changed = true;

    return EXECUTION_OK;
}

Execution_State SM_SetState(StateMachine_t *sm, uint32_t new_state, uint32_t now_ms)
{
    if (sm == NULL)
    {
    	LOGS_error(MODULE_NAME, "Machine à états inexistante");
        return EXECUTION_ERROR;
    }

    if (sm->state == new_state)
    {
    	LOGS_error(MODULE_NAME, "Le prochain état est le même que celui actuel");
        return EXECUTION_ERROR;
    }

    //LOGS_info(MODULE_NAME, "Changement des paramètres de la structure de la machine à états");
    sm->previous_state = sm->state;
    sm->state = new_state;

    sm->state_timestamp = now_ms;
    sm->state_changed = true;

    //char buffer_textlog_setstate[32];
    //snprintf(buffer_textlog_setstate, sizeof(buffer_textlog_setstate), "Passage à l'état : %u", (unsigned int)new_state);
    //LOGS_info(MODULE_NAME, buffer_textlog_setstate);
    return EXECUTION_OK;
}

bool SM_IsState(const StateMachine_t *sm, uint32_t state)
{
    if (sm == NULL)
    {
    	LOGS_error(MODULE_NAME, "Machine à états inexistante");
        return false;
    }

    LOGS_info(MODULE_NAME, "Comparaison entre les deux états");
    return (sm->state == state);
}

uint32_t SM_GetState(const StateMachine_t *sm)
{
    if (sm == NULL)
    {
    	LOGS_error(MODULE_NAME, "Machine à états inexistante");
        return 0;
    }

    //LOGS_info(MODULE_NAME, "Obtention de l'état actuel");
    return sm->state;
}

uint32_t SM_GetPreviousState(const StateMachine_t *sm)
{
    if (sm == NULL)
    {
    	LOGS_error(MODULE_NAME, "Machine à états inexistante");
        return 0;
    }

    LOGS_info(MODULE_NAME, "Obtention de l'état précédent");
    return sm->previous_state;
}

uint32_t SM_GetStateDuration(const StateMachine_t *sm, uint32_t now_ms)
{
    if (sm == NULL)
    {
    	LOGS_error(MODULE_NAME, "Machine à états inexistante");
        return 0;
    }

    LOGS_info(MODULE_NAME, "Obtention du temps d'exécution de l'état");
    return now_ms - sm->state_timestamp;
}

bool SM_HasTimedOut(const StateMachine_t *sm, uint32_t timeout_ms, uint32_t now_ms)
{
    return SM_GetStateDuration(sm, now_ms) >= timeout_ms;
}

bool SM_ConsumeStateChange(StateMachine_t *sm)
{
    if (sm == NULL)
    {
    	LOGS_error(MODULE_NAME, "Machine à états inexistante");
        return false;
    }

    //LOGS_info(MODULE_NAME, "Vérification du changement d'état");
    bool changed = sm->state_changed;

    //LOGS_info(MODULE_NAME, "Changement des paramètres de la structure de la machine à états");
    sm->state_changed = false;

    return changed;
}
