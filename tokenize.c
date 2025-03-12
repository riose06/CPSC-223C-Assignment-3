/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: March 13 @ 11:59pm
 * CPSC 223C Assignment 3 - Tokenizer
 * Last updated: March 12 @ 8:29am
 */

// PURPOSE: Program is intended to allow the user to seperate text from a text file 
//          of their choice into tokens. The user may enter their choice of seperators
//          as well. The program will print and label the tokens starting from 0, and 
//          then reveal the total number of tokens following the list.

// First, run "chmod u+x r.sh" in the terminal to gain access to the bash file
// Then, run "r.sh" in the terminal to run the bash program!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file2string.c"

// Removes the built-in next line (\n) when using the fgets() function
void trim(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

int main () 
{
    printf("\nWelcome to Epic Software Systems, Inc. Head of Systems Lab: Ethan Rios!\n\n");

    FILE* file_ptr;        // Internal name of the text file
    char file_name[50];    // External name of the text file
    char* file_data;       // Array of char from the text file

    // Gives user multiple chances to enter a text file in case of a typing mistake
    do 
    {
        printf("Please enter the name of a text file to be tokenized: ");
        fgets(file_name, 49, stdin);
        trim(file_name);

    }
    while ((file_ptr = fopen(file_name, "r")) == NULL);

    // Calls on the file2string function which reads and copies the data from the file into a string
    file_data = file2string(file_ptr);

    // Closes the file
    flcose(file_ptr);

    // Gets the number of characters in the string
    int data_length = strlen(file_data);

    // Print the number of bytes and contents of the file to the user
    printf("\nThank you! The size of the file you entered has %d characters.", data_length);
    printf("\nThe data from the file was copied into a string array in the program.");
    printf("\nHere is the data that was stored in an array of chars:\n\n");
    printf("%s", file_data);

    // User enters choice of seperators, extra line from input is removed
    char* tokens[50];
    char seperators[15];
    printf("\n\nPlease enter your choice of seperator characters and press enter: ");
    fgets(seperators, 14, stdin);
    trim(seperators);

    printf("Confirmation: These are the separators => %s", seperators);

    // Sets the ptr to the first instance of the seperators
    int k = 0;
    char* ptr = strtok(file_data, seperators);

    if (ptr == NULL)         // Token does not exist
    {
        printf("There are no tokens");
    }
    else                     // Token exists: continue
    {
        tokens[k] = ptr;     // First instance of seperator
        k++;

        // Loops through and finds all instances seperator occurs, and adds them to an array of tokens
        while ((ptr = strtok(NULL, seperators)) != NULL)
        {
            tokens[k] = ptr;
            k++;
        }
    }

    // Loop through the array of tokens while listing each one in the terminal
    int j = 0;
    printf("\n\nHere is the complete list of tokens:\n");
    for (; j < k; j++)
    {
        printf("Token %d: %s\n", j, tokens[j]);
    }

    // Prints the total number of tokens and conclusion
    printf("\nThe total number of tokens is %d", j);
    printf("\nThank you for using our tokenizer. Have a nice day!\n\n");
    printf("==================================== End of execution ====================================\n\n");
    
    return 0;
}
