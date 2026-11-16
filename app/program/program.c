/**
 *******************************************************************************
 * @file 				program.c
 * @author 				Arthur Retaillaud
 * @creation_date 		15/11/2026
 * @update_date			16/11/2026
 * @see					program.h
 * @brief				Implémentation des fonctionnalités liées au programme principal.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdio.h>

#include "program.h"
#include "../utils/state_machine/state_machine.h"
#include "../utils/logs/logs.h"
#include "../utils/utils.h"
#include "../display/display.h"
#include "../display/screens/start_screen/start_screen.h"

/* ******************************************************* Includes ****************************************************** */
#define MODULE_NAME		"PROGRAM"

/* **************************************************** Private macros *************************************************** */

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
Execution_State Program_Init(Program_t *program, uint32_t now_ms)
{
    if (program == NULL)
    {
    	LOGS_error(MODULE_NAME, "Structure de program inexistante");
    	return EXECUTION_ERROR;
    }

    LOGS_info(MODULE_NAME, "Initialisation de la machine à états de program");
    if (SM_Init(&program->program_sm, STATE_INIT, now_ms) == EXECUTION_OK)
    {
    	LOGS_info(MODULE_NAME, "Machine à états de program initialisée");
        return EXECUTION_OK;
    }
    else
    {
    	LOGS_error(MODULE_NAME, "Machine à états non initialisée");
        return EXECUTION_ERROR;
    }
}


Execution_State Program_Update(Program_t *program, uint32_t now_ms)
{
    if (program == NULL)
    {
    	LOGS_error(MODULE_NAME, "Structure de program inexistante");
    	return EXECUTION_ERROR;
    }

    bool entered = SM_ConsumeStateChange(&program->program_sm);

    switch (SM_GetState(&program->program_sm))
    {
        case STATE_INIT:
            if (entered)
            {
                LOGS_info(MODULE_NAME, "First loop in STATE_INIT");
                DISPLAY_init();
            }

            SM_SetState(&program->program_sm, STATE_1, now_ms);

            break;

        case STATE_1:
            if (entered)
            {
            	LOGS_info(MODULE_NAME, "First loop in STATE_1");
            	draw_start_screen();
            }

            SM_SetState(&program->program_sm, STATE_2, now_ms);

            break;

        case STATE_2:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_2");
			}

			SM_SetState(&program->program_sm, STATE_3, now_ms);

			break;

        case STATE_3:
			if (entered)
			{
				LOGS_info(MODULE_NAME, "First loop in STATE_3");
			}

			SM_SetState(&program->program_sm, STATE_DONE, now_ms);

			break;

        case STATE_DONE:
            if (entered)
            {
            	LOGS_info(MODULE_NAME, "First loop in STATE_DONE");
            }

            /* Attente d'une éventuelle réinitialisation */

            break;

        case STATE_ERROR:
            if (entered)
            {
            	LOGS_info(MODULE_NAME, "First loop in STATE_ERROR");
            }

            /* Attente d'une éventuelle réinitialisation */

            break;

        default:
            SM_SetState(&program->program_sm, STATE_ERROR, now_ms);

            break;

        return EXECUTION_OK;
    }
}
