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
  playInEachSpace(s1,s);
 
  
}
 

void Game::playInEachSpace(Space* sp, Snake* s)
{
  bool escape = false; 
  Direction dir = LEFT;
  unsigned int microseconds1 = 350000;
  unsigned int microseconds2 = 400000;
  while (!s->isDead() && !hitWall && !escape) 
	 
  {
    std::cout << "\033[2J\033[1;1H";
    std::cout<<"Strength of snake left is: "<<s->getStrength();
    std::cout<<std::endl;
    s1->printSpace();
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
	case 'i': if (prev != DOWN) 
		  {
		    dir = UP;
		  }
		  break;
	case 'k': if(prev != UP)
		  { 
		    dir = DOWN;
		  }
		  break;
      }
    }
    usleep(microseconds2);
    s->move(dir);
    if (s->getHeadX()==sp->getOpeningX() && s->getHeadY() == sp->getOpeningY())
    {
      hitWall = false;
      escape = true;
    }
    else 
    {
      hitWall = s->getHeadX()<0 || s->getHeadY()<0 || 
          s->getHeadX() == s1->getGridX()|| s->getHeadY()== s1->getGridY();
    } 
  }

}
bool Game::getHitWall()
{
  return hitWall;
}
