#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef char* string;

int main(void)
{
    string s = NULL;

    printf("Enter string: \n");
    scanf("%s", s);
    printf("You entered %s\n", s);

    int *p = malloc(sizeof(int));

    if (p == NULL)
    {
        return 1;
    }

    printf("%p\n", p);

    free(p);
}