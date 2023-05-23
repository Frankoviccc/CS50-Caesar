#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char rotate(char letter, int key);

// Declare const int above main
const int ALPHABET_SIZE = 26;
const char a = 'a';
const char A = 'A';

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");    // Bij invoeren van twee argumenten print, anders reprompt
        return 1;
    }

    string key_string = argv[1]; // Sla invoer op in variabel key_string

    for (int i = 0; i < strlen(key_string); i++)
    {
        if (isdigit(key_string[i]))
        {
            // Itereer door key_string en ga door zolang invoer cijfers zijn
            continue;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(key_string); // Maak van ingevoerde string een int

    string text = get_string("Plaintext: ");

    printf("Ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        char plainchar = text[i];   // Gebruik gecreerde functie op ingevoerde tekst
        char rotatedchar = rotate(plainchar, key);
        printf("%c", rotatedchar);
    }
    printf("\n");


}

char rotate(char letter, int key)
{

    // char letter_base_zero = letter - a;
    // char letter_plus_key = letter_base_zero + key;
    // char modulo_alphabet = letter_plus_key % 26;
    // char letter_base_normal = modulo_alphabet + a;

    char rotated_char;

    if (islower(letter))
    {
        rotated_char = (((letter - a) + key) % ALPHABET_SIZE) + a;
    }
    else if (isupper(letter))
    {
        rotated_char = (((letter - A) + key) % ALPHABET_SIZE) + A;
    }
    else
    {
        rotated_char = letter;
    }

    return rotated_char;
}