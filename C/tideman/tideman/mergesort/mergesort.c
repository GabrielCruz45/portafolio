#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int numbers[8] = {9, 4, 0, 8, 2, 1, 3, 7};


void merge(int sort_me[], int n);


int main(void)
{
    int counter = 8;
    merge(numbers, counter);

    for (int i = 0; i < 8; i++)
    {
        printf("%i\n", numbers[i]);
    }

    //el bicho
    return 0;
}





















void merge(int sort_me[], int size_of_array)
{
    int left[size_of_array / 2];
    int right[size_of_array / 2];

    int temporary[1];


    //Divide sort_me array into 2 parts
    for (int i = 0; i < size_of_array / 2; i++)
    {
        left[i] = sort_me[i];
        printf("right[i]: %i\n", left[i]);

        right[i] = sort_me[i + (size_of_array / 2)];
        printf("right[i + 1]: %i\n", right[i]);
    }

    printf("Before recursion: %i\n", size_of_array);

    //Recursion Test
    if (size_of_array < 1)
    {
        return;
    }



    //Sort left side; down the rabbit hole
    merge(left, size_of_array / 2);

    //Sort left side
    for (int i = 0; i < size_of_array / 2 ; i++)
    {
        if (left[i] < left[i + 1])
        {
            temporary[0] = left[i];
            left[i] = left[i + 1];
            printf("left[i]:%i\n", left[i]);

            left[i + 1] = temporary[0];
            printf("left[i + 1]: %i\n", left[i + 1]);
        }
    }


    //Sort right; down the rabbit hole
    merge(right, size_of_array / 2);

    //Sort right side
    for (int i = 0; i < size_of_array / 2 ; i++)
    {
        if (right[i] < right[i + 1])
        {
            temporary[0] = right[i];
            right[i] = right[i + 1];
            printf("%i\n", right[i]);

            right[i + 1] = temporary[0];
            printf("%i\n", right[i + 1]);
        }
    }

    //Merge both arrays
    for (int i = 0; i < size_of_array / 2 ; i++)
    {
        numbers[i] = left[i];

        numbers[i + (size_of_array / 2)] = right[i];
    }
}