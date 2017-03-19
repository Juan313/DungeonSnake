#include "space.hpp"
#include <iostream>

Space::Space(int gx,int gy, Snake* s, Space* l, Space* r, Space* u, Space* d, std::string n)
{
  GridX = gx;
  GridY = gy;
  keyX = -1;
  keyY = -1;
  openingX = -2;
  openingY = -2;
  this->s = s;
  left = l; 
  right = r;
  up = u;
  down = d;
  name = n;
  
  // update boarder
  // update snake initial location on the space is the center of the space
}

Space::~Space()
{
}

void Space::printSpace()
{
  
  for (int j = -1 ; j<GridX+1; ++j)
  {
    if (j == openingX  && openingY == -1)
    {
      std::cout<<"D";
    }
    else 
    {
      std::cout<<"#";
    }
  }
  std::cout<<std::endl;
  
  for (int i = 0 ; i< GridY; ++i)
  {
    for (int j = 0 ; j< GridX; ++j)
    {
      if (j ==0)
      {
        if (i == openingY && j == openingX+1) 
        {
	  std::cout<<"D";
        }
        else 
        {
	  std::cout<<"#";
        }
      }

      bool printStuff = false;

      if ((j == s->headX) && (i == s->headY)) 
      {
        if ((j == keyX) && (i == keyY))
        {
          keyX = -1;
          keyY = -1;
          // generate an opening in the wall
          openingX = makeOpeningX();
          openingY = makeOpeningY();   
	  std::cout<<'O';
	  printStuff = true;
        }
	else 
        {
          std::cout<<'O';
	  printStuff = true;
        }
      }

      else 
      { 
	for (int k = 0;k<5;++k)
	{
	  if ((s->tailX[k] == j) && (s->tailY[k] == i) && printStuff == false)
	  {
	    std::cout<<'o';
	    printStuff = true;
	  }
	}
      }

      if ((j == keyX) && (i == keyY))
      {
	std::cout<<'K';
	printStuff = true;
      }
 
      if (printStuff == false) 
      {
	std::cout<<' ';
      }
    }  
    if (i == openingY && openingX == GridX) 
    {
      std::cout<<"D"<<std::endl;
    }
    else 
    {
      std::cout<<"#"<<std::endl;
    }
  }
  for (int i = -1 ; i<GridX+1; ++i)
  {
    if (i == openingX  && openingY == GridY)
    {
      std::cout<<"D";
    }
    else 
    {
      std::cout<<"#";
    }
  }
  std::cout<<std::endl;
}

int Space::getGridX()
{
  return GridX;
}

int Space::getGridY()
{
  return GridY;
}

int Space::getOpeningX()
{
  return openingX;
}

int Space::getOpeningY()
{
  return openingY;
}
void Space::setKeyX()
{
  keyX = rand()%GridX;  
}
void Space::setKeyY()
{
  keyY = rand()%GridY;  
}

std::string Space::getName()
{
  return name;
}
void Space::generalInstruction()
{
  std::cout<<"Press the following key to move the snake."<<std::endl;
  std::cout<<"               k"<<std::endl;
  std::cout<<"               ^"<<std::endl;
  std::cout<<"               |"<<std::endl;
  std::cout<<"           h<-- -->l"<<std::endl;
  std::cout<<"               |"<<std::endl;
  std::cout<<"               v"<<std::endl;
  std::cout<<"               j"<<std::endl;
}
