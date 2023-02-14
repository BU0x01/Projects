
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

// Batbilegt Ulziibayar (800697683), 09/09/2022, program1

using namespace std;

string RandomWord();
int RandomChoice();
string Game(string word);

const int size = 5000;

int main()
{
    while (1)
    {
        Game(RandomWord());
        cout << endl;
    }
    return 0;
}

string RandomWord()
{
    string line, word;
    int random = RandomChoice();
    int count = 1;
    ifstream file01("dictionary.txt");
    while (getline(file01, line))
    {
        if (random == count)
        {
            word = line;
            break;
        }
        count++;
    }

    return word;
}

int RandomChoice()
{
    srand(time(NULL));
    int random;
    random = (rand() % 80000);
    return random;
}

string Game(string word)
{
    int misses = 5;
    string hiddenWord = word;
    for (int i = 0; i < (hiddenWord.length() - 1); i++)
    {
        hiddenWord[i] = '*';
    }

    while (misses != 0)
    {
        char guess;
        cout << "Word: " << hiddenWord << endl;
        cout << "Guesses left: " << misses << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        bool correctGuess = false;

        for (int i = 0; i < word.length(); i++)
        {
            if (guess == word[i])
            {
                hiddenWord[i] = word[i];
                correctGuess = true;
            }
        }

        if (!correctGuess)
        {
            misses--;
            cout << "Miss" << endl;
        }
    }
    if (misses == 0)
    {
        cout << "Too bad! You ran out of guesses" << endl;
    }
    else
    {
        cout << "Nice! You found the secret word!" << endl;
    }
    cout << "The word was " << word << endl;
    return hiddenWord;
}