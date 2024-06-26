#include <iostream>
#include <string>
/*Botwa sript*/
class Critter {
   public:
      Critter(const std::string &name = "", int age = 0);
      ~Critter();
      Critter(const Critter &c);
      Critter &operator=(const Critter &c);
      void Greet() const;
   private:
      std::string *m_pName;
      int m_Age;
};

Critter::Critter(const std::string &name, int age) {
   std::cout << "Called\n";
   m_pName = new std::string(name);
   m_Age = age;
}

Critter::~Critter() {
   std::cout << "Destructor\n";
   delete m_pName;
}

Critter::Critter(const Critter &c) {
   std::cout << "Copy Constructor called\n";
   m_pName = new std::string(*(c.m_pName));
   m_Age = c.m_Age;
}

Critter &Critter::operator=(const Critter &c) {
   std::cout << "Overload\n";
   if(this != &c) {
      delete m_pName;
      m_pName = new std::string(*(c.m_pName));
      m_Age = c.m_Age;
   }
   return *this;
}

void Critter::Greet() const {
   std::cout << *m_pName << '\t' << m_Age;
   std::cout << &m_pName << std::endl;
}

void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

auto main(int argc, char *argv[]) -> decltype(0) {
   testDestructor();
	std::cout << std::endl;
	
	Critter crit("Poochie", 5);
	crit.Greet();
	testCopyConstructor(crit);
	crit.Greet();
	std::cout << std::endl;
	
	testAssignmentOp();
   return 0;
}

void testDestructor()
{
	Critter toDestroy("Rover", 3);
	toDestroy.Greet();
}

void testCopyConstructor(Critter aCopy)
{
	aCopy.Greet();
}

void testAssignmentOp()
{
	Critter crit1("crit1", 7);
	Critter crit2("crit2", 9);
	crit1 = crit2;
	crit1.Greet();
	crit2.Greet();
	std::cout << std::endl;
	
	Critter crit3("crit3", 11);
	crit3 = crit3;
	crit3.Greet();
}
