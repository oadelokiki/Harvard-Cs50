#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <stdbool.h>

const int BLOCKSIZE = 512;
bool jpegheader(uint8_t storage[])
{
    return storage[0] == 0xff
        && storage[1] == 0xd8
        && storage[2] == 0xff
        && (storage[3] & 0xf0) == 0xe0;
    ///^checks whether the first 4 bytes of the "jpeg" file are the proper header for file in question
}
int main(int argc,char* argv[])
{
    bool verif = true;
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    ///^checks if there's one comm line argument
    FILE *jpegfile = fopen(argv[1], "r");
    if(jpegfile == NULL)
    {
        printf("File not found!");
        return 1;
    }
    ///^verifies that the file isn't empty
    char filename[8];
    FILE* outputptr = NULL;
    uint8_t storage[BLOCKSIZE];
    int jpgcounter = 0;
    ///^Creates A file called outputptr
    while(fread(storage, sizeof(char), 512, jpegfile)|| feof(jpegfile) == 0)
    {
        if(jpegheader(storage))
        {
            if(outputptr != NULL)
            {
                fclose(outputptr);
            }
            sprintf(filename,"%03i.jpg", jpgcounter);\
            outputptr = fopen(filename, "w");
            jpgcounter++;

        }
        if(outputptr != NULL)
        {
            fwrite(storage, sizeof(storage), 1, outputptr);
        }
    }
    if(outputptr == NULL)
    {
        fclose(outputptr);
    }
    if(jpegfile == NULL)
    {
        fclose(jpegfile);
    }

    ///reads the file to a variable "storage"
    return 0;
}