#include "Espion.h"

void testEspion()
{
    char * petit = casser_cesar("Iwtivpyixxi");
    printf("Iwtivpyixxi = %s\n", petit);
    char *texte_long = lecture("exemple2_chiffre_cesar.txt");
    char *decoded = casser_cesar(texte_long);
    printf("%s\n", decoded);
    free(petit);
    free(decoded);
    free(texte_long);
}

void testCasserVigenere()
{
    char *texte_long = lecture("exemple3_vigenere_clef_taillle_3.txt");
    char *decoded = casser_vigenere_avec_clef(texte_long, 3);
    printf("%s\n", decoded);
    free(decoded);
    free(texte_long);
    
}

int main(int argc, char const *argv[])
{
    testEspion();
    testCasserVigenere();
    return 0;
}
