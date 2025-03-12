/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: March 13 @ 11:59pm
 * CPSC 223C Assignment 3 - Tokenizer
 * Last updated: March 12 @ 8:28am
 */

// PURPOSE: Program is intended to allow the user to seperate text from a text file 
//          of their choice into tokens. The user may enter their choice of seperators
//          as well. The program will print and label the tokens starting from 0, and 
//          then reveal the total number of tokens following the list.

// First, run "chmod u+x r.sh" in the terminal to gain access to the bash file
// Then, run "r.sh" in the terminal to run the bash program!!

#include <stdio.h>
#include <stdlib.h>

char* file2string(FILE* fileptr)
    { 
        char* data;

        // Set file_ptr to the end of the text file
        // Use malloc to copy the size of the text file to file_data (create space)
        fseek(fileptr, 0, SEEK_END);
        data = (char*) malloc ((ftell(fileptr) + 1) * sizeof(char));

        // Set file_ptr to the start of the text file
        rewind(fileptr);

        // Loop through the text file, copying each character
        // from file_ptr into the array file_data
        char c;
        int i;
        for (i = 0; (c = fgetc(fileptr)) != EOF; i++) 
        {
            data[i] = c;
        }

        data[i] = '\0';  // Array terminates with null

        return data;
    }
