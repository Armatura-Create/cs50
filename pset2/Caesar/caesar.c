#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[]){
    
    if(argc < 2 || atoi(argv[0]) < 0 || atoi(argv[1]) < 0){
        printf("enter a single command-line arg: non-negative integer.\n");
        return 1;
    }
    
    int key = 0;
    
    key = atoi(argv[1]);
    
    printf("plaintext: ");
    string code = GetString();
    
    printf("ciphertext: ");
    for(int i =0; strlen(code)>i; i++){
        
        if (isupper(code[i]) && isalpha(code[i])){
            code[i] = (code[i] - 'A' + key) % 26 + 65;
        }
        
        if (islower(code[i]) && isalpha(code[i])){
            code[i] = (code[i] - 'a' + key) % 26 + 97;
        }
        printf("%c", code[i]);
    }
    printf("\n");
    return 0;
}