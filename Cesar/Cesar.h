#include <stdio.h>
#include <stdlib.h>
#include "../fonctionsDeBase/fonctionsDeBase.h"

/**
 * @brief Chiffre message avec clef décalage
 * 
 * @param message 
 * @param clef 
 * @return char* 
 */
char *chiffrementCesar(char *message, char clef);

/**
 * @brief Dechiffre message avec clef décalage
 * 
 * @param message 
 * @param clef 
 * @return char* 
 */
char *dechiffrementCesar(char *message, char clef);