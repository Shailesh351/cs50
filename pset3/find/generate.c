/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    /* It prints "Usage: generate n [s]" and terminate programm with error
       code 1 if total no of arguments is not 2 or 3  */
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }
    
       
    /* Converts string of second commandline argument into integer using 
       atoi function and saves this integer in integr type variable n */
    int n = atoi(argv[1]);


    /*  if total no of argument is 3, it means seed is provided by user this will
        be converted from  string to long integer .
     *  and it will be used as argument for srand48() function.
     *  srand48() function is for initialization function and this should be 
        called before calling drand48() function.
     
     *  If seed is not provided by user block of code after else will execute
        which takes current system time in seconds as seed 
     *  this time in seconds is different after every second as time goes
        so number will be random every time .. :-)
     */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    
    /*  drand48() function returns nonnegative double-precision floating-point
        values between [0.0, 1.0).
     *  this values then multiplied by LIMIT and then type casted in int
        and it gives us numbers.
     *  this loop prints this numbers.
     */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}