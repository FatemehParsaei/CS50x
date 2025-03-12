#include "helpers.h"
#include <math.h>

// Written By Fatemeh Parsaei
// August 2024

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            average =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            if (average > 255)
                average = 255;
            // Update pixel values
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                             .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                               .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                              .131 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int w = round((float) width / 2.0);

    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < w; j++)
        {
            // Swap pixels
            RGBTRIPLE temp = image[i][j];
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // make it blur
    int average;
    int sum;
    float counter;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // RED
            average = 0;
            sum = 0;
            counter = 0;
            if (i - 1 > -1 && j - 1 > -1)
            {
                sum += copy[i - 1][j - 1].rgbtRed;
                counter++;
            }
            if (i - 1 > -1)
            {
                sum += copy[i - 1][j].rgbtRed;
                counter++;
            }
            if (i - 1 > -1 && j + 1 < width)
            {
                sum += copy[i - 1][j + 1].rgbtRed;
                counter++;
            }
            if (j - 1 > -1)
            {
                sum += copy[i][j - 1].rgbtRed;
                counter++;
            }
            sum += copy[i][j].rgbtRed;
            counter++;
            if (j + 1 < width)
            {
                sum += copy[i][j + 1].rgbtRed;
                counter++;
            }
            if (i + 1 < height && j - 1 > -1)
            {
                sum += copy[i + 1][j - 1].rgbtRed;
                counter++;
            }
            if (i + 1 < height)
            {
                sum += copy[i + 1][j].rgbtRed;
                counter++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                sum += copy[i + 1][j + 1].rgbtRed;
                counter++;
            }

            average = round((float) sum / counter);
            if (average > 255)
                average = 255;
            image[i][j].rgbtRed = average;

            // BLUE
            average = 0;
            sum = 0;
            counter = 0;
            if (i - 1 > -1 && j - 1 > -1)
            {
                sum += copy[i - 1][j - 1].rgbtBlue;
                counter++;
            }
            if (i - 1 > -1)
            {
                sum += copy[i - 1][j].rgbtBlue;
                counter++;
            }
            if (i - 1 > -1 && j + 1 < width)
            {
                sum += copy[i - 1][j + 1].rgbtBlue;
                counter++;
            }
            if (j - 1 > -1)
            {
                sum += copy[i][j - 1].rgbtBlue;
                counter++;
            }
            sum += copy[i][j].rgbtBlue;
            counter++;
            if (j + 1 < width)
            {
                sum += copy[i][j + 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j - 1 > -1)
            {
                sum += copy[i + 1][j - 1].rgbtBlue;
                counter++;
            }
            if (i + 1 < height)
            {
                sum += copy[i + 1][j].rgbtBlue;
                counter++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                sum += copy[i + 1][j + 1].rgbtBlue;
                counter++;
            }

            average = round((float) sum / counter);
            if (average > 255)
                average = 255;
            image[i][j].rgbtBlue = average;

            // GREEN
            average = 0;
            sum = 0;
            counter = 0;
            if (i - 1 > -1 && j - 1 > -1)
            {
                sum += copy[i - 1][j - 1].rgbtGreen;
                counter++;
            }
            if (i - 1 > -1)
            {
                sum += copy[i - 1][j].rgbtGreen;
                counter++;
            }
            if (i - 1 > -1 && j + 1 < width)
            {
                sum += copy[i - 1][j + 1].rgbtGreen;
                counter++;
            }
            if (j - 1 > -1)
            {
                sum += copy[i][j - 1].rgbtGreen;
                counter++;
            }
            sum += copy[i][j].rgbtGreen;
            counter++;
            if (j + 1 < width)
            {
                sum += copy[i][j + 1].rgbtGreen;
                counter++;
            }
            if (i + 1 < height && j - 1 > -1)
            {
                sum += copy[i + 1][j - 1].rgbtGreen;
                counter++;
            }
            if (i + 1 < height)
            {
                sum += copy[i + 1][j].rgbtGreen;
                counter++;
            }
            if (i + 1 < height && j + 1 < width)
            {
                sum += copy[i + 1][j + 1].rgbtGreen;
                counter++;
            }

            average = round((float) sum / counter);
            if (average > 255)
                average = 255;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}
