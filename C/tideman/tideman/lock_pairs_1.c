 int a, b;
    int counter = 0;
    //int counter2 = 0;

    for (int i = 0; i < pair_count - 1 ; i++)
    {
        for (int j = 0; j < counter; j++)
        {
            printf("%i == %i?\n", pairs[i].winner, pairs[j].loser);

            a = i;
            b = j;

            if (pairs[a].winner == pairs[b].loser)
            {
                a = b;

                //Chequea la lógica del 'k < counter' (o sea, como se exprresa al fin y al cabo), maybe hay que hacerlo al revés o buscar otra variable que reemplaze 'counter' y que k--
                for (int k = 0; k < counter; k++)
                {
                    if (pairs[a].winner == pairs[k].loser)
                    {
                        a = k;
                    }
                    else if (pairs[k].winner != pairs[j].loser)
                    {
                        locked[pairs[i].winner][pairs[i].loser] = true;
                        //printf("%i\n\n", locked[pairs[i].winner][pairs[i].loser]);

                    }
                //counter2++;
                }
            }

            else //(!(pairs[i].winner == pairs[j].loser))
            {
                locked[pairs[i].winner][pairs[i].loser] = true;
            }
        }
        counter++;
    }
    return;