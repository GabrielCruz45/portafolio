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

void lock_pairs(void);

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


    int a, b;
    int k = 0;
    int counter = 0;
    //int counter2 = 0;

    printf("Hey 1\n");

    for (int i = 0; i < candidate_count; i++)
    {
        printf("Hey 2\n");
        
        for (int j = 0; j < counter; j++)
        {
            printf("Hey 3\n");

            printf("Blue for(j)\ni: %i j: %i\n", i, j);
            printf("pairs[%i]: %i %i pairs[%i]: %i %i\n\n", i, pairs[i].winner, pairs[i].loser, j, pairs[j].winner, pairs[j].loser);
            printf("%i == %i?\n\n", pairs[i].winner, pairs[j].loser);

            a = i;
            b = j;

            printf("Yellow if:\na.winner: %i b.loser: %i\n", pairs[a].winner, pairs[b].loser);
            if (pairs[a].winner == pairs[b].loser)
            {
                a = b;
                printf("k: %i a = b\nnew a: %i\n\n", k, a);

                if (pairs[a].winner == pairs[k].loser)
                {
                    printf("pairs[%i].winner == pairs[%i].loser\n %i == %i\n", a, k, pairs[a].winner, pairs[k].loser);

                    do
                    {
                        printf("Blue Do Loop\npairs[%i].winner: %i == pairs[%i].loser: %i?\n", a, pairs[a].winner, k, pairs[k].loser);
                        a = k;
                        k++;
                    } while(pairs[a].winner == pairs[k].loser);
                }

                printf("pairs[%i].winner: %i, pairs[%i].loser: %i\n", k, pairs[k].winner, j, pairs[j].loser);

                if (pairs[k].winner == pairs[j].loser)
                {
                    locked[pairs[i].winner][pairs[i].loser] = false;
                    printf("i = %i locked[%i][%i]: %i\n\n", i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
                }
                else
                {
                    locked[pairs[i].winner][pairs[i].loser] = true;
                    printf("i = %i locked[%i][%i]: %i\n\n", i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
                }

                k = 0;
            }
            counter++;
            printf("counter: %i\n\n\n", counter);
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



void lock_pairs(void)
{
    int counter = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < counter; j++)
        {
            if (!(pairs[i].winner == pairs[j].loser))
            {
                locked[pairs[i].winner][pairs[i].loser] = true;

            }
        }
        counter++;
    }
}


                //for (int k = 0; k < counter; k++)
                //{
                //    printf("Magenta for(k):\n%i %i\n\n", pairs[a].winner, pairs[k].loser);

                //    if (pairs[a].winner == pairs[k].loser)
                //    {
                //        a = k;
                //        printf("Blue if:\nnew other a: %i\n", a);
                //    }
                //    else if (pairs[k].winner != pairs[j].loser)
                //    {
                //        printf("Blue else if:\nk.winner: %i j.loser: %i\n\n", pairs[k].winner, pairs[j].loser);

                //        locked[pairs[i].winner][pairs[i].loser] = true;

                //        printf("i = %i locked[%i][%i]: %i\n\n", i, pairs[i].winner, pairs[i].loser, locked[pairs[i].winner][pairs[i].loser]);
                //    }
                //counter2++;
                //}

            //else if (!(pairs[i].winner == pairs[j].loser))
            //{
            //    printf("Yelllow else:\ni.winner: %i j.loser: %i\n\n", pairs[i].winner, pairs[j].loser);

            //    locked[pairs[i].winner][pairs[i].loser] = true;
            //    printf("pairs[i].winner: %i pairs[i].loser: %i\n", pairs[i].winner, pairs[i].loser);
            //    printf("%i\n\n", locked[pairs[i].winner][pairs[i].loser]);
            //}

