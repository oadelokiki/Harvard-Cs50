#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float change = get_float("Change owed:");
    int coins = 0;
    while ( change < 0)
    {
        change = get_float("Change owed:");
    }
    change *= 100;
    change = (int)change;
        if(change >= 25)
        {
            while(change >= 25)
            {
                change -= 25;
                coins ++;
            }
        }
        if(change >= 10)
        {
            while (change >= 10)
            {
                change -= 10;
                coins ++;
            }
        }
        if(change >= 5)
        {
            while(change >= 5)
            {
                change -= 5;
                coins ++;
            }
        }
        if(change >= 1)
        {
            while(change >= 1)
            {
                change -= 1;
                coins ++;
            }
        }
        printf("Coins: %i \n", coins);


}