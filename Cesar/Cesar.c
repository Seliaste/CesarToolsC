#include <stdio.h>
#include <stdlib.h>
//#include "fonctionsDeBase.h"

char* chiffrementCesar(char* message, char clef){
    int cle = (int)clef;
    char* message_code;
    printf("%c",cle);
    if (65>=cle && cle<=90){
        cle = cle-64;
        char* message_code = malloc(sizeof(message));
        while (message[i]!='\0'){
        if ((char)((int)message[i]+cle)){
                message_code[i]=((char)((int)message[i]+cle))%64;
            }
            else{
            message_code[i]=(char)((int)message[i]+cle);
            }
        ++i;
    }
    }
    if (cle>=97 && cle<=122){
        cle = cle-96;
        char* message_code = malloc(sizeof(message));
        while (message[i]!='\0'){
            if ((char)((int)message[i]+cle)){
                message_code[i]=((char)((int)message[i]+cle))%96;
            }
            else{
            message_code[i]=(char)((int)message[i]+cle);
            }
        ++i;
    }
    }
    else{
        return "Erreur de clé";
        
    }
    return message_code;
}
int main(int argc,char* argv[]){
printf("%s",chiffrementCesar("ABC",'F'));
}