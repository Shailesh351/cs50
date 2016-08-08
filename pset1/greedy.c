#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // remembers values
    float owed;
    int cents, q, d, n, p;
    
    printf("O hai! How much change is owed?\n");
    owed = GetFloat();
    
    // reprompt for the positive input
    while(owed < 0)
    {
        printf("How much change is owed?\n");
        owed = GetFloat();
    }
    
    // cents is total change owed in cent..
    cents = round(owed * 100);
    
    
    q = cents / 25;
    cents = cents - q * 25;
    d = cents / 10;
    cents = cents - d * 10;
    n = cents / 5;
    cents = cents - n * 5;
    p = cents / 1;
    
    printf("%d\n", (q + d + n + p));
    
}