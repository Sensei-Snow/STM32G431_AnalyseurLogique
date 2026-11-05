/**
 *******************************************************************************
 * @file 				display.h
 * @author 				Arthur Retaillaud
 * @creation_date 		05/11/2026
 * @update_date			05/11/2026
 * @see					display.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées à l'écran.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Initialisation de l'écran au niveau des GPIO et de l'orientation et allumage de celui-ci
 */
void DISPLAY_init(void);
