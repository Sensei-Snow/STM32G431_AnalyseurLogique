/**
 *******************************************************************************
 * @file 				logs.c
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			13/11/2026
 * @see					logs.h
 * @brief				Implémentation des fonctionnalités liées aux logs.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdio.h>
#include <stdint.h>

#include "stm32g4xx_hal.h"

/* **************************************************** Private macros *************************************************** */

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */
/**
 * @brief		Permet d'obtenir le temps d'exécution du STM32
 * @return		Retourne une chaîne de caractère sous la forme "[Heures:Minutes:Secondes]"
 */
char* GetUptime(void);

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */
char* GetUptime(void)
{
    static char buffer[16];

    uint32_t uptime = HAL_GetTick() / 1000;

    uint32_t hours   = uptime / 3600;
    uint32_t minutes = (uptime % 3600) / 60;
    uint32_t seconds = uptime % 60;

    snprintf(buffer, sizeof(buffer), "[%02u:%02u:%02u]",
             (unsigned int)hours,
             (unsigned int)minutes,
             (unsigned int)seconds);

    return buffer;
}

/* ********************************************** Public functions definitions ******************************************* */
void LOGS_info(const char *message)
{
	printf("[INFO] -- %s -- %s", GetUptime(), message);
}

void LOGS_warning(const char *message)
{
	printf("[WARNING] -- %s -- %s", GetUptime(), message);
}

void LOGS_error(const char *message)
{
	printf("[ERROR] -- %s -- %s", GetUptime(), message);
}
