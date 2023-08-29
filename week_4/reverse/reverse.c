#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    char *infile = argv[1];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", infile);
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER wv;

    fread(&wv, sizeof(WAVHEADER), 1, inptr);
    long header_end = ftell(inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    check_format(wv);

    // Open output file for writing
    // TODO #5
    char *outfile = argv[2];

    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not open %s\n", outfile);
    }

    // Write header to file
    // TODO #6
    fwrite(&wv, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(wv);

    // Write reversed audio to file
    // TODO #8

    // Set cursor to end
    fseek(inptr, -block_size, SEEK_END);

    // Buffer for writing output file
    DWORD *buffer = NULL;


    // Read samples from input file and write updated data to output file
    for (long position = ftell(inptr); position >= header_end; position = ftell(inptr))
    {
        fread(&buffer, block_size, 1, inptr);
        fwrite(&buffer, block_size, 1, outptr);
        fseek(inptr, (-2) * (block_size), SEEK_CUR);
    }


    fclose(inptr);
    fclose(outptr);

    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    int check = 0, counter = 0;

    char *wave = "WAVE";

    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] == wave[i])
        {
            counter++;
        }
    }

    if (counter == 4)
    {
        check = 1;
    }

    return check;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block_size = (header.bitsPerSample / 8) * header.numChannels;

    return block_size;
}