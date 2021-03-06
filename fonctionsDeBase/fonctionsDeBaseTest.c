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
    int *tabfreq = tableau_frequence("JE GROGNE GRRRRRRRRRrrrrrR");
    printTab(tabfreq);
    free(tabfreq);
    char* data = lecture("testData.txt");
    printf("fichier : %s\n", data);
    free(data);
    return 0;
}