#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void print_row(int spaces, int bricks);

int main(void)
{
    // get the height of the pyramid
    int height = get_height("Height: ");

    // start print the pyramid
    for (int row = 1; row <= height; row++)
    {
        // print every row in the pyramid
        // height - i = spaces
        // i number of hashes per line

        int spaces = height - row;
        int bricks = row; // number of bricks equal the row number

        print_row(spaces, bricks);
    }
}
int get_height(string prompt)
{
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
