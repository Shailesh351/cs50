#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i, len;
    string name;
    name = GetString();
    
    // this is for counting length of string
    for(len = 1; name[len] != '\0'; len++);   
    
    /** it will check first character of string if it is alfabet then converts 
     * it in uppercase
     */
    if (((name[0] <= 'z') && (name[0] >= 'a')) || 
        ((name[0] >= 'A') && (name[0] <= 'Z')))
    {
        
        if ((name[0] <= 'z') && (name[0] >= 'a')) 
        {
            printf("%c", name[0] - 32);
        }
        else if ((name[0] >= 'A') && (name[0] <= 'Z'))
        {
            printf("%c", name[0]);
        }
        
    }
    
    
    //this loop checks for space and is space is recognized then it will convert next character in uppercase
    for(i = 0; i < len; i++){
        
        if (name[i] == ' '){
            
            if ((name[i + 1] <= 'z') && (name[i + 1] >= 'a')){
                 printf("%c", name[i + 1] - 32);
            }
            else if ((name[i + 1] >= 'A') && (name[i + 1] <= 'Z')){
                printf("%c", name[i + 1]);
            }
            
        }
        
    }
    printf("\n");
}