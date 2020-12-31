#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void)
{
    float index = 0;
    float words = 0;
    float sentences = 0;
    float letters = 0;
    string text = get_string("Text:");
    if(strlen(text) > 0)
    {
        words += 1;
    }
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ' || text[i] == '\0')
        {
            words++;
        }
        if((text[i] == '.' || text[i] == '!' || text[i] == '?') && text[i+1] != '.' )
        {
            sentences++;
        }
        if((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
          letters++;
        }

    }
    ///index = 0.0588 * L - 0.296 * S - 15.8
    if(words < 100)
    {
        words = 100/ words;
    }
    if(words > 100)
    {
        words = words / 100;
    }
    index = 0.0588 * (letters * words) - 0.296 * (sentences * words) - 15.8;

    index = round(index);
    int grade = (int)index;
    ///printf("Words: %f\n", words);
    //printf("letters: %f\n", letters);
   // printf("sentences: %f\n", sentences);
    if(grade < 1)
    {
        printf("Before Grade 1\n");
        return 1;
    }
    if(grade >= 16)
    {
        printf("Grade 16+ \n");
        return 1;
    }
    else
    {
        printf("Grade %i\n", grade);

    }
}

