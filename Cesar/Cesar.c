#include "Cesar.h"

char *chiffrementCesar(char *message, char clef)
{
    switch (estChiffrable(clef))
    {
    case 1:               // minuscule
        clef = clef - 96; // la clef correspond au code ascii du caractère - 96 (97 etant a minuscule)
        break;
    case 2:               // majuscule
        clef = clef - 64; // idem pour les majuscules
        break;
    default:
        fprintf(stderr, "Erreur: Clef incorrecte\n");
        exit(EXIT_FAILURE);
    }

    char *message_code = calloc(sizeof(char), taille(message) + 1); // pour definir la mémoire du message codé
    for (int i = 0; i < taille(message); i++)
    {
        char cara = message[i];
        switch (estChiffrable(cara))
        {
        case 1:
            message_code[i] = (cara - 97 + clef) % 26 + 97; // applique la clef a chaque caractère du message (pour les minuscules)
            break;
        case 2:
            message_code[i] = (cara - 65 + clef) % 26 + 65; // idem pour les majuscules
            break;
        default:
            message_code[i] = cara; // si le caractère n'est pas chiffrable, on écrit le caractère sans le chiffrer
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

    char *message_code = calloc(sizeof(char), taille(message) + 1);
    for (int i = 0; i < taille(message); i++)
    {
        int cara = message[i];
        int indice;
        switch (estChiffrable(cara))
        {
        case 1: // si minuscule
            indice = (cara - 97 + ajustement) % 26; 
            if (indice < 0) //si on descend trop bas
            {
                indice += 26; 
            }
            message_code[i] = indice + 97;
            break;
        case 2: // si majuscule
            indice = (cara - 65 + ajustement) % 26;
            if (indice < 0)
            {
                indice += 26;
            }
            message_code[i] = indice + 65;
            break;
        default: //si on ne peut pas chiffrer
            message_code[i] = cara; //écrit le caractère en clair
            break;
        }
    }
    return message_code;
}
