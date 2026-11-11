/**
 *******************************************************************************
 * @file 				main.c
 * @author 				Arthur Retaillaud
 * @creation_date 		18/10/2026
 * @update_date			11/11/2026
 * @brief				Fichier principal de code de notre projet sur carte Nucléo STM32G431KB.
 *******************************************************************************
*/

/* ******************************************************* Includes ****************************************************** */
#include <stdbool.h>
#include <stdio.h>

#include "stm32g4_gpio.h"
#include "stm32g4_uart.h"
#include "stm32g4_sys.h"
#include "config.h"
#include "utils/utils.h"
#include "utils/logs/logs.h"

/* **************************************************** Private macros *************************************************** */

/* ************************************************ Private type definition ********************************************** */

/* ********************************************* Private functions declarations ****************************************** */

/* ************************************************** Private variables ************************************************** */

/* ********************************************** Private functions definitions ****************************************** */
Execution_State main(void)
{
	//-- Initializations -----------------------------------
	HAL_Init();
	BSP_GPIO_enable();
	BSP_UART_init(UART2_ID,115200);
	BSP_SYS_set_std_usart(UART2_ID, UART2_ID, UART2_ID);

	while(true) {
		//TODO
	}

	return STATE_OK;
}

/* ********************************************** Public functions definitions ******************************************* */
