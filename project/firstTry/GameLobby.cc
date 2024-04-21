#include <iostream>
#include <string>
/*Botwa sript*/
class Player {
   public:
      Player(const std::string &name = "");
      std::string GetName() const;
      Player *GetNext() const;
      void SetNext(Player *next);
   private:
      std::string m_Name;
      Player *m_pNext;
};

Player::Player(const std::string &name) : m_Name(name), m_pNext(0) {}

std::string Player::GetName() const {
   return m_Name;
}
Player *Player::GetNext() const {
   return m_pNext;
}
void Player::SetNext(Player *next) {
   m_pNext = next;
}

class Lobby {
   friend std::ostream &operator << (std::ostream &os, const Lobby &aLobby);
   public:
      Lobby();
      ~Lobby();
      void AddPlayer();
      void RemovePlayer();
      void Clear();
   private:
      Player *m_pHead;
};

Lobby::Lobby() : m_pHead(0) {}
Lobby::~Lobby() { Clear(); }

void Lobby::AddPlayer() {
   std::cout << "Please enter the name of the new player";
   std::string name;
   std::cin >> name;
   Player *pNewPlayer = new Player(name);
   if(m_pHead == 0) {
      m_pHead = pNewPlayer;
   } else {
      Player *pIter = m_pHead;
      while(pIter->GetNext() != 0) pIter = pIter->GetNext();
      pIter->SetNext(pNewPlayer);
   }
}

void Lobby::RemovePlayer() {
   if (m_pHead == 0) std::cout<<"The game lobby is empty already\n";
   else {
      Player *pTemp = m_pHead;
      m_pHead = m_pHead->GetNext();
      delete pTemp;
   }
}
void Lobby::Clear() {
   while(m_pHead != NULL) RemovePlayer();
}

std::ostream &operator << (std::ostream &os, const Lobby &aLobby) {
   Player *pIter = aLobby.m_pHead;
   os<<"\nHeres whos in the game lobby: \n";

   if(pIter == NULL) os << "The lobby is empty\n";
   else {
      while (pIter != NULL) {
         os << pIter->GetName() << std::endl;
         pIter = pIter->GetNext();
      }
   }
   return os;
   
}
auto main(int argc, char *argv[]) -> decltype(0) {
   Lobby myLobby;
   int choice;

   do
	{
		std::cout << myLobby;
		std::cout << "\nGAME LOBBY\n";
		std::cout << "0 - Exit the program\n";
		std::cout << "1 - Add a player to the lobby\n";
		std::cout << "2 - Remove a player from the lobby\n";
		std::cout << "3 - Clear the lobby\n";
		std::cout << std::endl << "Enter a choice: ";
		std::cin >> choice;
		
		switch (choice)
		{
			case 0: std::cout << "Good-bye\n"; break;
			case 1: myLobby.AddPlayer(); break;
			case 2: myLobby.RemovePlayer(); break;
			case 3: myLobby.Clear(); break;
			default: std::cout << "That was not a valid choice\n";
		}
	} while (choice != 0);
   return 0;
}