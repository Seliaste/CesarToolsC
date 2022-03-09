#include "Espion.h"

void testEspion(){
    printf("Iwtivpyixxi = %s\n", casser_cesar("Iwtivpyixxi"));
    char* texte_long = lecture("exemple1_chiffre_cesar.txt");
    printf("%s\n",casser_cesar(texte_long));
}

int main(int argc, char const *argv[])
{
    testEspion();
    return 0;
}
