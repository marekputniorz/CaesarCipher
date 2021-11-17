#include <stdio.h>
#include <stdlib.h>
 

//Funkce pro césarovu šifru
void cipher (char* text, int key) {
    
    int i = 0;
    char character;

    //Procházení znaku v souboru
    for (i = 0; text[i] != '\0'; i++) {
        character = text[i];
        //aplikace klíče pro malá písmena
        if (character >= 'a' && character <= 'z') {
            character = character + key;
            //Zakódování
            if (character > 'z') {
                character = character - 'z' + 'a' - 1;
            }
            //Dekódování 
            if (character < 'a') {
                character = character + 'z' - 'a' + 1;
            }
            text[i] = character;
        }
        //aplikace klíče pro velké písmena
        else if (character >= 'A' && character <= 'Z') {
            character = character + key;
            //Zakódování
            if (character > 'Z') {
                character = character - 'Z' + 'A' - 1;
            }
            //Dekódování
            if (character < 'A') {
                character = character + 'Z' - 'A' + 1;
            }
            text[i] = character;
        }
    }
    //Výpis zakódovaného řetězce
    printf("%s", text);
}

int main(int argc, char* argv[]) {
    
    char text[500];
    int key = 3;
    FILE* file = fopen(argv[1], "r");
    
    if (argc == 3) {
        key = atoi(argv[1]);
        file = fopen(argv[2], "r");
    }

    //Čtení řetězců ze souboru
    fgets(text, sizeof(text), file);
    //Volání funkce
    cipher(text, key);
    
    return 0;
}