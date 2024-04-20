#include <iostream>
/*Botwa sript*/

void increase(int *const array, const int NUM_ELEMENTS);
void display(const int *const array, const int NUM_ELEMENTS);

auto main(int argc, char *argv[]) -> decltype(0)
{
    std::cout << "Creating" << std::endl;
    int highScores[] = {5000, 3500, 2700};
    int NUM_SCORES = sizeof(highScores) / sizeof(int);
    std::cout << "Display" << std::endl;
    std::cout << *highScores << std::endl;
    std::cout << *(highScores + 1) << std::endl;
    std::cout << *(highScores + 2) << '\n';
    std::cout << "Increasing" << std::endl;
    increase(highScores, NUM_SCORES);
    std::cout << "Display" << std::endl;
    display(highScores, NUM_SCORES);
    return 0;
}

void increase(int *const array, const int NUM_ELEMENTS)
{
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        array[i] += 500;
    }
}
void display(const int *const array, const int NUM_ELEMENTS)
{
    for (int i = 0; i < NUM_ELEMENTS; ++i)
    {
        std::cout << array[i] << std::endl;
    }
}