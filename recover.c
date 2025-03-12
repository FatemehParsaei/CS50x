#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Written By Fatemeh Parsaei
// August 2024

// Number of bytes in a block of data
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[BLOCK_SIZE];

    // String to hold names of output files
    char filename[8] = {0};

    // Create Output file
    FILE *output = NULL;

    // Holds number of found jpeg files
    int foundJPg = 0;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous output file that is open
            if (output != NULL)
                fclose(output);

            sprintf(filename, "%03i.jpg", foundJPg++);

            // Open new output file
            output = fopen(filename, "w");
        }

        // Write new output file that is open & at last write the rest of input file card
        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    // close output file
    if (output != NULL)
    {
        fclose(output);
    }

    // Close the input file
    fclose(card);
    return 0;
}
