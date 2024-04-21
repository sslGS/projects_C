#include <iostream>
#include <string>
/*Botwa sript*/
class Critter {
   friend void Peek(const Critter &aCritter);
   friend std::ostream& operator <<(std::ostream &os, const Critter &aCritter);
   public:
      Critter(const std::string &name = "");
   private:
      std::string m_Name;
};

Critter::Critter(const std::string &name) : m_Name(name){}

void Peek(const Critter &aCritter);
std::ostream &operator <<(std::ostream &os, const Critter &aCritter);

auto main(int argc, char *argv[]) -> decltype(0) {
   Critter crit("Poochie");
   Peek(crit);
   std::cout << crit;
   return 0;
}

void Peek(const Critter &aCritter) {
   std::cout << aCritter.m_Name << std::endl;
}

std::ostream &operator <<(std::ostream &os, const Critter &aCritter) {
   os << "Critter Object -";
   os << aCritter.m_Name;
   return os;
}