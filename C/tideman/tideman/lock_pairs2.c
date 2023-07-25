#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

bool locked[9][9];

typedef struct
{
    int winner;
    int loser;
}
pair;

int candidate_count = 5;

pair pairs[5];

int main(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }


    pairs[0].winner = 4;
    pairs[0].loser = 0;

    pairs[1].winner = 1;
    pairs[1].loser = 3;

    pairs[2].winner = 2;
    pairs[2].loser = 4;

    pairs[3].winner = 0;
    pairs[3].loser = 1;

    pairs[4].winner = 3;
    pairs[4].loser = 2;



    int a, b, check, loser_on;
    int counter = 0;



   for (int i = 0; i < candidate_count; i++)
   {
        for (int j = 0; j < candidate_count; j++)
        {
            //Check if and where pairs[i].winner is loser on
            for (int k = 0; k < candidate_count; k++)
            {
                if (locked[k][pairs[i].winner] == 1)
                {
                    check = 1;
                    loser_on = k;
                }
            }

            // If new winner is not loser in already locked pair, lock pair
            if (check == 0)
            {
                locked[pairs[i].winner][pairs[i].loser] = true;
            }
            // If new winner is loser in already locked pair, check if source is not new loser (go up the ladder);
            //source is not loser in locked
            else
            {
                int k = 0;

                //Going up the ladder until winner is not loser and arrival at source
                do
                {
                    check = 0;

                    if (locked[k][loser_on] == 1)
                    {
                            check++;
                            loser_on = k;
                            k = -1;
                    }
                    k++;
                }
                while (k < candidate_count - 1);




                // If source is not loser in locked
                if(check == 0)
                {
                    locked[pairs[i].winner][pairs[i].loser] = true;
                }
                // If new winner is not loser in
                else //if (pairs[i].winner != pairs[].loser)
                {
                    locked[pairs[i].winner][pairs[i].loser] = true;
                }




                //Reset check variables
                check = 0;
                loser_on = 0;
            }
        }
   }


    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", locked[i][j]);
        }

        printf("\n");
    }
}