#include "game.hpp"
#include "kbhit.hpp"
#include <ctime> 
#include <iostream> 
#include <unistd.h> 

Game::Game(Space* s1, Space* s2, Space* s3, Space* s4, Space* s5, Space* s6, Snake* s)
{
  this->s1=s1;
  this->s2=s2;
  this->s3=s3;
  this->s4=s4;
  this->s5=s5;
  this->s6=s6;
  this->s=s;
  hitWall = false;
}

Game::~Game()
{

}

void Game::play()
{
  unsigned int seed = time(0);
  srand(seed);
  bool escape = false;
  Space* space = s6;
  while (!escape && space!=nullptr && s->keyCollection() < 6)
  {
    space = playInEachSpace(space,s);
  }
  
  if (s->keyCollection()==6)
  {
    std::cout<<"Congratulations! The snake has escaped the dungeon!"
             <<" You win!!!!!"<<std::endl;
  } 
  
}
 

Space* Game::playInEachSpace(Space* sp, Snake* s)
{
  s->updatePosition(sp->getGridX()/2,sp->getGridY()/2);  
  bool escape = false; 
  Direction dir = LEFT;
  unsigned int microseconds1 = 350000;
  unsigned int microseconds2 = 400000;
  bool obtainKey = false;
  while (!s->isDead() && !hitWall && !escape) 
	 
  {
    std::cout << "\033[2J\033[1;1H";
    std::cout<<"You are located at "<< sp->getName()<<". You have collected "<<s->keyCollection()<<" keys so far."<<std::endl;
    std::cout<<"Strength of snake left is: "<<s->getStrength()<<std::endl;
    sp->printInstruction();
    sp->printSpace();
    usleep(microseconds1);
    if(kbhit())
    {
      char key = getchar();
      Direction prev = dir;
      switch (key)
      {
	case 'h': if (prev != RIGHT) 
		  { 
		    dir = LEFT;
		  }
		  break;
	case 'l': if(prev != LEFT) 
		  { 
		    dir = RIGHT;
		  }
		  break;
	case 'k': if (prev != DOWN) 
		  {
		    dir = UP;
		  }
		  break;
	case 'j': if(prev != UP)
		  { 
		    dir = DOWN;
		  }
		  break;
      }
    }
    usleep(microseconds2);
    s->move(dir);
    if(!obtainKey && sp->makeItDance())
    {
      sp->setKeyX();
      sp->setKeyY();
      obtainKey = true;
    }
    if (s->getHeadX()==sp->getOpeningX() && s->getHeadY() == sp->getOpeningY())
    {
      hitWall = false;
      escape = true;
    }
    else 
    {
      hitWall = s->getHeadX()<0 || s->getHeadY()<0 || 
          s->getHeadX() == sp->getGridX()|| s->getHeadY()== sp->getGridY();
    } 
  }  
  if (s->isDead())
  {
    std::cout<<"Game over! The snake has run out of breath. You lose!"<<std::endl;
    return nullptr;
  }
  else if (getHitWall()) 
  {
    std::cout<<"Game over! The snake's head has banged on the dungeon wall and dead!!"<<std::endl;
    return nullptr;
  }
  else if (s->keyCollection()<=4) 
  {
    s->addAKey();
    std::cout << "\033[2J\033[1;1H";
    std::cout<<"Congratulations! You've escaped "<<sp->getName()<<"!"<<std::endl;
    std::cout<<"Press any key to continue to the next level."<<std::endl;
    getchar();
    return sp->nextSpace();
  }
  else 
  {
    s->addAKey();
    std::cout << "\033[2J\033[1;1H";
    return sp->nextSpace();
  }
   
}
bool Game::getHitWall()
{
  return hitWall;
}
