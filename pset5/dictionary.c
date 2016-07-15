/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Implementing a trie datastructure
typedef struct node
{
    bool isAword;
    struct node* children[27];
}
node;

node* firstNode;

// total number of words counter
int numberOfWords = 0;

// function to freenode
void freenode(node* firstNode)
{
    for(int i = 0; i < 27; i++)
    {
        if (firstNode->children[i] != NULL)
        {
            freenode(firstNode->children[i]);
        }
    }
    free(firstNode);
    return;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // letter as int+
    int aAsInt = (int)'a';
    int zAsInt = (int)'z';
    
    // set current node to first node
    node* currentNode = firstNode;
    
    // looping through each letter in word
    int i = 0;
    while(word[i] != '\0')
    {
        char ch = word[i];

        // find is ch is apostrophe
        if (word[i] == '\'')
        {
            ch = zAsInt + 1;
        }
        
        // converting letter between 0 and 25
        int childIndex = tolower(ch) - aAsInt;
        
        if (currentNode->children[childIndex] != NULL)
        {
            currentNode = currentNode->children[childIndex];
            i++;
        }
        else
        {
            return false;
        }
        
    }
    
    if (currentNode->isAword == true)
    {
        
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    // integer mapping for a and z
    int aAsInt = (int)'a';
    int zAsInt = (int)'z';
   
    // opening the dictionary file
    FILE* fp = fopen(dictionary,"r");
   
    // sanity check for null returned reference
    if (fp == NULL)
    {
        return false;
    }
    
    // mallocking memory for first node
    firstNode = (node*) malloc(sizeof(node));
   
    // cursor node
    node* currentNode= firstNode;
    
    int index = 0, words = 0;
    char word[LENGTH+1];
   
    // looping through dictionary until end of file is encountered
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // allow only alphabetical characters and apostrophes
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // append character to word
            word[index] = c;
            index++;

            // ignore alphabetical strings too long to be words
            if (index > LENGTH)
            {
                // consume remainder of alphabetical string
                while ((c = fgetc(fp)) != EOF && isalpha(c));

                // prepare for new word
                index = 0;
            }
        }

        // we must have found a whole word
        else if (c == '\n')
        {
            // terminate current word
            word[index] = '\0';
            
            for(index = 0; word[index] != '\0'; index++)
            {
                if (word[index] == '\'')
                {
                    word[index] = zAsInt + 1;
                }
                
                // if the character is not in trie...create one
           		if (currentNode->children[word[index] - aAsInt] == NULL)
           		{
           		        currentNode->children[word[index] - aAsInt] = (node*)malloc(sizeof(node));
           			    currentNode = currentNode->children[word[index] - aAsInt];
           		}
           		else
           		{
           			    currentNode = currentNode->children[word[index] - aAsInt];
           		}
            }
            
            currentNode->isAword = true;
            
            // update counter
            numberOfWords++;
            words++;

            // prepare for next word
            index = 0;
            
            currentNode = firstNode;
        }
    }
       
    // close the dictionary file
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return numberOfWords;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* currentNode = firstNode;
    freenode(currentNode);
    return true;
}
