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

// typedef struct array_of_nodes
// {
//     struct node *array_of_nodes[LENGTH + 1];
// }
// array_of_nodes;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N][LENGTH];

// Global initialization check
bool initialization_check[N][LENGTH];


// Global Variable for size function
unsigned int global_counter = 0;

// Populate initialization_check table
void populate(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            initialization_check[i][j] = false;
        }
    }
}

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
    int index = hash(word), word_length = strlen(word);

    if (initialization_check[index][word_length] == false)
    {
        return false;
    }

    if (word_length == 0 || word_length > 46)
    {
        return false;
    }



    if (strcasecmp(table[index][word_length]->word, word) == 0)
    {
        return true;
    }
    else
    {
        node *cursor = malloc(sizeof(node));
        if (cursor == NULL)
        {
            printf("Error creating a node!");
            return false;
        }

        cursor = table[index][word_length];

        while (cursor->next != NULL)
        {
            if (strcasecmp(cursor->word, word) == 0)
            {
                cursor = NULL;
                free(cursor);
                return true;
            }

            cursor = cursor->next;
        }

        free(cursor);
    }


    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < LENGTH + 1; j++)
        {
            if (initialization_check[i][j] == true)
            {
                // TODO
                node *cursor =  malloc(sizeof(node));
                if (cursor == NULL)
                {
                    printf("Could not create node successfully!\n");
                    return false;
                }


                cursor = table[i][j];

                while (cursor->next != NULL)
                {
                    node *tmp = malloc(sizeof(node));
                    if (tmp == NULL)
                    {
                        printf("Could not create node successfully!\n");
                        return false;
                    }

                    tmp = cursor;
                    cursor = cursor->next;
                    free(tmp);
                    tmp = NULL;
                }


                free(cursor);
                cursor = NULL;
            }
        }
    }

    return true;
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
    int index, word_length;

    populate();

    // Copy word from file to temporary string array
    while (fscanf(file_pointer, "%s", temporary_string) != EOF)
    {
        global_counter++;

        // Create new_node and check for error
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Error creating new_node!");
            return false;
        }

        // Populate new_node; Copy word from temporary string variable to new node
        strcpy(new_node->word, temporary_string);
        new_node->next = NULL; // It's good practice to initialize empty pointers to NULL.

        index = hash(new_node->word);
        word_length = strlen(new_node->word);


        if (initialization_check[index][word_length] != false)
        {
             new_node->next = table[index][word_length]->next;
             table[index][word_length]->next = new_node;
        }
        else
        {
            table[index][word_length] = new_node;

            initialization_check[index][word_length] = true;
        }
    }

    char *on_array = "Yeast";
    char *not_on_array = "Fergus";

    printf("on_array: %i not_on_array: %i\n", check(on_array), check(not_on_array));

    for (int i = 0; i < N; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < LENGTH; j++)
        {
            printf("%d", initialization_check[i][j]);
        }
        printf("\n");
    }

    fclose(file_pointer);
    free(temporary_string);
    unload();

    return 0;
}



















































    // node *cursor;

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < LENGTH; j++)
    //     {
    //         if (initialization_check[i][j] == true)
    //         {
    //             printf("table[%i][%i]\n", i, j);
    //             cursor = table[i][j];
    //             while (cursor->next != NULL)
    //             {
    //                 printf("%s->", cursor->word);
    //                 cursor = cursor->next;
    //             }

    //             printf("%s\n", cursor->word);
    //         }
    //     }
    // }

    // free(cursor);