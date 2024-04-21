#include <iostream>
/*Botwa sript*/
class Enemy {
   public:
      Enemy() : m_Damage(10) {};
      void Attack() const { 
         std::cout << "Attack inflicts " << m_Damage << " damage points!\n";
      }
   protected:
      short m_Damage;
};

class Boss : public Enemy {
   public:
      Boss() : m_DamageMul(3){};
      void SpecialAttack() const {
         std::cout << "SPECIAL Attack inflicts " << (m_DamageMul * m_Damage) << " damage points!\n";
      }
   private:
      short m_DamageMul;

};

auto main(int argc, char *argv[]) -> decltype(0) {
   std::cout << "Creating an enemy. \n";
   Enemy enemy1;
   enemy1.Attack();
   Boss boss1;
   boss1.SpecialAttack();
   boss1.Attack();
   return 0;
}