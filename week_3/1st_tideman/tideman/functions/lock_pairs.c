#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void lock_pairs(void)

int main(void)
{

}
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        locked[pairs[i].loser][pairs[i].winner] = false;
    }
    return;
}