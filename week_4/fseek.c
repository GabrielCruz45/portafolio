#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *file;

    file = fopen("file.txt", "w");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "0123456789\n");
    fprintf(file, "abcdefghij\n");



    fseek(file, 4, SEEK_SET);

    fprintf(file, "ABC");

    fseek(file, 1, SEEK_CUR);

    fprintf(file, "D");

    fseek(file, -4,  SEEK_END);

    fprintf(file, "**");

    if  (fseek(file, 10, SEEK_END) == 0)
    {
        printf("Seek failed!\n");
        return 1;
    }

    fclose(file);
    return 0;
}