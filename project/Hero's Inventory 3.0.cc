#include <iostream>
#include <string>
#include <vector>
/*Botwa sript*/
using namespace std;

auto main(int argc, char *argv[]) -> decltype(0)
{

    vector<string> inventory;
    vector<string>::iterator myIt;
    vector<string>::const_iterator iter;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    cout << "You have " << inventory.size() << " items.\n";

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << endl;

    cout << "\nYou trade your sword for a battle axe.";
    myIt = inventory.begin();
    *myIt = "battle axe";

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << endl;

    cout << "\nThe item name: '" << *myIt << "' has ";
    cout << myIt->size() << " letters in it\n";
    cout << "\nYour shield is destroyed in a fierce battle.";
    inventory.pop_back();

    cout << "\nYou recover a crossbow from a slain enemy.";
    inventory.insert(inventory.begin(), "crossbow");

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << endl;

    cout << "\nYour armor is destroyed in a fierce battle.";
    inventory.erase(inventory.begin() + 2);

    cout << "\nYour items:\n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter)
        cout << *iter << endl;

    cout << "\nYou were robbed of all of your possessions by a thief";
    inventory.clear();
    if (inventory.empty())
        cout << "\nYou have nothing\n";
    else
        cout << "\nYou have at least one item\n";

    return 0;
}