#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

/*Botwa sript*/
using namespace std;

auto main(int argc, char *argv[]) -> decltype(0)
{

    srand(static_cast<unsigned int>(time(0)));

    enum fields
    {
        WORD,
        HINT,
        NUM_FIELDS
    };
    const int NUM_WORDS = 4;
    const string WORDS[NUM_WORDS][NUM_FIELDS] = {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly. is it?"},
        {"jumble", "It's what the game is all about."}};

    int score = 0;
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    string jumble = theWord;
    string guess;

    for (int i = 0, length = jumble.size(); i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word\n";
    cout << "Enter 'hint' for a hint\n";
    cout << "Enter 'quit' to quit the game\n\n";
    cout << "The jumble is: " << jumble;
    cout << "\n\nYour guess: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
            score -= 25;
        }
        else
        {
            cout << "Sorry, thats not it";
            score -= 100;
        }
        cout << "\n\nYour guess: ";
        cin >> guess;
    }
    if (guess == theWord)
    {
        cout << "\nTHaTs it!\n";
        score += 500;
    }
    cout << "\nThanks for playing.\n";
    cout << "\nYour score is: " << score << endl;

    return 0;
}