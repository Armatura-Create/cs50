#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void){
    
    string full_name = GetString();
    
    printf("%c", toupper(full_name[0]));
    
    for( int i = 0; strlen(full_name)>i; i++){
        
        if(full_name[i] == ' ' && full_name[i+1] != '\0'){
            printf("%c", toupper(full_name[i+1]));
            i++;
        }
        
    }
    printf("\n");
}