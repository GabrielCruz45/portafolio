#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x);
    printf("x: %i\n", x);

    char *s ;
    printf("s: ");
    scanf("%s", s); //strings are already addresses no need for & ampersand here, other data types will need the & ampersand
    printf("s: %s\n", s);
}