#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cipherval = 0;
int main(int argc,string argv[])
{
    bool verif = true;
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    for(int i=0;i < strlen(argv[1]);i++)
    {
        if(isdigit(argv[1][i]))
        {
            verif = true;
        }
        else
        {
            verif = false;
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    int num = atoi(argv[1]);
//Verification Process above :)
    char key = (char)argv[1];
    int keys = (int)key;
    string plaintext = get_string("plaintext:");
    string ciphertext = plaintext;
    for (int i=0;i < strlen(plaintext); i++)
    {
        int ascival = (int)plaintext[i];
        if(ascival >= 65 && ascival <= 90)
        {
            cipherval = 90 - ascival;
            cipherval = 25 - cipherval;
            cipherval += num;
            cipherval = cipherval % 26;
            cipherval += 65;
            char cipher = (char)cipherval;
            ciphertext[i] = cipher;
        }
        if(ascival >= 97 && ascival <= 122)
        {
            cipherval = 122 - ascival;
            cipherval = 25 - cipherval;
            cipherval += num;
            cipherval = cipherval % 26;
            cipherval += 97;
            char cipher = (char)cipherval;
            ciphertext[i] = cipher;
        }
        if(ascival < 97 && ascival < 65 )
        {
            cipherval = ascival;
            char cipher = (char)cipherval;
            ciphertext[i] = cipher;
        }
        if(ascival > 122 && ascival > 97 )
        {
            cipherval = ascival;
            char cipher = (char)cipherval;
            ciphertext[i] = cipher;
        }
    }
    printf("ciphertext: %s\n",ciphertext);
}
