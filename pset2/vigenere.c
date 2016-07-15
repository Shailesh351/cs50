#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    
    int i, j, n, N;
    
    //yells and return 1 if command line argument is not equal to 1
    if (argc == 2)
    {
        string k = argv[1];
        
        //checks that string contains non alphabetical letter or not 
        for(i = 0, n = strlen(k); i < n ; i++)
        {
           if (!(((k[i] > 64) && (k[i] < 91)) || ((k[i] > 96) && (k[i] < 123))))
            {
                printf("Key word contains non alphabetical letter\n");
                return 1;
            }
        }
        
        string p = GetString();
        
       for(i = 0, j = 0, N = strlen(p); i < N; i++, j %= n)
       {
           //if p[i] is uppercase then this block will run
            if (((p[i] > 64) && (p[i] < 91)))               
            {
                if (((k[j] > 64) && (k[j] < 91)))
                {
                    if (((p[i] + k[j] - 65)) > 90)
                    {
                        printf("%c", (((p[i] + k[j] - 65) ) - 26));
                        j++;
                    }
                    else
                    {
                        printf("%c", ((p[i] + k[j] - 65) ));
                        j++;
                    }
                }
                else if (((k[j] > 96) && (k[j] < 123)))
                {
                  if (((p[i] + k[j] - 97)) > 90)
                    {
                        printf("%c", (((p[i] + k[j] - 97) ) - 26));
                        j++;
                    }
                    else
                    {
                        printf("%c", ((p[i] + k[j] - 97) ));
                        j++;
                    }  
                }
            }
            
            //if p[i] is lowercase then this block will run 
            else if (((p[i] > 96) && (p[i] < 123)))         
            {
               if (((k[j] > 64) && (k[j] < 91)))
                {
                    if (((p[i] + k[j]) - 65) > 122)
                    {
                        printf("%c", (((p[i] + k[j] - 65) ) - 26));
                        j++;
                    }
                    else
                    {
                        printf("%c", ((p[i] + k[j] - 65) ));
                        j++;
                    }
                }
                else if (((k[j] > 96) && (k[j] < 123)))
                {
                  if (((p[i] + k[j] - 97)) > 122)
                    {
                        printf("%c", (((p[i] + k[j] ) - 97 ) - 26));
                        j++;
                    }
                    else
                    {
                        printf("%c", ((p[i] + k[j] ) - 97 ));
                        j++;
                    }  
                } 
            }
            
            // if character is not alfabet then it will print it as it is
            else                    
            {
                printf("%c", p[i]);
            }
            
       }
        
        printf("\n");
        
    }
    else
    {
        printf("Not an appropriate argument \n");
        return 1;
    }
    return 0;
    
}