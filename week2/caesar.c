// caesar.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Caesar Cipher
// ------------------------
// Encrypt a message by rotating each letter forward in the alphabet
// by a numeric key given as a command-line argument.
//
//   Example (key = 3):  A→D, B→E, Z→C (wraps around)
//   "hello" → "khoor"
//
// Usage:
//   ./caesar KEY       (KEY must be a non-negative integer)
//   ./caesar           → prints usage error
//   ./caesar abc       → prints usage error
//
// How to compile:  make caesar
// How to run:      ./caesar 13
// How to check:    check50 cs50/problems/2024/x/caesar

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if(argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    for(int i = 0; i < strlen(plaintext); i++)
    {
        char encrypted = rotate(plaintext[i], key);
        printf("%c", encrypted);
    }
    printf("\n");
    return 0;
}

bool only_digits(string s)
{
    for(int i = 0; i < strlen(s); i++)
    {
        if(!isdigit(s[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char c, int n)
{
    if(isupper(c))
    {
        return (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        return (c - 'a' + n) % 26 + 'a';
    }
    else
    {
         return c;
    }
}
