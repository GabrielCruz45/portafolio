#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int n = strlen(input);
    int arr[n];
    int a = 0;

    for (int i = 0; i < n; i++)
    {
        arr[i] = input[i] - 48;
    }


    for (int i = 0; i < n ; i++)
    {
        a = a + (arr[i] * pow(10, (n - (i + 1))));
    }

    a = (int)a;

    return a;
}