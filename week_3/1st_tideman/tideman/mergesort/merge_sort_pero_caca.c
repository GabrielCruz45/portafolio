#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int numbers[8] = {9, 4, 0, 8, 2, 1, 3, 7};

int main(void)
{
    //Divide array by half
    int left4[4], right4[4];

    for (int i = 0; i < 4; i++)
    {
        left4[i] = numbers[i];
        right4[i] = numbers[i + 4];
    }

    //Divide array by half of half of left4[]
    int left2left4[2], right2left4[2];

    for (int i = 0; i < 2; i++)
    {
        left4[i] = left2left4[i];
        left4[i] = right2left4[i + 2];
    }




    //Divide array by half of half of half of left4[]
    int left1left4[1], right1left4[1];

    for (int i = 0; i < 1; i++)
    {
        left2left4[i] = left1left4[i];
        left2left4[i] = right1left4[i + 1];
    }

    //Check
    if (left1left4[0] < right1left4[0])
    {
        int temporary[0] = right1left4[0];
        left1left4[0] = right1left4[0];
        right1left4[0] = temporary[0];
    }









}