#include <iostream>
/*Botwa sript*/

auto main(int argc, char *argv[]) -> decltype(0)
{
    // int a = 10;
    // int &b = a;
    // int *c = &b;
    // std::cout << &a << std::endl;
    // std::cout << &b << std::endl;
    // std::cout << &(*c) << std::endl;

    unsigned short a{15}, b{12};
    unsigned short *p{}, *&pRef{p};
    pRef = &a;
    std::cout << *p << std::endl;
    *pRef = 70;
    std::cout << a << std::endl;
    pRef = &b;
    std::cout << *p << std::endl;

    char c {'N'};
    char *pc {&c};
    short *pd {(short *)pc};
    void *pv{(void *)pc};
    std::cout << pv << std::endl;
    std::cout << pd << std::endl;
    return 0;
}
