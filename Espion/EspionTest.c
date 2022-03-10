#include "Espion.h"

void testEspion()
{
    printf("Iwtivpyixxi = %s\n", casser_cesar("Iwtivpyixxi"));
    char *texte_long = lecture("exemple1_chiffre_cesar.txt");
    printf("%s\n", casser_cesar(texte_long));
}

void testCasserVigenere()
{
    char *texte_long = lecture("exemple3_vigenere_clef_taillle_3.txt");
    printf("%s\n", casser_vigenere_avec_clef(texte_long, 3));
}

int main(int argc, char const *argv[])
{
    testEspion();
    testCasserVigenere();
    return 0;
}
