#include "ldungeon.hpp"
#include <cstdlib>
#include <iostream>

LDungeon::LDungeon(int gx,int gy, Snake* s, Space* l, Space* r, Space* u, Space* d,std::string n)
:Space(gx,gy,s,l,r,u,d,n)
{

}
LDungeon::~LDungeon()
{

}

bool LDungeon::makeItDance()
{
  return (s->danceL());
}

int LDungeon::makeOpeningX()
{
  return GridX; 
} 
int LDungeon::makeOpeningY()
{
  return rand()%GridY; 
} 

Space* LDungeon::nextSpace()
{
  return right;
}
void LDungeon::printInstruction()
{
  std::cout<<"To obtain the key for "<<getName()<<" .The snake needs to do a L dance"<<std::endl;
  std::cout<<"		o"<<std::endl;
  std::cout<<"		o"<<std::endl;
  std::cout<<"		o"<<std::endl;
  std::cout<<"		ooO"<<std::endl;
  
  Space::generalInstruction();
}
