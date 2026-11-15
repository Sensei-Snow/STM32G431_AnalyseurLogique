/**
 *******************************************************************************
 * @file 				rtc.c
 * @author 				Arthur Retaillaud
 * @creation_date 		13/11/2026
 * @update_date			14/11/2026
 * @see					rtc.h
 * @brief				Implémentation des fonctionnalités liées à l'horloge système.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdio.h>

#include "stm32g4_rtc.h"
#include "rtc.h"
#include "../logs/logs.h"

/* **************************************************** Private macros *************************************************** */
#define MODULE_NAME		"RTC"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */

/* ********************************************** Public functions definitions ******************************************* */
void RTC_Init_SetDateTime(RTC_TimeTypeDef time, RTC_DateTypeDef date)
{
	char buffer_logtext_time[100];
	snprintf(buffer_logtext_time, sizeof(buffer_logtext_time), "Setting RTC time : %u:%u:%u", (unsigned int)time.Hours, (unsigned int)time.Minutes, (unsigned int)time.Seconds);
	char buffer_logtext_date[100];
	snprintf(buffer_logtext_date, sizeof(buffer_logtext_date), "Setting RTC date : %u %u %u 20%u", (unsigned int)date.WeekDay, (unsigned int)date.Date, (unsigned int)date.Month, (unsigned int)date.Year);

	LOGS_info(MODULE_NAME, "Initializing RTC");
    BSP_RTC_init();

    LOGS_info(MODULE_NAME, buffer_logtext_time);
    BSP_RTC_set_time(&time);

    LOGS_info(MODULE_NAME, buffer_logtext_date);
    BSP_RTC_set_date(&date);
}
