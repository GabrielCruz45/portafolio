#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void sort_pairs(void)

int main(void)
{

}

void sort_pairs(void)
{
    // TODO
    pair temporary[1];

    //Bubblesort
    for (int step = 0; step < candidate_count - 1; step++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (pairs[i].strength < pairs[i + 1].strength)
            {
                temporary[0] = pairs[i];
                pairs[i] = pairs[i + 1];
                pairs[i + 1] = temporary[0];
            }
        }
    }

    return;
}