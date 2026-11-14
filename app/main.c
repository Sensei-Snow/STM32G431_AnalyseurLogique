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

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */
int main(void)
{
	//-- Initializations -----------------------------------
	HAL_Init();
	BSP_GPIO_enable();
	BSP_UART_init(UART2_ID,115200);
	BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	#if CONFIGURATION_DATETIME
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

		RTC_Init_SetDateTime(time, date);
	#endif

	//-- Execution -----------------------------------
	while(true) {
		//TODO
	}

	return 0;
}

/* ********************************************** Public functions definitions ******************************************* */
