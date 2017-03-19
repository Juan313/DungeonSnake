#ifndef SDUNGEON_HPP
#define SDUNGEON_HPP
#include "space.hpp"
#include <string> 

class SDungeon : public Space
{
public:
SDungeon(int,int,Snake*, Space*, Space*,Space*,Space*,std::string);
~SDungeon();
bool makeItDance(); 
int makeOpeningX();
int makeOpeningY();
Space* nextSpace();
void printInstruction();


};

#endif
