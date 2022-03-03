#include "fonctionsDeBase.h"

int taille(char *texte)
{
    int i = 0;
    while (texte[i] != '\0')
    {
        i++;
    }
    return i;
}

int estChiffrable(char cara)
{
    if (cara >= 97 && cara <= 122)
    {
        return 1;
    }
    if (cara >= 65 && cara <= 90)
    {
        return 2;
    }
    return 0;
}

int *tableau_frequence(char *texte)
{
    int *freq = malloc(sizeof(int) * 26);
    for (int j = 0; j < 26; j++)
    {
        freq[j] = 0;
    }
    char cara;
    for (int i = 0; i < taille(texte); i++)
    {
        cara = texte[i];
        switch (estChiffrable(cara))
        {
        case 1:
            freq[cara - 97]++;
            break;
        case 2:
            freq[cara - 65]++;
            break;
        }
    }
    return freq;
}

char *lecture(char *nomFichier)
{
    FILE *fichier = fopen(nomFichier, "r");
    if(fichier == NULL){
        printf("Erreur: fichier non accessible");
        exit(EXIT_FAILURE);
    }
    struct stat st;
    int code = stat(nomFichier, &st);
    if(code == -1){
        printf("Erreur: stat n'a pas pu être lancé (êtes vous sur un système UNIX?)");
        exit(EXIT_FAILURE);
    }
    char *buffr = malloc(st.st_size);
    code = fread(buffr, sizeof(char), st.st_size / sizeof(char), fichier);
    if(code == 0){
        printf("Erreur: fichier vide ou lecture impossible\n");
        exit(EXIT_FAILURE);
    }
    fclose(fichier);
    return buffr;
}