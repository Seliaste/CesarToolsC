#include "Vigenere.h"

char *chiffrer_vigener(char *message, char *clef)
{
    int size = taille(message);
    int sizeclef = taille(clef);
    char *res = malloc(size * sizeof(char)); // malloc pour return
    for (int i = 0; i < size; i++)
    {
        res[i] = vigener_char(message[i], clef[i % sizeclef], false); // codage caractère par caractère
    }
    return res;
}

/* Si ça ne tenait qu'à moi, 
j'aurais fait le chiffrage et le déchiffrage dans une seule fonction.
Mais vu que le tp le demandait, j'en ai fais deux malgrès leur similarité.
*/
char *dechiffrer_vigener(char *message, char *clef)
{
    int size = taille(message);
    int sizeclef = taille(clef);
    char *res = malloc(size * sizeof(char)); // malloc pour return
    for (int i = 0; i < size; i++)
    {
        res[i] = vigener_char(message[i], clef[i % sizeclef], true); // décodage caractère par caractère
    }
    return res;
}

char vigener_char(char cara, char clef, bool dechiffrer)
{
    int ajustement = dechiffrer ? -(clef - 96) : (clef - 96); // si on déchiffre, on retire, sinon on ajoute
    int indice;
    switch (estChiffrable(cara))
    {
    case 1: // minuscule
        indice = (cara - 97 + ajustement) % 26;
        if (indice < 0) // si on est trop descendu (ce qui n'est pas pris en compte par le modulo)
        {
            indice += 26;
        }
        return indice + 97;
    case 2: // majuscule
        indice = (cara - 65 + ajustement) % 26;
        if (indice < 0) // idem que pour les minuscules
        {
            indice += 26;
        }
        return indice + 65;
    default: // pas chiffrable: on renvoie en clair
        return cara;
    }
}