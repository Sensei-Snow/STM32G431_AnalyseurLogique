/**
 *******************************************************************************
 * @file 				logs.c
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			14/11/2026
 * @see					logs.h
 * @brief				Implémentation des fonctionnalités liées aux logs.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdio.h>
#include <stdint.h>

#include "stm32g4xx_hal.h"
#include "stm32g4_rtc.h"

/* **************************************************** Private macros *************************************************** */

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */
/**
 * @brief		Permet d'obtenir le temps d'exécution du STM32
 * @return		Retourne une chaîne de caractère sous la forme "[Heures:Minutes:Secondes]"
 */
char* GetUptime(void);

/**
 * @brief		Permet d'obtenir l'heure
 * @return		Retourne une chaîne de caractère sous la forme "[Heures:Minutes:Secondes]"
 */
char* GetTime(void);

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */
char* GetUptime(void)
{
    static char uptime_str[16];

    uint32_t uptime = HAL_GetTick() / 1000;

    uint32_t hours   = uptime / 3600;
    uint32_t minutes = (uptime % 3600) / 60;
    uint32_t seconds = uptime % 60;

    snprintf(uptime_str, sizeof(uptime_str), "[%02u:%02u:%02u]",
             (unsigned int)hours,
             (unsigned int)minutes,
             (unsigned int)seconds);

    return uptime_str;
}

char* GetTime(void)
{
    static char time_str[16];

    RTC_TimeTypeDef time;
    RTC_DateTypeDef date;

    BSP_RTC_get_time_and_date(&time, &date);

    snprintf(time_str, sizeof(time_str),
             "[%02u:%02u:%02u]",
			 (unsigned int)time.Hours,
			 (unsigned int)time.Minutes,
			 (unsigned int)time.Seconds);

    return time_str;
}

/* ********************************************** Public functions definitions ******************************************* */
void LOGS_info(const char *module, const char *message)
{
	printf("[INFO] [%s] -- %s -- %s -- %s", module, GetTime(), GetUptime(), message);
}

void LOGS_warning(const char *module, const char *message)
{
	printf("[WARNING] [%s] -- %s -- %s -- %s", module, GetTime(), GetUptime(), message);
}

void LOGS_error(const char *module, const char *message)
{
	printf("[ERROR] [%s] -- %s -- %s -- %s", module, GetTime(), GetUptime(), message);
}
