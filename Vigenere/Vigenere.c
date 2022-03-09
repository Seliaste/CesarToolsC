#include "Vigenere.h"

char *chiffrer_vigener(char *message, char *clef)
{
    int size = taille(message);
    int sizeclef = taille(clef);
    char *res = malloc(size * sizeof(char));
    for (int i = 0; i < size; i++)
    {
        res[i] = vigener_char(message[i], clef[i % sizeclef], false);
    }
    return res;
}

char *dechiffrer_vigener(char *message, char *clef)
{
    int size = taille(message);
    int sizeclef = taille(clef);
    char *res = malloc(size * sizeof(char));
    for (int i = 0; i < size; i++)
    {
        res[i] = vigener_char(message[i], clef[i % sizeclef], true);
    }
    return res;
}

char vigener_char(char cara, char clef, bool dechiffrer)
{
    int ajustement = dechiffrer ? -(clef - 96) : (clef - 96); // si on déchiffre, on retire
    switch (estChiffrable(cara))
    {
    case 1:
        return ((cara - 97 + ajustement) % 26) + 97;
    case 2:
        return ((cara - 65 + ajustement) % 26) + 65;
    default:
        return cara;
    }
}