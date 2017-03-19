#include "cdungeon.hpp"
#include <cstdlib>
#include <iostream>

CDungeon::CDungeon(int gx,int gy, Snake* s, Space* l, Space* r, Space* u, Space* d,std::string n)
:Space(gx,gy,s,l,r,u,d,n)
{

}
CDungeon::~CDungeon()
{

}

bool CDungeon::makeItDance()
{
  return (s->danceC());
}

int CDungeon::makeOpeningX()
{
  return rand()%GridX; 
} 
int CDungeon::makeOpeningY()
{
  return -1; 
} 

Space* CDungeon::nextSpace()
{
  return up;
}
void CDungeon::printInstruction()
{
  std::cout<<"To obtain the key for "<<getName()<<" .The snake needs to do a C dance"<<std::endl;
  std::cout<<"		oo"<<std::endl;
  std::cout<<"		o"<<std::endl;
  std::cout<<"		o"<<std::endl;
  std::cout<<"		oO"<<std::endl;
  
  Space::generalInstruction();
}
