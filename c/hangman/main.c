#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "words.h"
#define MAXGUESSES 8

// Variables used in functions
char wrong_guess_list[MAXGUESSES];
int guesses;

int isLetterGuessed(char x)
{
    for (int i = 0; i < MAXGUESSES; i++)
    {
        if (x == wrong_guess_list[i])
        {
            return 1;
        }
    }
    return 0;
}

void printWrongGuessList()
{
    printf("Wrong Guesses: [");
    for (int i = 0; i < MAXGUESSES; i++)
    {
        if (wrong_guess_list[i] != '\0')
            printf("%c, ", wrong_guess_list[i]);
    }
    printf("]\n%d wrong guesses left\n\n", MAXGUESSES - guesses + 1);
}

void clear()
{
    printf("\e[1;1H\e[2J");
}

int main()
{
    srand(time(NULL));
    // Reset global variables
    guesses = 0;
    memset(wrong_guess_list, '\0', MAXGUESSES);
    // Variables
    int r_index = rand() % (sizeof(words) / sizeof(words[0]));
    char *answer = words[r_index];
    int len_answer = strlen(answer);
    char answer_arr[len_answer], correct_arr[len_answer];
    int word_found = 0;
    char guess, correct;

    // Print answer
    // printf("%s\n", answer);

    // Converts answer into an array and fills correct_guess with "_"
    for (int i = 0; i <= len_answer - 1; i++)
    {
        answer_arr[i] = answer[i];
        correct_arr[i] = '_';
    }

    printf("Guess this %d letter word, good luck!\n\n", len_answer);

    while (guesses <= MAXGUESSES && word_found == 0)
    {
        printWrongGuessList();
        // Print the current correct_arr
        for (int i = 0; i < len_answer; i++)
        {
            printf("%c ", correct_arr[i]);
        }

        // Input letter
        printf("\n\nEnter a letter: ");
        scanf(" %c", &guess);
        guesses++;

        // Clear the console
        clear();

        // Check if letter was already entered
        if (isLetterGuessed(guess))
        {
            printf("You already entered that letter!\n");
            guesses--;
        }

        word_found = 1;
        correct = 0;
        for (int i = 0; i < len_answer; i++)
        {
            // If letter in answer array add it to correct_arr
            if (answer_arr[i] == guess)
            {
                correct_arr[i] = guess;
                correct = 1;
            }

            // Check if word is found
            if (correct_arr[i] == '_')
                word_found = 0;
        }

        // If the letter is new add it to the guess list
        if (!isLetterGuessed(guess) && !correct)
            wrong_guess_list[guesses - 1] = guess;

        // Prevents guesses from increasing at a new correct letter
        if (correct)
            guesses--;
    }

    if (guesses > MAXGUESSES)
    {
        printf("\nYou LOST: ran out of guesses\n");
    }
    else
    {
        printf("\nYou WON!\n");
    }

    printf("The word was: %s \n", answer);

    // system("pause");

    char again;
    printf("\nPlay again? (y/n) ");
    scanf(" %c", &again);

    if (again == 'y')
    {
        clear();
        main();
    }

    return 0;
}
