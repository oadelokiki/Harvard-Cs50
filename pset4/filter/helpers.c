#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row= 0; row < height; row++)
    {
        for(int column =0; column <width ; column++)
        {
        float average = (image[row][column].rgbtRed + image[row][column].rgbtBlue + image[row][column].rgbtGreen) / 3.000;
        int avg = round(average);

        image[row][column].rgbtRed = avg;
        image[row][column].rgbtBlue = avg;
        image[row][column].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row= 0; row < height; row++)
    {
        for(int column =0; column <width ; column++)
        {
            int sepred = round(.393 * image[row][column].rgbtRed + .769 * image[row][column].rgbtGreen + .189 * image[row][column].rgbtBlue);
            int sepgreen = round(.349 * image[row][column].rgbtRed + .686 * image[row][column].rgbtGreen + .168 * image[row][column].rgbtBlue);
            int sepblue = round(.272 * image[row][column].rgbtRed + .534 * image[row][column].rgbtGreen + .131 * image[row][column].rgbtBlue);

            image[row][column].rgbtRed = (sepred > 255) ? 255 : sepred;
            image[row][column].rgbtGreen = (sepgreen > 255) ? 255 : sepgreen;
            image[row][column].rgbtBlue = (sepblue > 255) ? 255 : sepblue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width / 2 ; column++)
        {
           int red = image[row][column].rgbtRed;
           int blue = image[row][column].rgbtBlue;
           int green = image[row][column].rgbtGreen;

           image[row][column].rgbtRed = image[row][width - column - 1].rgbtRed;
           image[row][column].rgbtBlue = image[row][width - column - 1].rgbtBlue;
           image[row][column].rgbtGreen = image[row][width - column - 1].rgbtGreen;

           image[row][width - column - 1].rgbtRed = red;
           image[row][width - column - 1].rgbtBlue = blue;
           image[row][width - column - 1].rgbtGreen = green;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int row = 0; row < height; row++)
    {
        for(int column = 0; column < width ; column++)
        {
           int sumRed = 0;
           int sumBlue = 0;
           int sumGreen = 0;
           float counter = 0.00;

           for(int k = -1; k < 2; k++)
           {
               for (int h = -1; h < 2; h++)
               {
                   if(row + k < 0 || row + k > height - 1 || column + h < 0 || column + h > width - 1)
                   {
                        continue;
                   }

                   sumRed += image[row + k][column + h].rgbtRed;
                   sumBlue += image[row + k][column + h].rgbtBlue;
                   sumGreen += image[row + k][column + h].rgbtGreen;

                   counter++;

               }
           }
           temp[row][column].rgbtRed = round(sumRed/counter);
           temp[row][column].rgbtBlue = round(sumBlue/counter);
           temp[row][column].rgbtGreen = round(sumGreen/counter);
        }
    }
    for(int i = 0; i< height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;

        }
    }
    return;
}
