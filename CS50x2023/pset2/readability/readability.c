#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int count_letters(string text);


int main(void)
{
    string text = get_string("text: ");
    int letterCount = 0;
    int wordCount = 0;
    int sentences = 0;
    bool inWord = false;

    // calculate letters,words,sentences
    for (int i = 0; text[i] != '\0'; i++)
    {
        char t = text[i];
        if (isalpha(t))
        {
            // letters
            letterCount++;
            if (!inWord)
            {
                // words
                inWord = true;
                wordCount++;
            }
        }
        else if (isspace(t))
        {
            inWord = false;
        }
        else if (t == '.' || t == '!' || t == '?')
        {
            // sentences
            sentences++;
            inWord = false;
        }
    }

    // calculate difficulties

    float L = (float)letterCount / wordCount * 100;
    float S = (float)sentences / wordCount * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // round grade to nearest integer
    int roundedIndex = round(index);

    // print numbers of Letters, Words, Sentences and Difficulties grade
    printf("%i Letters. \n", letterCount);
    printf("%i Word. \n", wordCount);
    printf("%i Sentences. \n", sentences);

    // print grade
    if (roundedIndex >= 16)
    {
        printf("Grade: Grade 16+\n");
    }
    else if (roundedIndex < 1)
    {
        printf("Grade: Before Grade 1\n");
    }
    else
    {
        printf("Grade: Grade %d\n", roundedIndex);
    }

    return 0;
}