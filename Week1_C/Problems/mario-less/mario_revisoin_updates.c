#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void print_row(int spaces, int bricks);
void right_aligned_pyramid(int height);

int main(void)
{
    /*
        We should write pseudocode.
        1- get the height of the pyramid
        2- print pyramid:
            print number of rows equal height:
                each row:
                    we print number of spaces
                    print number of bricks
    */
    
    // make function to use abstraction in our code.
    int height = get_height("Height: ");
    // this function will print the pyramid
    right_aligned_pyramid(height);
}
int get_height(string prompt)
{
    /*
        Input: its takes string will showed to the user
        Return: an integer greater than 0 called height.
    */

    int n;
    // while the values less than 1 re-prompt the user
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1);
    
    // return the value
    return n;
}
void print_row(int spaces, int bricks)
{
    /*
        input: takes number of spaces, number of bricks
        output: return nothing, but print row of spaces and bricks.
    */

    // first print the spaces
    for (int i = 0; i < spaces; i++)
    {
        printf(" ");
    }

    // print the bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    // take a new line
    printf("\n");
}
void right_aligned_pyramid(int height)
{
    /*
        Input: an integer greater.
        Ouput: its print a right aligned pyramid of bricks #
    */

    // start loop with row number 1 equal one brick # and count up
    for (int row = 1; row <= height; row++)
    {
        // count number of spaces
        int spaces = height - row;
        // count number of bricks
        int bricks = row;
        // print the row
        print_row(spaces, bricks);
    }
}
