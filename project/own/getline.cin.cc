#include <iostream>
#include <string>
/*Botwa sript*/
auto main(int argc, char *argv[]) -> decltype(0) {

   std::string name;
   getline(std::cin, name);
   std::cout<<name;
   const unsigned char max_length = 100;
   char text[max_length]{};
   std::cin.getline(text, max_length, '!');
   std::cout << text << std::endl;


   return 0;
}