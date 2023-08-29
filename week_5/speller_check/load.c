#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Default dictionary
#define DICTIONARY "dictionaries/large"

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

// Global check array
bool check_initialized_nodes[N];

// Global Variable for size function
unsigned int global_counter = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

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
    // int check = 0;


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

int main(int argc, char *argv[])
{
     // Check for correct number of args
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./speller [DICTIONARY] text\n");
        return 1;
    }

     // Determine dictionary to use
    char *dictionary = argv[1];


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
        printf("Error allocating memory!\n");
    }
    int index;



    // Copy word from file to temporary string array
    while (fscanf(file_pointer, "%s", temporary_string) != EOF)
    {
        // // Add to global counter variable
        // if (strlen(temporary_string) < 0 || strlen(temporary_string) > 46)
        // {
        //     printf("\nSirve el IF\n");
        //     return 1;
        // }


        global_counter++;
        printf("%d\n", global_counter);
        printf("%s\n", temporary_string);


        // Create new_node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Error creating new_node!");
            return false;
        }

        // Copy word from temporary string variable to new node
        strcpy(new_node->word, temporary_string);
        new_node->next = NULL; // It's good practice to initialize empty pointers to NULL.
        index = hash(new_node->word);

        printf("%d\n", hash(new_node->word));

        char *null = NULL;


        // Assign pointer value to new node
        if (check_initialized_nodes[index] == true)
        {
            // Cursor Start!
            new_node->next = table[index]->next;
            table[index]->next = new_node;
        }
        else
        {
            table[index] = new_node;
            check_initialized_nodes[index] = true;

        }
    }

    fclose(file_pointer);
    free(temporary_string);



    // // TRUE CHECK
    // node *cursor;

    // // Print hash table
    // for (int i = 0; i < 26; i++)
    // {
    //     cursor = table[i];

    //     while (cursor->next != NULL)
    //     {
    //             printf("%s->", cursor->word);
    //             cursor = cursor->next;
    //     }

    //     printf("%s", cursor->word);
    //     printf("\n");
    // }

    char *word_is_on = "Foo's";
    char *word_is_not = "Five";


    printf("%d\n", check(word_is_on));



    return 0;
}