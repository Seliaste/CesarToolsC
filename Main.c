#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionsDeBase/fonctionsDeBase.c"
#include "Espion/Espion.c"
#include "Cesar/Cesar.c"
#include "Vigenere/Vigenere.c"
int main(int argc, char *argv[])
{
    if (strcmp("-c", argv[1])==0)
    {
        if (taille(argv[3]) == 1)
        {
            printf("%s",chiffrementCesar(lecture(argv[2]), argv[3][0]));
        }
        if (taille(argv[3]) > 1)
        {
            printf("%s",chiffrer_vigener(lecture(argv[2]), argv[3]));
        }
        else
        {
            EXIT_FAILURE;
        }
    }
    else if (strcmp("-d", argv[1])==0)
    {
        if (taille(argv[3]) == 1)
        {
            printf("%s",dechiffrementCesar(lecture(argv[2]), argv[3][0]));
        }
        if (taille(argv[3]) > 1)
        {
           printf("%s",dechiffrer_vigener(lecture(argv[2]), argv[3]));
        }
        else
        {
            EXIT_FAILURE;
        }
    }
    else
    {
        printf("%s\n\n\n\n",casser_cesar(lecture(argv[1])));
        printf("%s",casser_vigenere_avec_clef(lecture(argv[1]),3));
    }
}