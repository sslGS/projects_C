#include <iostream>
/*Botwa sript*/
typedef unsigned short bit;
class Creature {
   public:
      Creature(bit health = 100) : m_Health(health){};
      virtual void Greet() const{};
      virtual void DisplayHealth() const {
         std::cout << "Health " << m_Health << std::endl;
      };
   protected:
      bit m_Health{};

};

class Orc : public Creature {
   public:
      Orc(bit health = 120) : Creature(health) {};
      virtual void Greet() const {
         std::cout << "The orc grunts hello\n";
      };
};


auto main(int argc, char *argv[]) -> decltype(0) {
   Creature *pCreature = new Orc();
   pCreature->Greet();
   pCreature->DisplayHealth();
   return 0;
}