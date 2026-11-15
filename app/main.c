/**
 *******************************************************************************
 * @file 				main.c
 * @author 				Arthur Retaillaud
 * @creation_date 		18/10/2026
 * @update_date			14/11/2026
 * @brief				Fichier principal de code de notre projet sur carte Nucléo STM32G431KB.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdbool.h>
#include <stdio.h>

#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_sys.h"
#include "stm32g4_rtc.h"
#include "config.h"
#include "utils/utils.h"
#include "utils/logs/logs.h"
#include "utils/rtc/rtc.h"

/* **************************************************** Private macros *************************************************** */
#define CONFIGURATION_DATETIME		1
#define MODULE_NAME					"MAIN"

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */
int main(void)
{
	//-- Initializations -----------------------------------
	LOGS_info(MODULE_NAME, "Starting configuration");

	LOGS_info(MODULE_NAME, "Initializing HAL");
	HAL_Init();

	LOGS_info(MODULE_NAME, "Enabling GPIO");
	BSP_GPIO_enable();

	LOGS_info(MODULE_NAME, "Initializing UART");
	BSP_UART_init(UART2_ID,115200);

	LOGS_info(MODULE_NAME, "Initializing USART");
	BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	#if CONFIGURATION_DATETIME
		LOGS_info(MODULE_NAME, "Configuration RTC date/time enabled");
		RTC_TimeTypeDef time = {
				.Hours = 14,
				.Minutes = 30,
				.Seconds = 0
			};

		RTC_DateTypeDef date = {
		        .WeekDay = FRIDAY,
		        .Month = NOVEMBER,
		        .Date = 13,
		        .Year = 26
		    };

		LOGS_info(MODULE_NAME, "Initializing RTC and set date/time");
		RTC_Init_SetDateTime(time, date);
	#endif
	LOGS_info(MODULE_NAME, "Configuration finished");

	//-- Execution -----------------------------------
	LOGS_info(MODULE_NAME, "Starting execution");
	while(true) {
		//TODO
	}

	LOGS_info(MODULE_NAME, "Execution finished");

	return 0;
}

/* ********************************************** Public functions definitions ******************************************* */
