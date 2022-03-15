/**
 * @file Espion.h
 * @author Aéna Aria (aena.aria2@etu.univ-lorraine.fr)
 * @brief Module espion pour casser les encodages
 * @date 2022-03-15
 */

#include <stdio.h>
#include <stdlib.h>
#include "../fonctionsDeBase/fonctionsDeBase.h"
#include "../Cesar/Cesar.h"

/**
 * @brief essaie de casser un texte en français encodé en césar
 * 
 * @param texte 
 * @return char* 
 */
char* casser_cesar(char* texte);

/**
 * @brief essaie de casser un texte en français encodé en vigénère
 * 
 * @param texte 
 * @param tailleClef 
 * @return char* 
 */
char* casser_vigenere_avec_clef(char* texte, int tailleClef);