#include "snake.hpp"
#include "game.hpp"
#include "space.hpp"
#include <iostream> 
#include <unistd.h> 

int main()
{
  Snake* s = new Snake(3,4);
  Space* dungeon1 = new Space(40,40,s,nullptr,nullptr,nullptr,nullptr);
  Space* dungeon2 = new Space(40,40,s,nullptr,nullptr,nullptr,nullptr);
  Space* dungeon3 = new Space(40,40,s,nullptr,nullptr,nullptr,nullptr);
  Space* dungeon4 = new Space(40,40,s,nullptr,nullptr,nullptr,nullptr);
  Space* dungeon5 = new Space(40,40,s,nullptr,nullptr,nullptr,nullptr);
  Space* dungeon6 = new Space(40,40,s,nullptr,nullptr,nullptr,nullptr);

  Game* g = new Game(dungeon1,dungeon2,dungeon3,dungeon4,dungeon5,dungeon6,s);
  g->play();

  if (s->isDead())
  {
    std::cout<<"Game over! The snake has run out of breath. You lose!"<<std::endl;
  }
  else if (g->getHitWall()) 
  {
    std::cout<<"You lose!!"<<std::endl;
  }
  return 0;
}
