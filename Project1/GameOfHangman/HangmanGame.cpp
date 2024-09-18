#include "randWord.h"
#include <iostream>
#include <string>

using namespace std;

void displayWord(const string& word, const string& guessedLetters);

int main()
{
    InitDictionary("word_dictionary.txt");
    cout << "Welcome to the Game of Hangman" << endl;
    
    string secretWord = ChooseRandomWord();
    string guessedLetters;
    int incorrectGuesses = 0; 
    const int MAX_GUESSES = 8;

    while (incorrectGuesses < MAX_GUESSES) 
    {
        cout << "The word appears as follows: ";
        displayWord(secretWord, guessedLetters);
        cout << "You have " << (MAX_GUESSES - incorrectGuesses) << " guess(es) left." << endl;

        char guess;
        cout << "Please try to guess a letter:";
        cin >> guess;
        guess = tolower(guess);

        if (guessedLetters.find(guess) != string::npos) 
        {
            cout << "You've already chosen that letter. Please try another one." << endl;
            continue;
        }

        guessedLetters += guess;

        if (secretWord.find(guess) != string::npos) 
        {
            cout << "WOW! Your guess is correct." << endl;
        } 
        else 
        {
            cout << "SORRY! There are no " << guess << "'s in the word." << endl;
            incorrectGuesses++;
        }

        bool allGuessed = true;
        for (char c : secretWord) 
            {
            if (guessedLetters.find(c) == string::npos) 
                {
                allGuessed = false;
                break;
                }
            }
            if (allGuessed) 
                {
                cout << "CONGRATULATIONS! You guessed the WORD: " << secretWord << endl;
                return 0;
                }
    }

    cout << "You're OUT of guesses :(  The word was: " << secretWord << endl;
    return 0;
}

void displayWord(const string& word, const string& guessedLetters) 
{
    for (char c : word) 
    {
        if (guessedLetters.find(c) != string::npos) 
        {
            cout << c;
        } 
        else 
        {
            cout << "-";
        }
    }
    cout << endl;
}
