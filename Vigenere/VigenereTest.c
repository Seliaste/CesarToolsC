#include "Vigenere.h"

void testVigener()
{
    printf("B + a = %c\n", vigener_char('B', 'a', false));
    printf("o + b = %c\n", vigener_char('o', 'b', false));
    printf("n + c = %c\n", vigener_char('n', 'c', false));
    printf("u + f = %c\n", vigener_char('u', 'e', false));
    printf("u + f = %c\n", vigener_char('u', 'f', false));
    printf("Bonjour Madame + abc = %s\n", chiffrer_vigener("Bonjour Madame", "abc"));
    printf("Aitcb - h = %s\n", dechiffrer_vigener("Aitcb", "h"));
}

int main(int argc, char const *argv[])
{
    testVigener();
    return 0;
}
