#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int whoWins(string player); // counts the score

int scrabScore[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // scrabble scores for every alphabet

int main(void)
{
    string player1 = get_string("\nPlayer 1 : ");
    string player2 = get_string("Player 2 : ");

    int score1 = whoWins(player1);
    int score2 = whoWins(player2);

    if (score1 > score2)
    {
        printf("\nPlayer 1 Wins!\n\n");
    }
    else if (score2 > score1)
    {
        printf("\nPlayer 2 Wins!\n\n");
    }
    else
    {
        printf("\nTie!\n\n");
    }
}

int whoWins(string player)
{
    int score = 0;

    for (int i = 0, n = strlen(player); i < n; i++)
    {
        if (isupper(player[i]))
        {
            score += scrabScore[player[i] - 'A'];
        }
        else if (islower(player[i]))
        {
            score += scrabScore[player[i] - 'a'];
        }
    }
    return score;
}