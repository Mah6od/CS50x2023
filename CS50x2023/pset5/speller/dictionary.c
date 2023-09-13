// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 5381;

// Hash table
node *table[N];

// Words in the dictionary
unsigned int worddict = 0;

// Hash code from the word
unsigned int wordhash = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    wordhash = hash(word);
    node *cursor = table[wordhash];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
// Hashes word to a number
// djb2 algorithm (http://www.cse.yorku.ca/~oz/hash.html)
// this algorithm (k=33) was first reported by dan bernstein many years ago
// in comp.lang.c. another version of this algorithm (now favored by bernstein)
// uses xor: hash(i) = hash(i - 1) * 33 ^ str[i]; the magic of number 33
//(why it works better than many other constants, prime or not) has never been adequately explained.
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dic = fopen(dictionary, "r");
    char word[LENGTH + 1];
    if (dic != NULL)
    {
        while (fscanf(dic, "%s", word) != EOF)
        {
            node *n = malloc(sizeof(node));

            if (n != NULL)
            {
                wordhash = hash(word);
                strcpy(n->word, word);
                n->next = table[wordhash];
                table[wordhash] = n;
                worddict++;
            }
        }
        fclose(dic);
    }
    else
    {
        return false;
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return worddict;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    int i = 0;
    while (i < N)
    {
        node *cursor = table[i];

        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }

        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
        i++;
    }
    return false;
}