#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get a name
    string name = get_string("what's your name? ");

    // say hello
    printf("Hello, %s\n", name);
}