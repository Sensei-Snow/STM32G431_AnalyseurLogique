/**
 *******************************************************************************
 * @file 				utils.h
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			11/11/2026
 * @brief				Fichier d'en-tête pour l'implémentation de fonctionnalités utiles et fort sympathiques.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */
/**
 * @brief		Énumération des états d'exécution possibles d'une fonction
 */
typedef enum {
	EXECUTION_OK,
	EXECUTION_PROGRESS,
	EXECUTION_WARNING,
	EXECUTION_ERROR
}Execution_State;

/**
 * @brief		Énumération des protocoles disponibles
 */
typedef enum {
	UART,
	I2C,
	SPI
}Protocol;

/**
 * @brief		Énumération des signaux physiques du protocole UART
 */
typedef enum {
	RX,
	TX
}UART_Signal;

/**
 * @brief		Énumération des signaux physiques du protocole I2C
 */
typedef enum {
	SDA,
	SCL
}I2C_Signal;

/**
 * @brief		Énumération des signaux physiques du protocole SPI
 */
typedef enum {
	SCLK,
	MISO,
	MOSI,
	CS
}SPI_Signal;

/* *********************************************** Public functions declarations ***************************************** */
