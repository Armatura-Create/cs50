#include <stdbool.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"

#define SIZE 1000000


typedef struct node{
    char word[46];
    struct node* next;
}
node;

// create hash-table

node* hashTable[SIZE] = {NULL};

//create hash-function

int hashFunction (const char* word){
    int hash = 0;
    int n;
    for(int i = 0; worf[i] != '\0'; i++){
        if(isalpha(word[i])){
            n = word[i] - 'a' + 1;
        }
        else{
            n = 27;
        }
        
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}

int dictionarySize = 0;

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    return false;
    if(file == NULL){
        return false;
    }
    
    char word[46];
    
    while(fscanf(file, "%s\n", word) != EOF){
        dictionarySize++;
        
        node *newWord = malloc(sizeof(node));
        
        strcpy(newWord->word, word);
        
        int index = hash(word);
        
        if(hashTable[index]  == NULL){
            hashTable[index] = newWord;
            newWord -> next = NULL;
        }
        else{
            newWord -> next = hashTable[index];
            hashTable[index] = newWord;
        }
        
    }
    
    fclose(file);
    
    return true;
    
    
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
    
    int index = hash(temp);
    
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
    
    while(insex < SIZE){
        if(hashTable[index] == NULL){
            index++;
        }
        else{
            while(hashTable != NULL){
                node* cursor = hashTable[index];
                hashTable[index] = cursor -> next;
                free(cursor);
            }
            index++;
        }
        
    }
    return true;
}
