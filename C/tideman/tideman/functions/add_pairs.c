#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void add_pairs(void);

int main(void)
{

}


void add_pairs(void)
{
    // TODO; puede ser que aquí haya un bug por la lógica del j + 1; BBBBUUUUGGGGlert
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                //No sé si el j - 1 funciona; creo que si pero just in case => BBBBUUUUGGGGlert ;<
                pairs[j - 1].winner = i;
                pairs[j - 1].loser = j;
                pairs[j - 1].strength = preferences[i][j] - preferences[j][i];

                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[j - 1].winner = j;
                pairs[j - 1].loser = i;
                pairs[j - 1].strength = preferences[j][i] - preferences[i][j];

                pair_count++;
            }

        }
    }
    return;
}