#ifndef SPACE_HPP

#define SPACE_HPP
#include "snake.hpp"

class Space
{
private:
  int GridX;
  int GridY;
  int keyX;
  int keyY;
  int openingX;
  int openingY;
  Snake* s; 
  char** grid;
  Space* left;
  Space* right;
  Space* up;
  Space* down;
  
public:
  Space(int gx,int gy, Snake* s, Space* l, Space* r, Space* u, Space* d);
  ~Space();
  void printSpace();
//  bool virtual makeItDance() = 0;
  int getGridX();
  int getGridY();
  int getOpeningX();
  int getOpeningY();

};

#endif
