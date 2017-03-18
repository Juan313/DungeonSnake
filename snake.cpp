#include "snake.hpp"

Snake::Snake(int x, int y)
{
  headX = x;
  headY = y;
  tailX[0] = x+1; 
  tailY[0] = y;
  tailX[1] = x+2;
  tailY[1] = y;
  tailX[2] = x+3;
  tailY[2] = y;
  tailX[3] = x+4;
  tailY[3] = y;
  tailX[4] = x+5;
  tailY[4] = y;
  strength = 200;
}
Snake::~Snake()
{

}

void Snake::move(Direction d)
{
  int tempX = headX;
  int tempY = headY;
  switch (d)
  {
    case LEFT: headX--; 
         break;
    case RIGHT: headX++; 
         break;
    case UP: headY--; 
         break;
    case DOWN: headY++; 
         break;
  } 
  int temp2X, temp2Y;
  temp2X = tailX[0];
  temp2Y = tailY[0];
  tailX[0] = tempX;
  tailY[0] = tempY;
  for (int i = 1; i<5; ++i)
  {
    tempX = tailX[i];
    tempY = tailY[i];
    tailX[i] = temp2X;
    tailY[i] = temp2Y;
    temp2X = tempX;
    temp2Y = tempY;
  }
  strength--;
}

bool Snake::danceL()
{
  if ((headX-tailX[0] == 1) && (tailX[0] - tailX[1] == 1)
     && (tailY[1]-tailY[2]==1) && (tailY[2]-tailY[3]==1) 
     &&(tailY[3]-tailY[4]==1))
    return true;
  else  
    return false;
}
bool Snake::danceC()
{
  if ((headX-tailX[0] == 1) && (tailY[0] - tailY[1] == 1)
     && (tailY[1]-tailY[2]==1) && (tailY[2]-tailY[3]==1) 
     &&(tailX[4]-tailX[3]==1))
    return true;
  else  
    return false;
}
bool Snake::danceS()
{
  if ((tailX[0]-headX == 1) && (tailY[0] - tailY[1] == 1)
     && (tailY[1]-tailY[2]==1) && (tailY[2]-tailY[3]==1) 
     &&(tailX[4]-tailX[3]==1))
    return true;
  else  
    return false;
}
bool Snake::danceI()
{
  if ((headY-tailY[0] == 1) && (tailY[0] - tailY[1] == 1)
     && (tailY[1]-tailY[2]==1) && (tailY[2]-tailY[3]==1) 
     &&(tailY[3]-tailY[4]==1))
    return true;
  else  
    return false;
}
bool Snake::isDead()
{
  return (strength<=0);
}
void Snake::updatePosition(int x, int y)
{
  headX = x;
  headY = y;
  tailX[0] = x+1; 
  tailY[0] = y;
  tailX[1] = x+2;
  tailY[1] = y;
  tailX[2] = x+3;
  tailY[2] = y;
  tailX[3] = x+4;
  tailY[3] = y;
  tailX[4] = x+5;
  tailY[4] = y;
}
int Snake::getStrength()
{
  return strength;
}
int Snake::getHeadX()
{
  return headX;
}
int Snake::getHeadY()
{
  return headY;
}
