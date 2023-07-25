


int main(void)
{

    //PRINT WINNER FUNCTION
    int counter;
    check check_array[MAX];
    check temporary;
    int a, b, c, d, e, f, g;

    //Count how many wins cadidate has
    for (int i = 0; i < candidate_count; i++)
    {
        check_array[i].candidate = i;

        for  (int j = 0; j < candidate_count; j++)
        {
            if (locked[i][j] == true)
            {
                check_array[i].wins++;
            }
        }
    }

    //Sort check_array w/bubblesort
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (check_array[j].wins < check_array[j + 1].wins)
            {
                temporary.wins = check_array[j].wins;
                temporary.candidate = check_array[j].candidate;

                check_array[j].wins = check_array[j + 1].wins;
                check_array[j].candidate = check_array[j + 1].candidate;

                check_array[j + 1].wins = temporary.wins;
                check_array[j + 1].candidate = temporary.candidate;

            }
        }
    }

    //If tie; check who winz
    if (check_array[0].wins == check_array[1].wins)
    {
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
    else
    {
        printf("%s\n", candidates[check_array[0].candidate]);
        return;
    }
}