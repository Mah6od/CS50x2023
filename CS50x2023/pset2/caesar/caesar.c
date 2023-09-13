#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // make sure program was run with one command-line argument
    if (argc != 2)
    {
        printf("Usage: caesar key\n");
        return 1;
    }

    // make sure every single charctar in argv[1] is a digit
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i])) // ctype library
        {
            printf("Usage: caesar key\n");
            return 1;
        }
    }
    // convert argv[1] from string to an int
    int k = atoi(key);

    // prompt user for plaintext
    string plaintext = get_string("Plain Text: ");

    // for each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // rotate character if it's letter
        if (isupper(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'a' + k) % 26) + 'a';
        }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}