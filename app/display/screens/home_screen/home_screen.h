/**
 *******************************************************************************
 * @file 				home_screen.h
 * @author 				Arthur Retaillaud
 * @creation_date 		17/11/2026
 * @update_date			17/11/2026
 * @see					home_screen.h
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées à l'écran d'accueil.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Affiche l'écran d'accueil
 */
void draw_home_screen_initial(void);

/***
 * @brief		Affiche l'écran d'accueil avec un message d'erreur indiquant que les paramètres sont incomplets
 */
void draw_home_screen_incomplete_settings(void)

/**
 * @brief		Affiche le menu de l'écran d'accueil
 */
void draw_home_screen_menu(void);
