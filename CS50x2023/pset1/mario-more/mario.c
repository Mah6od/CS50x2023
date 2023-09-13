#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // while condition(ask question until you input correct answer)
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // print the left blockes
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // print that space between blockes
        printf("  ");

        // print the right blockes
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }
        printf("\n");
    }

}