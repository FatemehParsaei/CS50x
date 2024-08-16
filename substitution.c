#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Written By Fatemeh Parsaei
// August 2024

int main(int argc, string argv[])
{
    // Validate Key
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Make sure all characters in command-line argument are alphabetical
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
            break;
        }
    }
    // Make sure command-line argument is 26
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Make sure key does not have repeated characters
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (islower(argv[1][i]))
            {
                if (islower(argv[1][j]))
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                        break;
                    }
                }
                else // argv[1][j] is uppercase
                {
                    if (argv[1][i] == tolower(argv[1][j]))
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                        break;
                    }
                }
            }
            else // argv[1][i] is uppercase
            {
                if (isupper(argv[1][j]))
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                        break;
                    }
                }
                else // argv[1][j] is lowercase
                {
                    if (argv[1][i] == toupper(argv[1][j]))
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                        break;
                    }
                }
            }
        }
    }
    string key = argv[1];
    // Get Plaintext
    string plaintext = get_string("plaintext:  ");

    // Encipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            if (isupper(key[plaintext[i] - 'A']))
            {
                printf("%c", key[plaintext[i] - 'A']);
            }
            else // key[plaintext[i] - 'A'] is lowercase
            {
                printf("%c", toupper(key[plaintext[i] - 'A']));
            }
        }
        else if (islower(plaintext[i]))
        {
            if (islower(key[plaintext[i] - 'a']))
            {
                printf("%c", key[plaintext[i] - 'a']);
            }
            else // key[plaintext[i] - 'A'] is uppercase
            {
                printf("%c", tolower(key[plaintext[i] - 'a']));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
