#include "sdungeon.hpp"
#include <cstdlib>
#include <iostream>

SDungeon::SDungeon(int gx,int gy, Snake* s, Space* l, Space* r, Space* u, Space* d,std::string n)
:Space(gx,gy,s,l,r,u,d,n)
{

}
SDungeon::~SDungeon()
{

}

bool SDungeon::makeItDance()
{
  return (s->danceS());
}

int SDungeon::makeOpeningX()
{
  return -1; 
} 
int SDungeon::makeOpeningY()
{
  return rand()%GridY; 
} 

Space* SDungeon::nextSpace()
{
  return left;
}
void SDungeon::printInstruction()
{
  std::cout<<"To obtain the key for "<<getName()<<" .The snake needs to do a S dance"<<std::endl;
  std::cout<<"	       oo"<<std::endl;
  std::cout<<"		o"<<std::endl;
  std::cout<<"		o"<<std::endl;
  std::cout<<"		oO"<<std::endl;
  
  Space::generalInstruction();
}
