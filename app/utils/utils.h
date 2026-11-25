/**
 *******************************************************************************
 * @file 				utils.h
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			24/11/2026
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
	NO_PROTOCOL,
	UART,
	I2C,
	SPI
}Protocol;

/**
 * @brief		Énumération de tout les signaux physiques de tout les protocoles disponibles
 */
typedef enum {
	NO_SIGNAL,
	NOT_USED,
	RX,
	TX,
	SDA,
	SCL,
	SCLK,
	MISO,
	MOSI,
	CS
}All_Signal;

/* *********************************************** Public functions declarations ***************************************** */
