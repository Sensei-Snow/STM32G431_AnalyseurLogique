/**
 *******************************************************************************
 * @file 				program.h
 * @author 				Arthur Retaillaud
 * @creation_date 		15/11/2026
 * @update_date			19/11/2026
 * @see					program.c
 * @brief				Fichier d'en-tête pour l'implémentation des fonctionnalités liées au programme principal.
 *******************************************************************************
*/

#pragma once

/* ******************************************************* Includes ****************************************************** */
#include <stdint.h>

#include "../utils/state_machine/state_machine.h"
#include "../utils/utils.h"

/* ***************************************************** Public macros *************************************************** */

/* ************************************************** Public types definition ******************************************** */
/**
 * @brief		Énumération de tout les états possibles de la machine à états du programme principale
 */
typedef enum
{
    STATE_INIT,
    STATE_STARTSCREEN,
    STATE_HOMESCREEN_INITIAL,
    STATE_HOMESCREEN_MENU,
	STATE_INFOSCREEN,
	STATE_DONE,
	STATE_WARNING,
    STATE_ERROR

} ProgramState_t;

/**
 * @brief		Structure contenant les variables nécéssaires par la machine à états du programme principal
 */
typedef struct
{
    StateMachine_t program_sm;

} Program_t;

/* *********************************************** Public functions declarations ***************************************** */
/**
 * @brief		Initialisation de la machine à états du programme principal
 * @param		program : Pointeur vers lastructure avec toutes les variables nécéssaires par la machine à états du programme principal
 * @param		now_ms : Temps en milisecondes
 * @return		EXECUTION_OK si la machine à états du programme principal s'est initialisée et EXECUTION_ERROR si la machine à états du programme principal n'a pas été créée
 */
Execution_State Program_Init(Program_t *program, uint32_t now_ms);

/**
 * @brief		Mise à jour de la machine à états du programme principal
 * @param		program : Pointeur vers lastructure avec toutes les variables nécéssaires par la machine à états du programme principal
 * @param		now_ms : Temps en milisecondes
 * @return		EXECUTION_OK si le prochain état peut être changé ou EXECUTION_ERROR si la machine à états du programme principal n'a pas été créée ou le prochain état est le même que celui actuel
 */
Execution_State Program_Update(Program_t *program, uint32_t now_ms);
