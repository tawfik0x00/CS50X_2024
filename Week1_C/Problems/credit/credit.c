#include <cs50.h>
#include <stdio.h>

long get_credit_number(string prompt);
int check_sum(long number);
void print_card_type(long number);
int get_prefix(long number);
int get_length(long number);

int main(void)
{
    // get the number and check the length of the number
    long number = get_credit_number("Number: ");

    // if the number of the credit doesn't match 13, 15, 16 exit
    if (number == -1)
    {
        printf("INVALID\n");
        return 0;
    }

    
    int result = check_sum(number);

    // if the result doesn't equal 0 mean it's invalid credit number
    if (result != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // print the type of the card
    print_card_type(number);
    return 0;
}
long get_credit_number(string prompt)
{
    int length = 0;
    long number;

    number = get_long("%s", prompt);

    length = get_length(number);

    if (length == 13 || length == 15 || length == 16)
    {
        return number;
    }
    else
    {
        return -1;
    }
}
int check_sum(long number)
{
    int last_digit, second_last;
    int sum1 = 0, sum2 = 0;

    while (number != 0)
    {
        // get the last digit
        last_digit = number % 10;

        // delete the last digit
        number = number / 10;

        // add the last digit to the sum
        sum1 += last_digit;

        // get the second last digit now its the last because we delete the last
        second_last = number % 10;

        // and delete it after store it in second_last
        number = number / 10;

        // in algorithm we mutiply the number in 2 if it's greater than 9 we subtract 9 from it
        second_last *= 2;
        second_last -= (second_last > 9) ? 9 : 0;

        // save the value in sum2
        sum2 += second_last;
    }

    // return the value using luhan algorithm should return 0 for valid credit number
    return (sum1 + sum2) % 10;
}
void print_card_type(long number)
{
    int prefix = get_prefix(number);
    int length = get_length(number);

    if ((prefix / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else if ((prefix / 10 == 3) && (prefix % 10 == 4 || prefix % 10 == 7) && length == 15)
    {
        printf("AMEX\n");
    }
    else if ((prefix / 10 == 5) && (prefix % 10 > 0 && prefix % 10 < 6) && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
int get_length(long number)
{
    int length = 0;
    while (number != 0)
    {
        // divide by ten delete the last number until reach zero
        number /= 10;
        length++;
    }
    return length;
}
int get_prefix(long number)
{
    // get the first two digits
    while (number >= 100)
    {
        number /= 10;
    }

    return (int) number;
}
