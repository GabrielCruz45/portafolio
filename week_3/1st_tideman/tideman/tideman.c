#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j; if [i][j] is true then arrow is locked (or pointing) from candidate [i] to candidate [j]
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

typedef struct
{
    int wins;
    int losses;
    int candidate;
}
check;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;


// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_for_loop(int winner, int loser_in_question);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference;
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    int a, b;

    for (int i = 0; i < candidate_count - 1; i++)
    {
        a = ranks[i];

        for (int j = i + 1; j < candidate_count; j++)
        {
            b = ranks[j];

            //Record preference
            preferences[a][b]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO; entiendo que hacer candidate_count - 1 no hace mucha diferencia
    // pues el próximo for loop terminaría el proceso, pero por hacerlo in good form
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;

                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;

                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    pair temporary;
    int a, b, c, d;

    //Bubblesort
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            a = preferences[pairs[j].winner][pairs[j].loser];
            b = preferences[pairs[j].loser][pairs[j].winner];
            c = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
            d = preferences[pairs[j + 1].loser][pairs[j + 1].winner];

            if (a - b < c - d)
            {
                temporary.winner = pairs[j].winner;
                temporary.loser = pairs[j].loser;

                pairs[j].winner = pairs[j + 1].winner;
                pairs[j].loser = pairs[j + 1].loser;

                pairs[j + 1].winner = temporary.winner;
                pairs[j + 1].loser = temporary.loser;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < candidate_count ; i++)
    {
        if (!(check_for_loop(pairs[i].winner, pairs[i].loser)))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int counter = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                counter++;
            }
        }

        if (counter == candidate_count)
        {
            printf("%s\n", candidates[i]);
            return;
        }
        else
        {
            counter = 0;
        }
    }
}

//Input needs to be winner, loser in question; Eventualmente locked tiene que tener una columna llena de cero pq no hay mas de dos sources
bool check_for_loop(int current_winner, int loser_in_question)
{
    int new_winner;
    int check = 0;
    bool recursion = false;

    //Check if and where winner is loser on
    for (int k = 0; k < candidate_count; k++)
    {
        if (locked[k][current_winner] == 1)
        {
            check++;
            new_winner = k;
        }
    }

    //If winner is loser on another pair, go to that pair to check
    if (check >= 1)
    {
        recursion = check_for_loop(new_winner, loser_in_question);
    }

    //If check == 0; current winner is current "source"

    //Check if loser_in_question is current_winner
    if (current_winner == loser_in_question)
    {
        //If true, there is a loop
        return true;
    }


    //Otherwise, no loop
    return recursion;
}

