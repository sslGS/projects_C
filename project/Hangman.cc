#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cctype>
/*Botwa sript*/
using namespace std;
vector<string> words;
const int MAX_WRONG = 8;

void randomizingWord()
{
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
}

void game()
{
    const string THE_WORD = words[0];
    char guess;
    int wrong = 0;
    string soFar(THE_WORD.size(), '-');
    string used = "";
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\n\nYou have " << (MAX_WRONG - wrong);
        cout << " inncorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n"
             << used << endl;
        cout << "\nSo far, the word is:\n"
             << soFar << endl;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess);

        while (used.find(guess) != string::npos)
        {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;
        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "Thats right! " << guess << " is in the word\n";
            for (int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                    soFar[i] = guess;
            }
        }
        else
        {
            cout << "Sorry, " << guess << " isnt in the word\n";
            ++wrong;
        }
    }
    if (wrong == MAX_WRONG)
        cout << "\nYou've been hanged!";
    else
        cout << "\nYou guessed it!";
    cout << "\nThe word was " << THE_WORD << endl;
}

auto main(int argc, char *argv[]) -> decltype(0)
{
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    randomizingWord();
    cout << "Welcome to Hangman. Good Luck!\n";
    game();
    return 0;
}