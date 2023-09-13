#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: %s image\n", argv[0]);
        return 1;
    }

    // Open forensic image file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open forensic image file.\n");
        return 1;
    }

    // Variables for file handling
    FILE *output = NULL;
    char filename[8];
    unsigned char buffer[BLOCK_SIZE];
    int count = 0;
    int found_jpeg = 0;

    // Iterate over the image file
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // Check if the block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous output file
            if (output != NULL)
            {
                fclose(output);
            }

            // Create a new output file
            sprintf(filename, "%03i.jpg", count);
            output = fopen(filename, "w");
            if (output == NULL)
            {
                fclose(file);
                printf("Could not create JPEG file.\n");
                return 1;
            }

            // Write block to the output file
            fwrite(buffer, BLOCK_SIZE, 1, output);
            found_jpeg = 1;
            count++;
        }
        else if (found_jpeg)
        {
            // Continue writing blocks to the current output file
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }
    }

    // Close the last output file
    if (output != NULL)
    {
        fclose(output);
    }

    // Close the forensic image file
    fclose(file);

    return 0;
}
