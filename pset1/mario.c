#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    int h, i, j;
    
    // takes user input for height of pyrimid..
    printf("Height: ");
    h = GetInt();
    
    // ask for hight again and again for valid height thai is positive integer less than or equal to 23..
    while((h < 0) || (h > 23))
    {
      printf("Height: ");
      h = GetInt();  
    }
    
    // prints pyramid
    for(i = 1; i <= h ; i++)
    {
       for(j = 1;j <= h - i ; j++)
       {
           printf(" ");
       }
       for(j = 1 ; j <= i + 1;j++)
       {
           printf("#");
       }
       printf("\n");
    }
}