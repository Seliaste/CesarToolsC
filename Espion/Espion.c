#include "Espion.h"

char *casser_cesar(char *texte)
{
    int *tab = tableau_frequence(texte);
    int max = 0;
    char max_char;
    for (int i = 0; i < 26; i++) // recherche du caractère le plus commun
    {
        if (tab[i] > max)
        {
            max = tab[i];
            max_char = i;
        }
    }
    // les +92 proviennent du décalage entre le a et le e, la lettre la plus commune (97-5=92)
    if (max_char + 92 < 97) // si on est trop bas (en dehors de l'alphabet)
    {
        max_char += 26; // on remet par dessus
    }
    free(tab);
    return dechiffrementCesar(texte, max_char + 92); // cassage avec la clé devinée
}

char *casser_vigenere_avec_clef(char *texte, int tailleClef)
{
    char *res = calloc(taille(texte), sizeof(char)); // calloc pour renvoi
    for (int i = 0; i < tailleClef; i++)             // découpage en sous-strings
    {
        char *subString = calloc(taille(texte), sizeof(char)); // création du sous-string
        int j;
        for (j = 0; j < taille(texte) / 3; j++)
        {
            subString[j] = texte[i + j * 3]; // on récupère les caractères 3 par 3
        }
        char *decodedSubString = casser_cesar(subString); // on casse le sous-message
        for (j = 0; j < taille(texte) / 3; j++)
        {
            res[i + j * 3] = decodedSubString[j]; // on recopie le sous-message dans le res final
        }
        free(subString);
        free(decodedSubString);
    }
    return res;
}