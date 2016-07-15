#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes;
    printf("minutes: ");
    
    // takes user input for shower in minutes..
    minutes = GetInt();
    
    // prints shower in bottles..
    printf("bottles: %d\n", (minutes * 12));
}