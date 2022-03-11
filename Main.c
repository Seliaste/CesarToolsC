#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionsDeBase/fonctionsDeBase.h"
#include "Espion/Espion.h"
#include "Cesar/Cesar.h"
#include "Vigenere/Vigenere.h"
int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Syntaxe incorrecte.\nUsage :\nmain -c <nomFichier> <clef> : code le fichier\nmain -d <nomFichier> <clef> : décode le fichier\n main <nomFichier> : casse le chiffrage en césar puis en vigénère.\n");
        exit(EXIT_SUCCESS);
    }
    if (strcmp("-c", argv[1]) == 0)
    {
        if (taille(argv[3]) == 1)
        {
            printf("%s", chiffrementCesar(lecture(argv[2]), argv[3][0]));
        }
        if (taille(argv[3]) > 1)
        {
            printf("%s", chiffrer_vigener(lecture(argv[2]), argv[3]));
        }
        else
        {
            EXIT_FAILURE;
        }
    }
    else if (strcmp("-d", argv[1]) == 0)
    {
        if (taille(argv[3]) == 1)
        {
            printf("%s", dechiffrementCesar(lecture(argv[2]), argv[3][0]));
        }
        if (taille(argv[3]) > 1)
        {
            printf("%s", dechiffrer_vigener(lecture(argv[2]), argv[3]));
        }
        else
        {
            EXIT_FAILURE;
        }
    }
    else
    {
        printf("%s\n\n\n\n", casser_cesar(lecture(argv[1])));
        printf("%s", casser_vigenere_avec_clef(lecture(argv[1]), 3));
    }
}