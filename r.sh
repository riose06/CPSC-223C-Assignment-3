#!/bin/bash

# Author: Ethan Rios
# CWID: 880071006
# Email: eirios@csu.fullerton.edu
# Due: March 13 @ 11:59pm
# CPSC 223C Assignment 3 - Tokenizer

# PURPOSE: Program is intended to allow the user to seperate text from a text file 
#          of their choice into tokens. The user may enter their choice of seperators
#          as well. The program will print and label the tokens starting from 0, and 
#          then reveal the total number of tokens following the list.

echo "Remove unnecessary files"
rm -f main.o main.out

echo "Compile main.c"
gcc -Wall -m64 -no-pie -o main.out tokenize.c -std=c17 -fno-use-linker-plugin

# Make sure the executable has permission to execute
chmod u+x r.sh
chmod u+x main.out

echo "Run the program Tokenizer:"
./main.out

echo "The script file will terminate"