#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char caesar(char user_char, int key);

int main(int argc, string argv[]){
    bool key_successful = false;
    string text = "";
    int leight_text = 0;
    string key = "";
    int leight_key = 0;
    int key_count = 0;
    
    do{
        if(argc!=2){
        printf("ERROR 1\n");
        return 1;
        }
        else if(argv[1]){
            leight_key = strlen(argv[1]);
            for(int i = 0; i<leight_key; i++){
                if(!isalpha(argv[1][i])){
                    printf("ERROR 2\n");
                    return 1;
                }
                else{
                    key = argv[1];
                    key_successful = true;
                }
            }
        }    
    }while(!key_successful);
    
    printf("plaintext: ");
    text = GetString();
    
    leight_text = strlen(text);
    
    int array_key[strlen(key)];
    
    for(int i = 0; i<strlen(key); i++){
        array_key[i] = toupper(key[i])-65;
    }
    
    printf("ciphertext: ");
    
    for(int i = 0; i<leight_text; i++){
        if(!isalpha(text[i])){
            printf("%c", text[i]);
        }
        else{
            printf("%c", caesar(text[i], array_key[key_count]));
            if(leight_key - 1>key_count){
                key_count++;
            }
            else{
                key_count=0;
            }
                
        }
        
    }
    printf("\n");

}

char caesar (char user_char, int key){
    if (islower(user_char)){
        return ((user_char - 97 + key)%26 + 97);
    }
    else{
        return ((user_char - 65 + key)%26 + 65);
    }
}