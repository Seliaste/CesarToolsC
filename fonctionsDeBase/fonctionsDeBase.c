#include "fonctionsDeBase.h"

int taille(char *texte)
{
    int i = 0;
    while (texte[i] != '\0') // tant qu'on a pas attent la fin du string
    {
        i++;
    }
    return i;
}

int estChiffrable(char cara)
{
    if (cara >= 97 && cara <= 122) // si c'est minuscule
    {
        return 1;
    }
    if (cara >= 65 && cara <= 90) // si c'est majuscule
    {
        return 2;
    }
    return 0; // aucun des deux = pas chiffrable
}

int *tableau_frequence(char *texte)
{
    int *freq = malloc(sizeof(int) * 26); // malloc pour pouvoir renvoyer le tableau
    for (int j = 0; j < 26; j++)
    {
        freq[j] = 0; // initialisation à 0
    }
    char cara;
    for (int i = 0; i < taille(texte); i++) // pour chaque caractère du texte
    {
        cara = texte[i];
        switch (estChiffrable(cara)) // on utilise estChiffrable pour savoir si c'est une majuscule ou non
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
    FILE *fichier = fopen(nomFichier, "r"); // ouverture du stream
    if (fichier == NULL)
    {
        fprintf(stderr, "Erreur: fichier non accessible\n");
        exit(EXIT_FAILURE);
    }
    struct stat st;
    int code = stat(nomFichier, &st); // récupération de la taille du fichier
    if (code == -1)
    {
        fprintf(stderr, "Erreur: stat n'a pas pu être lancé (êtes vous bien sur un système UNIX?)\n");
        exit(EXIT_FAILURE);
    }
    char *buffr = malloc(st.st_size);                                      // malloc égal à la taille du fichier
    code = fread(buffr, sizeof(char), st.st_size / sizeof(char), fichier); // on lit l'équivalent de la taille en char
    if (code == 0)                                                         // si on a rien récupéré = fonctionnement anormal
    {
        fprintf(stderr, "Erreur: fichier vide ou lecture impossible\n");
        exit(EXIT_FAILURE);
    }
    fclose(fichier);
    return buffr;
}