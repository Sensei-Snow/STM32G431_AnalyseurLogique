# Utilisation de l'intelligence artificielle

---

## 1) Introduction

Ce document présente les modalités d'utilisation de l'intelligence artificielle (IA) dans le cadre du développement de ce projet.

L'intelligence artificielle est utilisée comme un outil d'assistance au développement, à la réflexion et à la documentation. Son utilisation vise à améliorer la productivité, faciliter la résolution de problèmes et accompagner certaines étapes de conception.

Ce document a pour objectif de garantir la transparence concernant les contributions de l'IA au sein du projet.

---

## 2) Outils utilisés

Les outils d'intelligence artificielle qui ont été utilisés dans le cadre de la réalisation de ce projet sont notamment :

| Nom                    | Modèle     | Effort   | Période d'utilisation    | Usage                                                    |
| ---------------------- | ---------- | -------- | ------------------------ | -------------------------------------------------------- |
| Claude                 | Sonnet 5.5 | High     | 11/11/2026 - Aujourd'hui | Génération de code                                       |
| ChatGPT                | GPT-6 Sol  | Medium   | 06/11/2026 - Aujourd'hui | Explication et résolution des bugs                       |
| ChatGPT                | GPT-6 Luna | Medium   | 18/10/2026 - Aujourd'hui | Assistance sur les démarches théoriques de programmation |
| GitHub Copilot Student | Variable   | Variable | 22/11/2026 - Aujourd'hui | Auto-complétions intelligentes dans Visual Studio Code   |

---

## 3) Code intégralement généré par intelligence artificielle

Cette section détaille précisément les parties du code qui ont été intégralement générées par intelligence artificielle

### `utils/logs.c`

| Lignes     | Usage                                    |
| ---------- | ---------------------------------------- |
| 79, 84, 89 | Affichage de logs avec taille adaptative |

### `display/TFTILI9341_driver_v2/TFTILI9341_driver_v2.c`

| Lignes  | Usage                                                                  |
| ------- | ---------------------------------------------------------------------- |
| 60 à 83 | Fonction d'affichage d'une image BMP sur l'écran TFTILI9341 en couleur |

### Fichiers de workflows GitHub

- `.github/workflows/main.yml`
- `.github/workflows/doxygen.yml`

### Fichiers README

- `README.md`
- `doxygen/README_Doxygen.md`

---

## 4) Code écrit avec assistance de l'intelligence artificielle sur les démarches théoriques de programmation

Cette section détaille précisément les parties du code où l'intelligence artificielle a été utilisée pour expliquer certains concepts théoriques de programmation, avec parfois une programmation guidée.

### `utils/logs.c`

| Lignes  | Usage                                                                 |
| ------- | --------------------------------------------------------------------- |
| 44 à 48 | Obtention du temps d'exécution à partir d'une valeur en millisecondes |

### `utils/state_machine/state_machine.h`

| Lignes  | Usage                                            |
| ------- | ------------------------------------------------ |
| 23 à 32 | Définition de la structure d'une machine à états |

### `utils/state_machine/state_machine.c`

| Lignes    | Usage                                                                                     |
| --------- | ----------------------------------------------------------------------------------------- |
| 29 à 45   | Définition de la fonction d'initialisation de la machine à états                          |
| 47 à 68   | Définition de la fonction de changement d'état de la machine à états                      |
| 103 à 112 | Définition de la fonction d'obtention du temps passé dans un état de la machine à états   |
| 114 à 117 | Définition de la fonction de vérification d'un timeout dans un état de la machine à états |
| 119 à 132 | Définition de la fonction de vérification d'un changement d'état de la machine à états    |

### `program/program.h`

| Lignes        | Usage                                             |
| ------------- | ------------------------------------------------- |
| 46 à 48 et 62 | Définition de la structure du programme principal |

### `program/program.c`

| Lignes    | Usage                                                                                                                               |
| --------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| 71 à 95   | OPTIMISATION : Définition d'une fonction pour éviter les répétitions de code pour la définition de certains paramètres du programme |
| 98 à 123  | Définition de la fonction pour initialiser la machine à états du programme principal                                                |
| 126 à 135 | Début de la définition de la fonction de mise à jour de la machine à états du programme principal                                   |

### `display/TFTILI9341_driver_v2/TFTILI9341_driver_v2.c`

| Lignes  | Usage                                                                                        |
| ------- | -------------------------------------------------------------------------------------------- |
| 45 à 58 | Définition de la fonction pour faire un rectangle avec coins arrondis sur l'écran TFTILI9341 |

### `display/screens/settings_screen/settings_screen.c`

| Lignes                | Usage                                                                                                                          |
| --------------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| 78 à 124 et 173 à 217 | OPTIMISATION : Définition de fonctions pour éviter les répétitions de code dans l'affichage des paramètres sur l'écran ILI9341 |
