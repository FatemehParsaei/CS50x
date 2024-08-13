#include <cs50.h>
#include <stdio.h>

void pyramid(int pyHeight);

int main(void)
{
    int height = 0;
    // Prompt the user for the pyramid's height
    do
    {
        height = get_int("from 1 to 8 choose Height:  ");
    }
    while (height < 1 || height > 8);

    pyramid(height);
}

void pyramid(int pyHeight) // makes the pyramid with the input integer
{
    for (int i = 1; i <= pyHeight; i++) // rows
    {
        int lenght = (pyHeight * 2) + 2;

        for (int j = 1; j <= lenght; j++) // columns
        {
            if (j <= pyHeight - i)
            {
                printf(" ");
            }
            else if (j > pyHeight - i && j <= pyHeight)
            {
                printf("#");
            }
            else if (j == pyHeight + 1 || j == pyHeight + 2)
            {
                printf(" ");
            }
            else if (j > pyHeight + 2 && j <= (((pyHeight * 2) + 2) - (pyHeight - i)))
            {
                printf("#");
            }
            else if (j > (((pyHeight * 2) + 2) - (pyHeight - i)))
            {
                break;
            }
        }
        printf("\n");
    }
}
