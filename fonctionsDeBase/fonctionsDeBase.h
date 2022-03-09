/**
 * @file fonctionsDeBase.h
 * @author Aéna ARIA (aena.aria2@etu.univ-lorraine.fr)
 * @brief Fonctions de base pour le TP3
 * @date 2022-02-28
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * @brief Renvoie la taille de texte
 * 
 * @param texte 
 * @return int 
 */
int taille(char *texte);

/**
 * @brief retourne 1 si c'est une lettre non accentuée minuscule, 2 majuscule, et 0 sinon
 * 
 * @param cara 
 * @return int 
 */
int estChiffrable(char cara);

/**
 * @brief Renvoie un tableau de taille 26 de la fréquence des lettres dans texte
 * 
 * @param texte 
 * @return int* 
 */
int *tableau_frequence(char *texte);

/**
 * @brief Prend le chemin relatif d'un fichier texte et renvoie son texte
 * 
 * @param nomFichier 
 * @return char* 
 */
char *lecture(char *nomFichier);
