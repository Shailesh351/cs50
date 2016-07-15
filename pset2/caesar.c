#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i, n;
    
    //yells and return 1 if argument is not equal to 1
    if (argc != 2)
    {
        printf("Usage: caesar s\n");
        return 1;
    }
    
    int k = atoi(argv[1]);          //typecasting of string into integer using atoi function
    
    //convert value of key into equavalant integer from 0 to 25.
    while(k > 26)
    {
        k %= 26;
    }
    
    string p = GetString();
    
    //this loop is for printing chipher text 
    for(i = 0, n = strlen(p) ; i < n ; i++)
    {
        
        
        if (((p[i] > 64) && (p[i] < 91)))               //if p[i] is uppercase then this block will run
        {
            if ((p[i] + k) > 90)
            {
                printf("%c",(p[i] + k - 26));
            }
            else
            {
                printf("%c",(p[i] + k));
            }
        }
        else if (((p[i] > 96) && (p[i] < 123)))         //if p[i] is lowercase then this block will run 
        {
           if ((p[i] + k) > 122)
            {
                printf("%c",(p[i] + k - 26));
            }
            else
            {
                printf("%c",(p[i] + k));
            } 
        }
        else                    // if character is not alfabet then it will print it as it is
        {
            printf("%c",p[i]);
        }
        
    }
    printf("\n");
    
    return 0;
}