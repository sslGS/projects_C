#include <iostream>
/*Botwa sript*/
typedef unsigned short bit;
class Enemy {
   public:
      Enemy(bit damage = 10) : m_Damage(damage){};
      void virtual Taunt() const{
         std::cout << "Your loser!" << std::endl;
      };
      void virtual Attack() const{
         std::cout << "Attack " << m_Damage << std::endl;
      };
   public:
      bit m_Damage{};
};

class Boss : public Enemy {
   public:
      Boss(bit damage = 30) : Enemy(damage){};
      void virtual Taunt() const{
         std::cout << "Your loser!!!" << std::endl;
      };
      void virtual Attack() const{
         std::cout << "Attack " << m_Damage << std::endl;
         std::cout << "ILL KILL YOU!" << std::endl;
      };
};
auto main(int argc, char *argv[]) -> decltype(0) {
   Enemy enemy1;
   enemy1.Attack();
   enemy1.Taunt();
   Boss boss1;
   boss1.Attack();
   boss1.Taunt();
   return 0;
}