#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    // while condition(ask question until you input correct answer)
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // print blocks
    for (int i = 0; i < height; i++)
    {
        // print spaces
        for (int k = 0; k < height - i - 1; k++)
        {
            printf(" ");
        }
        // print blocks
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // enter
        printf("\n");
    }
}
