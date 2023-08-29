#include <stdio.h>


int main(void)
{
    int n = 50;
    int *p = &n;

    printf("%p\n", p);

    char *s= "HI!";
    printf("%s\n", s);
    printf("%s\n", s + 1);
    printf("%s\n", s + 2);
}