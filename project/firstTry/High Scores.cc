#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
/*Botwa sript*/
using namespace std;

vector<int>::const_iterator iter;
vector<int> scores;

void checkScore()
{
    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter != scores.end(); ++iter)
    {
        cout << *iter << endl;
    }
}

void findScore()
{
    int score;
    cout << "\nFinding a score: ";
    cin >> score;
    iter = find(scores.begin(), scores.end(), score);
    if (iter != scores.end())
    {
        cout << "Score found.\n";
    }
    else
    {
        cout << "Score not found.\n";
    }
}

void randomizingScore()
{
    cout << "\nRandomizing scores.";
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(scores.begin(), scores.end());
}

void sortScore()
{
    cout << "\nSorting scores.";
    sort(scores.begin(), scores.end());
}
auto main(int argc, char *argv[]) -> decltype(0)
{

    cout << "Creating a list of scores.";
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);

    checkScore();
    findScore();
    randomizingScore();
    checkScore();
    sortScore();
    checkScore();

    return 0;
}