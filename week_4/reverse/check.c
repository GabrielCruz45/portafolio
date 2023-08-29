#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char word[45 + 1];
    struct node *next;
}
node;

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        node *n = malloc(sizeof(int));

        free(n);
    }
}