/**
 *******************************************************************************
 * @file 				rtc.h
 * @author 				Arthur Retaillaud
 * @creation_date 		13/11/2026
 * @update_date			14/11/2026
 * @see					rtc.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées à l'horloge système.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Initialise l'horloge système et définis une date et une heure
 */
void RTC_Init_SetDateTime(RTC_TimeTypeDef time, RTC_DateTypeDef date);
