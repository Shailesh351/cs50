/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include <math.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 // f is for first element,m for middle and l is for last element
bool search(int value, int values[], int n)
{
    int f, m, l;
    f = 0;
    l = n - 1;
    m = (f + l) / 2;
    
    while(f <= l)
    {
        if (values[m] < value)
        {
            f = m + 1;
        }
        else if (values[m] == value)
        {
            return true;
        }
        else 
        {
            l = m - 1;
        }
        m = (f + l) / 2;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if (values[j] > values[j + 1] )
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    return;
}