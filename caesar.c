#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Written By Fatemeh Parsaei
// August 2024

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    while (argc > 0)
    {
        if (argc == 2 && isdigit(argv[1][0]))
            break;
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!(isdigit(argv[1][i])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // if key is bigger or equal 26 adjust key
    if (key >= 26)
    {
        int n = key / 26;
        n *= 26;
        key -= n;
    }

    // Encrypt the plaintext
    printf("ciphertext: ");
    // For each character in the plaintext rotate it key times
    for (int j = 0, n = strlen(plaintext); j < n; j++)
    {
        if (isalpha(plaintext[j]))
        {
            if (isupper(plaintext[j]))
            {
                if ((plaintext[j] + key) > 90)
                {
                    printf("%c", plaintext[j] + key - 26);
                }
                else
                {
                    printf("%c", plaintext[j] + key);
                }
            }
            else if (islower(plaintext[j]))
            {
                if ((plaintext[j] + key) > 122)
                {
                    printf("%c", plaintext[j] + key - 26);
                }
                else
                {
                    printf("%c", plaintext[j] + key);
                }
            }
        }
        else
            printf("%c", plaintext[j]);
    }
    printf("\n");
    return 0;
}
