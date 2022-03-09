/**
 * @file Vigenere.h
 * @author Aéna ARIA (aena.aria2@etu.univ-lorraine.fr)
 * @brief Header du module pour chiffrer en code vigénere
 * @date 2022-03-09
 */

#include "../fonctionsDeBase/fonctionsDeBase.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Chiffre message à l'aide de clef
 * 
 * @param message 
 * @param clef 
 * @return char* 
 */
char *chiffrer_vigener(char *message, char *clef);

/**
 * @brief Déchiffre message avec clef
 * 
 * @param message 
 * @param clef 
 * @return char* 
 */
char *dechiffrer_vigener(char *message, char *clef);

/**
 * @brief Permet de chiffrer ou de déchiffrer un vigener
 * 
 * @param cara 
 * @param clef 
 * @param dechiffrer 
 * @return char 
 */
char vigener_char(char cara, char clef, bool dechiffrer);