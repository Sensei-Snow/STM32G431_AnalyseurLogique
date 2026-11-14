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
 * @param		time : structure contenant les heures, les minutes et les secondes
 * @param		date : structure contenant le jour, le jour de la semaine, le mois et l'année
 */
void RTC_Init_SetDateTime(RTC_TimeTypeDef time, RTC_DateTypeDef date);
