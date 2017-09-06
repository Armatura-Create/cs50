#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"

#define SIZE 1000000
#define LEN_WORD 46
#define LEN_TREE 26

typedef struct tree{
    char
}
tree;

int dictionarySize = 0;

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if(file == NULL){
        return false;
    }
    
    
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    char temp[46];
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        temp[i] = tolower(word[i]);
    }
    temp[len] = '\0';
    
    int index = hashFunction(temp);
    
    if(hashTable[index] == NULL){
        return false;
    }
    
    node* cursor = hashTable[index];
    
    while(cursor != NULL){
        if(strcmp(temp, cursor->word) == 0){
            return true;
        }
        cursor = cursor -> next;
    }
    
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(dictionarySize > 0){
        return dictionarySize;
    }
    else{
        return 0;
    }
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    int index = 0;
    
    while(index < SIZE){
        if(hashTable[index] == NULL){
            index++;
        }
        else{
            while(hashTable[index] != NULL){
                node* cursor = hashTable[index];
                hashTable[index] = cursor -> next;
                free(cursor);
            }
            index++;
        }
        
    }
    return true;
}