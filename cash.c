#include <cs50.h>
#include <stdio.h>

int countTheCoins(int cents);

int main(void)
{
    int money;

    // Prompt the user for change owed, in cents
    do
    {
        money = get_int("Change owed:  ");
    }
    while (money <= 0);

    // Calculate how many coins you should give customer
    printf("%i\n", countTheCoins(money));
}

int countTheCoins(int cents)
{
    int number = 0; // holds number of coins needed
    int holder = 0; // for minus operations

    if (cents / 25 != 0)
    {
        number = cents / 25;
        cents = cents - (25 * number); // Subtract the value of those quarters from cents
    }
    if (cents != 0 && cents / 10 != 0)
    {
        number = number + (cents / 10);
        holder = cents / 10;
        cents = cents - (10 * holder);
        holder = 0;
    }
    if (cents != 0 && cents / 5 != 0)
    {
        number = number + (cents / 5);
        holder = cents / 5;
        cents = cents - (5 * holder);
        holder = 0;
    }
    if (cents != 0)
    {
        number = number + cents;
    }
    return number;
}