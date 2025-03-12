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
            average = round(
                (float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    // Calculate GX and GY
    int gxRED = 0;
    int gxBLUE = 0;
    int gxGREEN = 0;
    int gyRED = 0;
    int gyBLUE = 0;
    int gyGREEN = 0;
    int root = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gxRED = 0;
            gxBLUE = 0;
            gxGREEN = 0;
            gyRED = 0;
            gyBLUE = 0;
            gyGREEN = 0;

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                gxRED += -1 * copy[i - 1][j - 1].rgbtRed;
                gxBLUE += -1 * copy[i - 1][j - 1].rgbtBlue;
                gxGREEN += -1 * copy[i - 1][j - 1].rgbtGreen;
                gyRED += -1 * copy[i - 1][j - 1].rgbtRed;
                gyBLUE += -1 * copy[i - 1][j - 1].rgbtBlue;
                gyGREEN += -1 * copy[i - 1][j - 1].rgbtGreen;
            }
            if (i - 1 >= 0)
            {
                gyRED += -2 * copy[i - 1][j].rgbtRed;
                gyBLUE += -2 * copy[i - 1][j].rgbtBlue;
                gyGREEN += -2 * copy[i - 1][j].rgbtGreen;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                gxRED += 1 * copy[i - 1][j + 1].rgbtRed;
                gxBLUE += 1 * copy[i - 1][j + 1].rgbtBlue;
                gxGREEN += 1 * copy[i - 1][j + 1].rgbtGreen;
                gyRED += -1 * copy[i - 1][j + 1].rgbtRed;
                gyBLUE += -1 * copy[i - 1][j + 1].rgbtBlue;
                gyGREEN += -1 * copy[i - 1][j + 1].rgbtGreen;
            }
            if (j - 1 >= 0)
            {
                gxRED += -2 * copy[i][j - 1].rgbtRed;
                gxBLUE += -2 * copy[i][j - 1].rgbtBlue;
                gxGREEN += -2 * copy[i][j - 1].rgbtGreen;
            }
            if (j + 1 < width)
            {
                gxRED += 2 * copy[i][j + 1].rgbtRed;
                gxBLUE += 2 * copy[i][j + 1].rgbtBlue;
                gxGREEN += 2 * copy[i][j + 1].rgbtGreen;
            }
            if (i + 1 < height && j - 1 > -1)
            {
                gxRED += -1 * copy[i + 1][j - 1].rgbtRed;
                gxBLUE += -1 * copy[i + 1][j - 1].rgbtBlue;
                gxGREEN += -1 * copy[i + 1][j - 1].rgbtGreen;
                gyRED += 1 * copy[i + 1][j - 1].rgbtRed;
                gyBLUE += 1 * copy[i + 1][j - 1].rgbtBlue;
                gyGREEN += 1 * copy[i + 1][j - 1].rgbtGreen;
            }
            if (i + 1 < height)
            {
                gyRED += 2 * copy[i + 1][j].rgbtRed;
                gyBLUE += 2 * copy[i + 1][j].rgbtBlue;
                gyGREEN += 2 * copy[i + 1][j].rgbtGreen;
            }
            if (i + 1 < height && j + 1 < width)
            {
                gxRED += 1 * copy[i + 1][j + 1].rgbtRed;
                gxBLUE += 1 * copy[i + 1][j + 1].rgbtBlue;
                gxGREEN += 1 * copy[i + 1][j + 1].rgbtGreen;
                gyRED += 1 * copy[i + 1][j + 1].rgbtRed;
                gyBLUE += 1 * copy[i + 1][j + 1].rgbtBlue;
                gyGREEN += 1 * copy[i + 1][j + 1].rgbtGreen;
            }

            // Calculate GX*GX and GY*GY
            gxRED *= gxRED;
            gxBLUE *= gxBLUE;
            gxGREEN *= gxGREEN;
            gyRED *= gyRED;
            gyBLUE *= gyBLUE;
            gyGREEN *= gyGREEN;

            root = round(sqrt((float) (gxRED + gyRED))); // RED square root
            if (root > 255)
                root = 255;
            image[i][j].rgbtRed = root;
            root = 0;
            root = round(sqrt((float) (gxBLUE + gyBLUE))); // BLUE square root
            if (root > 255)
                root = 255;
            image[i][j].rgbtBlue = root;
            root = 0;
            root = round(sqrt((float) (gxGREEN + gyGREEN))); // GREEN square root
            if (root > 255)
                root = 255;
            image[i][j].rgbtGreen = root;
            root = 0;
        }
    }
    return;
}
