#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10


typedef struct
{
    char holap[MAX_NAME];
    int age;
}
person;

unsigned int hash(char *name)
{
    return strlen(name);
}


int main(void)
{
    printf("Zelda => %u\n", hash("Zelda"));
    printf("Rauru => %u\n", hash("Natalie"));
    printf("Saria => %u\n", hash("Saria"));
    printf("Mipha => %u\n", hash("Mipha"));
    printf("Link => %u\n", hash("Link"));

    return 0;
}