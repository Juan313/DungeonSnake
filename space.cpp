#include "space.hpp"
#include <iostream>

Space::Space(int gx,int gy, Snake* s, Space* l, Space* r, Space* u, Space* d)
{
  GridX = gx;
  GridY = gy;
  keyX = 0;
  keyY = 10;
  openingX = 10;
  openingY = 40;
  this->s = s;
  left = l; 
  right = r;
  up = u;
  down = d;
  grid = new char*[GridY];
  for (int i = 0 ; i< GridY; ++i)
  {
    grid[i] = new char[GridX];
  }
  
  // update boarder
  // update snake initial location on the space is the center of the space
  s->updatePosition(GridX/2,GridY/2);  
}

Space::~Space()
{
  for (int i = 0 ; i< GridY; ++i)
  {
    delete [] grid[i];
  }
  delete grid;
  grid = nullptr;
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
	  if ((s->tailX[k] == j) && (s->tailY[k] == i))
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
    std::cout<<"#"<<std::endl;
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
