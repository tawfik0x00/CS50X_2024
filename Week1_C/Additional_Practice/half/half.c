// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // convert percent to decimal, after search divide by 100
    tax = tax / 100.0;
    float tipf = (float)tip / 100.0;

    // add tax to bill
    bill = (bill * tax) + bill;
    // add tip to bill
    bill = (bill * tipf) + bill;

    // return only half
    return bill / 2.0;
}
