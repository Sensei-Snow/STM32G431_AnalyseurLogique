/**
 *******************************************************************************
 * @file 				logs.h
 * @author 				Arthur Retaillaud
 * @creation_date 		11/11/2026
 * @update_date			11/11/2026
 * @see					logs.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées aux logs.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Affiche un log d'information en console
 * @param		message : chaîne de caractère du message d'information
 */
void LOGS_info(const char *message);

/**
 * @brief		Affiche un log d'avertissement en console
 * @param		message : chaîne de caractère du message d'avertissement
 */
void LOGS_warning(const char *message);

/**
 * @brief		Affiche un log d'erreur en console
 * @param		message : chaîne de caractère du message d'erreur
 */
void LOGS_error(const char *message);
