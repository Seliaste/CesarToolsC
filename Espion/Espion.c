#include "Espion.h"

char *casser_cesar(char *texte)
{
    int *tab = tableau_frequence(texte);
    int max = 0;
    char max_char;
    for (int i = 0; i < 26; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
            max_char = i;
        }
    }
    if (max_char + 92 < 97)
    {
        max_char += 26;
    }
    return dechiffrementCesar(texte, max_char + 92);
}

char *casser_vigenere_avec_clef(char *texte, int tailleClef)
{
    char *res = calloc(taille(texte), sizeof(char));
    for (int i = 0; i < tailleClef; i++)
    {
        char *subString = calloc(taille(texte), sizeof(char));
        int j;
        for (j = 0; j < taille(texte) / 3; j++)
        {
            subString[j] = texte[i + j * 3];
        }
        char *decodedSubString = casser_cesar(subString);
        for (j = 0; j < taille(texte) / 3; j++)
        {
            res[i + j * 3] = decodedSubString[j];
        }
        free(subString);
    }
    return res;
}