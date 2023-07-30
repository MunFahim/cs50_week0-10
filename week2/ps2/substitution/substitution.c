#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char alp[26] = {'A', 'B', 'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


bool checkLen(char str[]){
    bool len = false;
    for(int i = 0; i < 26; i++){
        if ((int)str[i] == 0){
            printf("Key must contain 26 characters.\n");
            return false;
        }
        if (((int)str[i] > 64 && (int)str[i] < 91) || ((int)str[i] > 96 && (int)str[i] < 123)){

        }else return false;
        for(int j = 0; j < 26;j++){
            if (i != j && str[j] == str[i]){
                return false;
            }
        }
    }
    return true;
}



char* getText(void){

    string text = get_string("plaintext: ");
    char* cText = text;
    return cText;
}

void cipher(char key[], char text[]){
    for(int i = 0; i < strlen(text); i++){
        char letter = tolower(text[i]);
        int found;
        for(int j = 0; j < 26; j++){
            if(letter == tolower(alp[j])){
                found = j;
                if (islower(text[i])){
                    text[i] = tolower(key[found]);
                }else text[i] = toupper(key[found]);

            }
        }
    }
    printf("ciphertext: %s\n", text);
}


int main(int argc, string argv[])
{

    char* theKey = " ";
    if (argc == 2){
        bool checker = checkLen(argv[1]);
        if(checker){
            theKey = argv[1];
        }else return 1;
    }else {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char* plain = getText();
    cipher(theKey, plain);
    return 0;
}