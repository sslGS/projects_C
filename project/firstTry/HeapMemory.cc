#include <iostream>
/*Botwa sript*/
int *intOnHeap();
void leak1();
void leak2();

auto main(int argc, char *argv[]) -> decltype(0) {
   int *pHeap = new int;
   *pHeap = 10;
   std::cout << *pHeap << std::endl;
   int *pHeap2 = intOnHeap();
   std::cout << *pHeap2 << std::endl;
   delete pHeap;
   delete pHeap2;
   pHeap = 0;
   pHeap2 = 0;
   return 0;
}

int *intOnHeap() {
   int *pTemp = new int(20);
   return pTemp;
}

void leak1() {int *drip1 = new int(30);}
void leak2() {
   int *drip2 = new int(50);
   drip2 = new int(100);
   delete drip2;
}