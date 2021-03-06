#ifndef SNAKE_HPP
#define SNAKE_HPP


enum Direction {LEFT, RIGHT, UP, DOWN};
class Snake
{

private:

  int headX;
  int headY;
  int tailX[5];
  int tailY[5];
  int strength;
  int key;

public:

  Snake(int, int);
  ~Snake();
  void move(Direction);
  bool danceL(); 
  bool danceC(); 
  bool danceS(); 
  bool danceI(); 
  bool isDead();
  void updatePosition(int,int);
  friend class Space;
  int getStrength();
  int getHeadX();
  int getHeadY();
  void addAKey();
  int keyCollection();

};

#endif
