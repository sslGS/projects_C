#include <iostream>
/*Botwa sript*/
void badSwap(int x, int y);
void goodSwap(int *const pX, int *const pY);
auto main(int argc, char *argv[]) -> decltype(0)
{
    int myScore = 150;
    int yourScore = 1000;
    std::cout << "Original values\n";
    std::cout << "Myscore:" << myScore << std::endl;
    std::cout << "Your score:" << yourScore << std::endl;
    badSwap(myScore, yourScore);
    std::cout << "Myscore:" << myScore << std::endl;
    std::cout << "Your score:" << yourScore << std::endl;
    goodSwap(&myScore, &yourScore);
    std::cout << "Myscore:" << myScore << std::endl;
    std::cout << "Your score:" << yourScore << std::endl;
    return 0;
}

void badSwap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap(int *const pX, int *const pY)
{
    int temp = *pX;
    *pX = *pY;
    *pY = temp;
}