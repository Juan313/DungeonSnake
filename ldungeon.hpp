#ifndef LDUNGEON_HPP
#define LDUNGEON_HPP
#include "space.hpp"
#include <string> 

class LDungeon : public Space
{
public:
LDungeon(int,int,Snake*, Space*, Space*,Space*,Space*,std::string);
~LDungeon();
bool makeItDance(); 
int makeOpeningX();
int makeOpeningY();
Space* nextSpace();
void printInstruction();


};

#endif
