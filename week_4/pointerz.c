#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int x = 69;
    int y = 420;
    int *p = &x;
    int *q = &y; //Pa mi lo dificil es que aqui el asterisco te dice
                 //que es un pointer mientras que abajo la estrellita indica que
                 //se está hablando de lo que tiene la variable a la cual apunta.

    char *s = "Mamawebo";

    printf("p: %p, q: %p\n", &x, &y);
    printf("p: %p, q: %p\n", p, q);
    printf("p: %i, q: %i\n", *p, *q);

    for (int i = 7, n = strlen(s); i >= 0; i--)
    {
        printf("%c", *(s + i));
    }

    printf("\n");
}