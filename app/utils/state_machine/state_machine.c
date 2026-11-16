/**
 *******************************************************************************
 * @file 				state_machine.c
 * @author 				Arthur Retaillaud
 * @creation_date 		15/11/2026
 * @update_date			15/11/2026
 * @see					state_machine.h
 * @brief				Implémentation des fonctionnalités liées à la gestion de machines à états.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdio.h>

#include "state_machine.h"
#include "../utils.h"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
Execution_State SM_Init(StateMachine_t *sm, uint32_t initial_state, uint32_t now_ms)
{
    if (sm == NULL)
        return EXECUTION_ERROR;

    sm->state = initial_state;
    sm->previous_state = initial_state;
    sm->state_timestamp = now_ms;

    sm->state_changed = true;

    return EXECUTION_OK;
}

Execution_State SM_SetState(StateMachine_t *sm, uint32_t new_state, uint32_t now_ms)
{
    if (sm == NULL)
        return EXECUTION_ERROR;

    if (sm->state == new_state)
        return EXECUTION_ERROR;

    sm->previous_state = sm->state;
    sm->state = new_state;

    sm->state_timestamp = now_ms;
    sm->state_changed = true;

    return EXECUTION_OK;
}

bool SM_IsState(const StateMachine_t *sm, uint32_t state)
{
    if (sm == NULL)
        return false;

    return (sm->state == state);
}

uint32_t SM_GetState(const StateMachine_t *sm)
{
    if (sm == NULL)
        return 0;

    return sm->state;
}

uint32_t SM_GetPreviousState(const StateMachine_t *sm)
{
    if (sm == NULL)
        return 0;

    return sm->previous_state;
}

uint32_t SM_GetStateDuration(const StateMachine_t *sm, uint32_t now_ms)
{
    if (sm == NULL)
        return 0;

    return now_ms - sm->state_timestamp;
}

bool SM_HasTimedOut(const StateMachine_t *sm, uint32_t timeout_ms, uint32_t now_ms)
{
    return SM_GetStateDuration(sm, now_ms) >= timeout_ms;
}

bool SM_ConsumeStateChange(StateMachine_t *sm)
{
    if (sm == NULL)
        return false;

    bool changed = sm->state_changed;

    sm->state_changed = false;

    return changed;
}
