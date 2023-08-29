#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Global Variable for size function
unsigned int global_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    // Point cursor to first node in hash table (if such node exists)
    node *cursor = malloc(sizeof(node));
    if (cursor == NULL)
    {
        printf("Error creating node!");
        return false;
    }


    cursor = table[index];
    // if (cursor->next == NULL)
    // {
    //     return false;
    // }


    while (cursor->next != NULL)
    {
        if (strcasecmp(cursor->word, word))
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}