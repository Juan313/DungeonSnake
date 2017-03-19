#include "snake.hpp"
#include "game.hpp"
#include "space.hpp"
#include "ldungeon.hpp"
#include "cdungeon.hpp"
#include "sdungeon.hpp"
#include "menu.hpp"
#include <iostream> 
#include <unistd.h> 

void displayInstruction();
void beginGame();
 
int main()
{
  char choice;
  while (choice!='0')
  {
    std::cout << "\033[2J\033[1;1H";
    Menu::displayMenu();
    choice = Menu::getChoice();
    switch(choice)
    {

      case '1': displayInstruction();
		break;
      case '2': beginGame();
		break;
      case '0': std::cout<<"Thanks for playing! Goodbye!"<<std::endl;
		break;
    }
  }
  return 0;
}

void displayInstruction()
{
  std::cout<<"You are a little snake trapped inside a six level dungeons."<<std::endl;
  std::cout<<"You must escape all six levels of dungeons to win the game."<<std::endl;
  std::cout<<"At each level, you must please the dungeon guard by doing a special dance. "<<std::endl;
  std::cout<<"If the dance meets the requirements of that level, a key will be"<<std::endl;
  std::cout<<"revealed to you. Be careful because different levels have different"<<std::endl;
  std::cout<<"requirements. At the top of each level, a demonstration of the dance "<<std::endl;
  std::cout<<"will be displayed. The dungeon cell also gets smaller and smaller as you approach"<<std::endl;
  std::cout<<"the final level. Once you obtain that key, a door will open up"<<std::endl;
  std::cout<<"that can take you to the next level. You can only exit through the door."<<std::endl;
  std::cout<<"If your head bang on the dungon wall that's not a door, you are instantly dead." <<std::endl;
  std::cout<<"You have certain strength at the beginning of the game. If your strength becomes 0, you are also dead."<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Press the following key to move the snake."<<std::endl;
  std::cout<<"               k"<<std::endl;
  std::cout<<"               ^"<<std::endl;
  std::cout<<"               |"<<std::endl;
  std::cout<<"           h<-- -->l"<<std::endl;
  std::cout<<"               |"<<std::endl;
  std::cout<<"               v"<<std::endl;
  std::cout<<"               j"<<std::endl;

  std::cout<<"Good luck! Hope you will help the little snake to escape!"<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Press any key to return to the main menu."<<std::endl;
  getchar();
}

void beginGame()
{

  Snake* s = new Snake(3,4);
  Space* dungeon1 = new SDungeon(14,14,s,nullptr,nullptr,nullptr,nullptr,"Final Dungeon");
  Space* dungeon2 = new SDungeon(16,14,s,dungeon1,nullptr,nullptr,nullptr,"Dungeon 2");
  Space* dungeon3 = new SDungeon(16,16,s,dungeon2,nullptr,nullptr,nullptr,"Dungeon 3");
  Space* dungeon4 = new CDungeon(16,16,s,nullptr,nullptr,dungeon3,nullptr,"Dungeon 4");
  Space* dungeon5 = new LDungeon(18,18,s,nullptr,dungeon4,nullptr,nullptr,"Dungeon 5");
  Space* dungeon6 = new LDungeon(18,18,s,nullptr,dungeon5,nullptr,nullptr,"Dungeon 6");
  Game* g = new Game(dungeon1,dungeon2,dungeon3,dungeon4,dungeon5,dungeon6,s);
  g->play();

  delete s;
  delete dungeon1;
  delete dungeon2;
  delete dungeon3;
  delete dungeon4;
  delete dungeon5;
  delete dungeon6;
  delete g;
  std::cout<<std::endl;
  std::cout<<"Press any key to return to the main menu."<<std::endl;
  getchar();
}
