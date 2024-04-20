#include <iostream>
/*Botwa sript*/
auto main(int argc, char *argv[]) -> decltype(0) {
    unsigned short *array = new unsigned short[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(unsigned char i{}; i < 10; ++i) {
        std::cout << array[i]<< std::endl;
    } delete[] array;

    return 0;
}