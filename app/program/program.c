#include <stdio.h>

#include "program.h"
#include "../utils/state_machine/state_machine.h"
#include "../utils/utils.h"
#include "../display/display.h"
#include "../display/screens/start_screen/start_screen.h"

Execution_State Program_Init(Program_t *program, uint32_t now_ms)
{
    if (program == NULL)
        return EXECUTION_ERROR;

    if (SM_Init(&program->program_sm, STATE_INIT, now_ms) == EXECUTION_OK)
    {
        return EXECUTION_OK;
    }
    else
    {
        return EXECUTION_ERROR;
    }
}


Execution_State Program_Update(Program_t *program, uint32_t now_ms)
{
    if (program == NULL)
        return EXECUTION_ERROR;

    bool entered = SM_ConsumeStateChange(&program->program_sm);

    switch (SM_GetState(&program->program_sm))
    {
        case STATE_INIT:
            if (entered)
            {
                printf("----------First loop in STATE_INIT\n");
                DISPLAY_init();
            }

            SM_SetState(&program->program_sm, STATE_1, now_ms);

            break;

        case STATE_1:
            if (entered)
            {
            	printf("----------First loop in STATE_1\n");
            	draw_start_screen();
            }

            SM_SetState(&program->program_sm, STATE_2, now_ms);

            break;

        case STATE_2:
			if (entered)
			{
				printf("----------First loop in STATE_2\n");
			}

			SM_SetState(&program->program_sm, STATE_3, now_ms);

			break;

        case STATE_3:
			if (entered)
			{
				printf("----------First loop in STATE_3\n");
			}

			SM_SetState(&program->program_sm, STATE_DONE, now_ms);

			break;

        case STATE_DONE:
            if (entered)
            {
            	printf("----------First loop in STATE_DONE\n");
            }

            /* Attente d'une éventuelle réinitialisation */

            break;

        case STATE_ERROR:
            if (entered)
            {
            	printf("----------First loop in STATE_ERROR\n");
            }

            /* Attente d'une éventuelle réinitialisation */

            break;

        default:
            SM_SetState(&program->program_sm, STATE_ERROR, now_ms);

            break;

        return EXECUTION_OK;
    }
}
