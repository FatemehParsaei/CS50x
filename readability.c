#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Written By Fatemeh Parsaei
// August 2024

// NOTE: all sentences MUST end with a punctuation mark!

void count_letters_words_sentences(string text);

int letters_Count = 0;
int words_Count = 0;
int sentence_Count = 0;

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    count_letters_words_sentences(text);
    // Compute the Coleman-Liau index
    float L = ((float) letters_Count / (float) words_Count) * 100;
    float S = ((float) sentence_Count / (float) words_Count) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Print the grade level
    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade > 15)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", grade);
}

void count_letters_words_sentences(
    string text) // counts the number of letters, words & sentences in text
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i])) // counts the letters
            letters_Count++;
        if (isalpha(text[i - 1]) && isspace(text[i])) // counts the words
            words_Count++;
        else if (isalpha(text[i - 1]) && ispunct(text[i]))
            words_Count++;
        if (isalpha(text[i - 1]) && text[i] == '\'') // i've or jem's are one word
            words_Count--;
        if (isalpha(text[i - 1]) && text[i] == '-') // mother-in-law is one word
            words_Count--;
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') // counts the sentences
            sentence_Count++;
    }
}
