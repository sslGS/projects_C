#include <iostream>
#include <string>
#include <vector>
/*Botwa sript*/

std::string *ptrToElement(std::vector<std::string> *const pVec, int i);
auto main(int argc, char *argv[]) -> decltype(0)
{
    std::vector<std::string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");

    std::cout << *(ptrToElement(&inventory, 0)) << std::endl;
    std::string *pStr = ptrToElement(&inventory, 1);
    std::cout << *pStr << std::endl;
    std::string str = *(ptrToElement(&inventory, 2));
    std::cout << str << std::endl;
    *pStr = "Healthing Potion";
    std::cout << inventory[1] << std::endl;
    return 0;
}

std::string *ptrToElement(std::vector<std::string> *const pVec, int i)
{
    return &((*pVec)[i]);
}