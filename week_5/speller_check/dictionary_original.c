// Implements a dictionary's functionality

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

// Global nodes array check
bool check_initialized_nodes[N];

// Global Variable for size function
unsigned int global_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    if (check_initialized_nodes[index] == false)
    {
        return false;
    }

    if (strlen(word) == 0 || strlen(word) > 46)
    {
        return false;
    }

    // Point cursor to first node in hash table (if such node exists)
    node *cursor = malloc(sizeof(node));
    if (cursor == NULL)
    {
        printf("Error creating a node!");
        return false;
    }

    cursor = table[index];

    while (cursor->next != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file_pointer = fopen(dictionary, "r");
    if (file_pointer == NULL)
    {
        printf("Could not open file successfully!\n");
        return false;
    }


    char *temporary_string = (char *)malloc((sizeof(char)*LENGTH) + 1);
    if (temporary_string == NULL)
    {
        return false;
    }

    int index;


    // Copy word from file to temporary string array
    while (fscanf(file_pointer, "%s", temporary_string) != EOF)
    {
        // Add to global counter variable
        global_counter++;

        // Create new_node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        new_node->next = NULL; // It's good practice to initialize empty pointers to NULL.

        // Copy word from temporary string variable to new node
        strcpy(new_node->word, temporary_string);
        index = hash(new_node->word);

        // Assign pointer value to new node
        if (table[index] != NULL)
        {
            new_node->next = table[index]->next;
            table[index] = new_node;
        }
        else
        {
            table[index] = new_node;
            check_initialized_nodes[index] = true;
        }
    }

    fclose(file_pointer);
    free(temporary_string);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (global_counter == 0)
    {
        return 0;
    }
    else
    {
        return global_counter;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor =  malloc(sizeof(node));
    node *tmp = malloc(sizeof(node));
    if (cursor == NULL || tmp == NULL)
    {
        printf("Could not create nodes successfully!\n");
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        tmp = cursor;

        while (cursor->next != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    free(cursor);
    return true;
}
