#include "Espion.h"

char *casser_cesar(char *texte)
{
    int* tab = tableau_frequence(texte);
    int max = 0;
    char max_char;
    for(int i=0; i < 26; i++){
        if(tab[i]>max){
            max = tab[i];
            max_char = i;
        }
    }
    return dechiffrementCesar(texte,max_char+92);
}