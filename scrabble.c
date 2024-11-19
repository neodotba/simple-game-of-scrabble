#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int calculate_score(string word);

int main(void)
{
    // Gets inputs from both players.
    string first_word = get_string("Enter the first word: ");
    string second_word = get_string("Enter the second word: ");

    // Calculates the scores for both words.
    int score1 = calculate_score(first_word);
    int score2 = calculate_score(second_word);

    // Checks which player wins based on calclulated score from "first_word" or "second_word" -
    // greater score = win, equal score = tie.
    if (score1 > score2)
    {
        printf("Player 1 wins! ");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins! ");
    }
    else
    {
        printf("Tie!");
    }
}

// Funcion for calculating the score of inputed word based on points array for each letter of the
// word.
int calculate_score(string word)
{
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += points[word[i] - 'a'];
        }
    }
    return score;
}
