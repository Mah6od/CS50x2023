#include <stdio.h>
#include <cs50.h>

int main()
{
    int start_size, end_size;
    int years = 0;

    // Prompt for start size
    do
    {
        start_size = get_int("Start size(minimum: 9): ");
    }
    while (start_size < 9);

    // Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // Calculate number of years until we reach threshold
    while (start_size < end_size)
    {
        int born_lamas = start_size / 3;
        int die_lamas = start_size / 4;
        start_size = start_size + born_lamas - die_lamas;
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
