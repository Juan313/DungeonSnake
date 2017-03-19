#ifndef CDUNGEON_HPP
#define CDUNGEON_HPP
#include "space.hpp"
#include <string> 

class CDungeon : public Space
{
public:
CDungeon(int,int,Snake*, Space*, Space*,Space*,Space*,std::string);
~CDungeon();
bool makeItDance(); 
int makeOpeningX();
int makeOpeningY();
Space* nextSpace();
void printInstruction();


};

#endif
