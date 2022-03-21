/**
 * @file Cesar.h
 * @author WIECZOREK Thomas
 * @brief  module de chiffrement cesar
 * @date 2022-03-15
 */
#include <stdio.h>
#include <stdlib.h>
#include "../fonctionsDeBase/fonctionsDeBase.h"

/**
 * @brief Chiffre message avec une clef de décalage
 * 
 * @param message 
 * @param clef 
 * @return char* 
 */
char *chiffrementCesar(char *message, char clef);

/**
 * @brief Dechiffre message avec une clef de décalage
 * 
 * @param message 
 * @param clef 
 * @return char* 
 */
char *dechiffrementCesar(char *message, char clef);