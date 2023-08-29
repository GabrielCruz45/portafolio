#include <stdio.h>

int main(void)
{
    FILE* file;

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

    fclose(file);
    return 0;
}