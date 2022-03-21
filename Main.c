/**
 * @file Main.c
 * @author WIECZOREK Thomas
 * @brief main avec définition des commandes
 * @date 2022-03-10
 */
#include <stdlib.h>
#include <string.h>
#include "fonctionsDeBase/fonctionsDeBase.h"
#include "Espion/Espion.h"
#include "Cesar/Cesar.h"
#include "Vigenere/Vigenere.h"
int main(int argc, char *argv[])
{
    if (argc <= 1) // message d'erreur si il n'y a pas d'argument
    {
        printf("Syntaxe incorrecte.\nUsage :\nmain -c <nomFichier> <clef> : code le fichier\nmain -d <nomFichier> <clef> : décode le fichier\n main <nomFichier> : casse le chiffrage en césar puis en vigénère.\n");
        exit(EXIT_SUCCESS);
    }
    if (strcmp("-c", argv[1]) == 0) // regarde si le premier argument est "-c" et si c'est le cas on utilise une fonction de chiffrement
    {
        if (taille(argv[3]) == 1)
        {
            char *affichage = chiffrementCesar(lecture(argv[2]), argv[3][0]);
            printf("%s", affichage); // chiffre en césar si la clé est un caractère
            free(affichage);
        }
        if (taille(argv[3]) > 1)
        {
            char *affichage = chiffrer_vigener(lecture(argv[2]), argv[3]);
            printf("%s", ); // chiffre en vigenere si la clé est une chaîne de caractères
            free(affichage);
        }
        else
        {
            EXIT_FAILURE;
        }
    }
    else if (strcmp("-d", argv[1]) == 0) // si le premier argument est "-d" on utilise une fonction de dechiffrement
    {
        if (taille(argv[3]) == 1)
        {
            char *affichage = dechiffrementCesar(lecture(argv[2]), argv[3][0]);
            printf("%s", affichage);
            free(affichage);
        }
        if (taille(argv[3]) > 1)
        {
            char *affichage dechiffrer_vigener(lecture(argv[2]), argv[3]);
            printf("%s", affichage);
            free(affichage);
        }
        else
        {
            EXIT_FAILURE;
        }
    }
    else
    {
        // sinon on essaye de casser le chiffrement sans clé en césar et en vigenere
        char *affichage = casser_cesar(lecture(argv[1]));
        printf("%s\n\n\n\n", affichage);
        free(affichage);
        char *affichage = casser_vigenere_avec_clef(lecture(argv[1]), 3);
        printf("%s", affichage);
        free(affichage);
    }
}