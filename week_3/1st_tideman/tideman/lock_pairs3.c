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

bool check_for_loop(int winner, int loser_in_question);

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




    for (int i = 0; i < candidate_count ; i++)
    {
        printf("\nfor loop i: %i, pairs[i].winner: %i, pairs[i].loser: %i\n\n", i, pairs[i].winner, pairs[i].loser);

        if (!(check_for_loop(pairs[i].winner, pairs[i].loser)))
        {
            printf("if bueno winner: %i loser: %i\n\n\n", pairs[i].winner, pairs[i].loser);

            locked[pairs[i].winner][pairs[i].loser] = true;
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

//Input needs to be winner, winner in question; Eventualmente locked tiene que tener una columna llena de cero pq no hay mas de dos sources
bool check_for_loop(int current_winner, int loser_in_question)
{
    int new_winner;
    int  check = 0;
    bool recursion = false;


    printf("current_winner: %i, loser_in_question: %i\n", current_winner, loser_in_question);

    //Check if and where winner is loser on
    for (int k = 0; k < candidate_count; k++)
    {
        if (locked[k][current_winner] == 1)
        {
            check++;
            new_winner = k;
        }
    }

    printf("winner: %i, new_winner: %i,loser_in_question: %i, check: %i\n\n", current_winner, new_winner, loser_in_question, check);

    //If winner is loser on another pair, go to that pair to check
    if (check >= 1)
    {
        recursion = check_for_loop(new_winner, loser_in_question);
    }

    //If check == 0; current winner is current "source"

    //Check if loser_in_question is new_winner
    if(current_winner == loser_in_question)
    {
        //If true, there is a loop
        printf("There's a loop!!\n");

        return true;
    }


    //Otherwise, no loop
    printf("No loop bre!! %i\n", recursion);

    return recursion;

}