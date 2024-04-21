#include <iostream>
/*Botwa sript*/
typedef unsigned short bit;
class Enemy {
   public:
      Enemy(bit damage = 10){
         m_pDamage = new bit(damage);
      };

      virtual ~Enemy() {
         std::cout << "Destructor\n";
         delete m_pDamage;
         m_pDamage = nullptr;
      };

      void virtual Attack() const{
         std::cout << "Attack " << *m_pDamage << std::endl;
      };
   protected:
      bit *m_pDamage{};
};

class Boss : public Enemy {
   public:
      Boss(bit mul = 3) {
         m_pDamageMul = new bit(mul);
      };

      virtual ~Boss() {
         std::cout << "Destructor\n";
         delete m_pDamageMul;
         m_pDamageMul = nullptr;
      }

      void virtual Attack() const{
         std::cout << "Attack " << (*m_pDamage) * (*m_pDamageMul) << std::endl;
         std::cout << "ILL KILL YOU!" << std::endl;
      };

      protected:
         bit *m_pDamageMul;
};
auto main(int argc, char *argv[]) -> decltype(0) {
   Enemy *pBadGuy = new Boss();
   pBadGuy->Attack();
   delete pBadGuy;
   pBadGuy = nullptr;
   return 0;
}