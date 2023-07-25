#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void record_preferences(int ranks[]);

int main(void)
{

}

void record_preferences(int ranks[])
{
    // TODO
    int a, b;

    for (int i = 0; i < candidate_count - 1; i++)
    {
        a = ranks[i];

        //candidate_count - 1?
        for (int j = i + 1; j < candidate_count; j++)
        {
            b = ranks[j];

            //Record preference
            preferences[a][b]++;
        }
    }
    return;
}