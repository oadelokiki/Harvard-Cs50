#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void charloop(char x,int times)
{
    for(int i = 0; i < times; i++)
    {printf("%c", x);}

}

int main(void)
{
    int height = get_int("Height:");
    while(height <= 0 || height >=9)
    {
        height = get_int("Height:");
    }

    int space = 0;
    int max=height;
    if (height<0){
    }
    while(height>0)
    {
        height--;
        space++;
        charloop(' ',abs(max-space));charloop('#', abs(max - height));printf("  "); charloop('#', abs((max - height)));charloop(' ', abs(max-space));
        printf("\n");
    }
}


