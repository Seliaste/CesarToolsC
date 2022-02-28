#include "fonctionsDeBase.h"
#include <stdio.h>

void printTab(int* tab){
    printf("[ ");
    for(int i = 0; i < 26; i++){
        printf("%d ",tab[i]);
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    printf("taille de bjr = %d\n",taille("bjr"));
    printf("a est %d, Z est %d, é est %d\n",estChiffrable('a'),estChiffrable('Z'),estChiffrable('-'));
    printTab(tableau_frequence("JE GROGNE GRRRRRRRRRrrrrrR"));

    return 0;
}