#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calc_quarters(int cents);
int calc_nickels(int cents);
int calc_dimes(int cents);
int calc_pennies(int cents);

int main(void)
{
    // Get a Cents Owed
    int cents = get_cents();
    
    // another way to solve this problem
    // divide and modulus
    
    // calc quarters
    int quarters = calc_quarters(cents);
    cents -= (quarters * 25);

    // calc dimes
    int dimes = calc_dimes(cents);
    cents -= (dimes * 10);

    // calc nickels
    int nickels = calc_nickels(cents);
    cents -= (nickels * 5);

    // calc pennies
    int pennies = calc_pennies(cents);
    cents -= (pennies * 1);

    printf("%i\n", (quarters + dimes + nickels + pennies));
}
int get_cents(void)
{
    int cents;

    // While cents less than 1 ask again the user 
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    // return cents
    return cents;
}
int calc_quarters(int cents)
{
    // define a number of quarters will calc through the loop
    int quarters = 0;

    // while cents greater than 25 every time subtract 25 and add one to quarters
    while (cents >= 25)
    {
        cents -= 25;
        quarters++;
    }
    return quarters;
}
int calc_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        cents -= 10;
        dimes++;
    }
    return dimes;
}
int calc_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        cents -= 5;
        nickels++;
    }
    return nickels;
}
int calc_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        cents -= 1;
        pennies++;
    }
    return pennies;
}
