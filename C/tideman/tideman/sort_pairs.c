#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int winner;
    int loser;
    int strength;
}
pair;

pair pairs[10];

int main(void)
{
    pairs[0].strength = 4;
    pairs[1].strength = 5;
    pairs[2].strength = 6;
    pairs[3].strength = 9;
    pairs[4].strength = 8;
    pairs[5].strength = 3;
    pairs[6].strength = 7;
    pairs[7].strength = 1;
    pairs[8].strength = 2;
    pairs[9].strength = 10;
    pair temporary;

    //Bubblesort
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (pairs[j].strength < pairs[j + 1].strength)
            {
                temporary.strength = pairs[j].strength;

                pairs[j].strength = pairs[j + 1].strength;

                pairs[j + 1].strength = temporary.strength;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%i\n", pairs[i].strength);
    }

    return 0;
}
