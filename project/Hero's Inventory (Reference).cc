#include <iostream>
#include <string>
#include <vector>
/*Botwa sript*/
using namespace std;

void display(const vector<string> &vec)
{
    cout << "Your items:\n";
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout << *i << endl;
    }
}

auto main(int argc, char *argv[]) -> decltype(0)
{
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shields");
    display(inventory);
    return 0;
}