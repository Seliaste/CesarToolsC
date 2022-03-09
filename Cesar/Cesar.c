#include "Cesar.h"

char *chiffrementCesar(char *message, char clef)
{
    switch (estChiffrable(clef))
    {
    case 1:
        clef = clef - 96;
        break;
    case 2:
        clef = clef - 64;
        break;
    default:
        fprintf(stderr, "Erreur: Clef incorrecte\n");
        exit(EXIT_FAILURE);
    }

    char *message_code = malloc(taille(message) * sizeof(char));
    for (int i = 0; i < taille(message); i++)
    {
        char cara = message[i];
        switch (estChiffrable(cara))
        {
        case 1:
            message_code[i] = (cara - 97 + clef) % 26 + 97;
            break;
        case 2:
            message_code[i] = (cara - 65 + clef) % 26 + 65;
            break;
        default:
            message_code[i] = cara;
            break;
        }
    }
    return message_code;
}

char *dechiffrementCesar(char *message, char clef)
{
    int ajustement;
    switch (estChiffrable(clef))
    {
    case 1:
        ajustement = -clef + 96;
        break;
    case 2:
        ajustement = -clef + 64;
        break;
    default:
        fprintf(stderr, "Erreur: Clef incorrecte\n");
        exit(EXIT_FAILURE);
    }

    char *message_code = malloc(taille(message) * sizeof(char));
    for (int i = 0; i < taille(message); i++)
    {
        int cara = message[i];
        int indice;
        switch (estChiffrable(cara))
        {
        case 1:
            indice = (cara - 97 + ajustement) % 26;
            if (indice < 0)
            {
                indice += 26;
            }
            message_code[i] = indice + 97;
            break;
        case 2:
            indice = (cara - 65 + ajustement) % 26;
            if (indice < 0)
            {
                indice += 26;
            }
            message_code[i] = indice + 65;
            break;
        default:
            message_code[i] = cara;
            break;
        }
    }
    return message_code;
}
