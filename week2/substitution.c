// substitution.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Substitution Cipher
// ------------------------------
// Encrypt a message using a 26-character substitution key.
// Each letter in the key maps to the corresponding letter of the alphabet:
//   Key:  VCHPRZGJNTLSKFBDQWAXEUYMOI
//   A→V, B→C, C→H, D→P, E→R, F→Z, ...
//
// Usage:
//   ./substitution KEY    (KEY = 26 unique letters, case-insensitive)
//   ./substitution        → prints usage error
//   ./substitution ABCD   → prints usage error (not 26 chars)
//   ./substitution AABCDE...  → prints usage error (duplicate letters)
//
// How to compile:  make substitution
// How to run:      ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
// How to check:    check50 cs50/problems/2024/x/substitution

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool is_valid_key(string key);

int main(int argc, string argv[])
{
    // STEP 1: Validate command-line arguments
    if(argc != 2 || !is_valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // STEP 2: Get the plaintext from the user
    string plaintext = get_string("plaintext:  ");

    // STEP 3: Encrypt and print ciphertext
    printf("ciphertext: ");

    for(int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if(isalpha(c))
        {
            int position;
            if(isupper(c))
            {
                position = c - 'A';
            }
            else
            {
                position = c -'a';
            }

            char substituted = argv[1][position];

            if(isupper(c))
            {
                printf("%c", toupper(subtituted));
            }
            else
            {
                printf("%c", tolower(substituted));
            }
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

// ---------------------------------------------------------------------------
// TODO: Implement is_valid_key
// ---------------------------------------------------------------------------
// Return true if the key is valid, false otherwise.
//
// A valid key:
//   1. Is exactly 26 characters long
//   2. Contains only alphabetic characters (no digits, spaces, symbols)
//   3. Contains each letter exactly once (no duplicates — case-insensitive)
//
// Hints:
//   - strlen(key) == 26
//   - isalpha(key[i]) to check each character
//   - To check for duplicates, use a boolean array of size 26:
//       bool seen[26] = {false};
//     Then for each character, check if seen[tolower(c) - 'a'] is already true.
//     If yes → duplicate found → return false
//     If no  → mark it as seen and continue
// ---------------------------------------------------------------------------
bool is_valid_key(string key)
{
    // TODO: Check length is 26
    if (strlen(key) != 26)
    {
        return false;
    }

    // TODO: Check all characters are alphabetic
    // TODO: Check for duplicates using a seen[] array

    return true; // placeholder — replace this
}
