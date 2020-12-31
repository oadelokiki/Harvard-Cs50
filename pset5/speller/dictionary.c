// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "dictionary.h"

int actcounter = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int v = 0;
    int hash;

    for(int i= 0; word[i] != '\0'; i++)
    {
        v = v + tolower(word[i]);
    }
    hash = v%N;

    node *ptr = table[hash];

    char *currentword;

    while(ptr != NULL)
    {
        int var = strcasecmp(ptr -> word, word);

        if (var==0)
        {
            return true;
        }
        else
        {
            ptr = ptr ->next;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    actcounter++;
    int count = 0;
    for(int i = 0; word[i]!= '\0'; i++)
    {
        count = count + tolower(word[i]);
    }
    return count%N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE*originfile = fopen(dictionary, "r");
    if(!originfile)
    {
        printf("No file loaded");
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(originfile, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n==NULL)
        {
            return false;
        }
        strcpy(n -> word, word);
        int index = hash(word);
        n->next = table[index];
        table[index] = n;

    }
    fclose(originfile);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return actcounter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int tablements = 0;
    while(tablements < N)
    {
        while(table[tablements] != NULL)
        {
            node *temp = table[tablements];
            table[tablements] = table[tablements] ->next;
            free(temp);
        }
        tablements++;

    }

    return true;
}
