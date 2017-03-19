#ifndef SPACE_HPP

#define SPACE_HPP
#include "snake.hpp"
#include <string> 

class Space
{
protected:
  int GridX;
  int GridY;
  int keyX;
  int keyY;
  int openingX;
  int openingY;
  Snake* s; 
  Space* left;
  Space* right;
  Space* up;
  Space* down;
  std::string name;
  
public:
  Space(int gx,int gy, Snake* s, Space* l, Space* r, Space* u, Space* d,std::string n);
  virtual ~Space();
  void printSpace();
  virtual bool makeItDance() = 0;
  virtual int makeOpeningX() = 0;
  virtual int makeOpeningY() = 0;
  virtual Space* nextSpace() = 0;
  int getGridX();
  int getGridY();
  int getOpeningX();
  int getOpeningY();
  void setKeyX();
  void setKeyY();
  std::string getName();
  virtual void printInstruction() = 0;
  void generalInstruction();
};

#endif
