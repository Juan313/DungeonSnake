#ifndef GAME_HPP
#define GAME_HPP
#include "snake.hpp"
#include "space.hpp"

class Game
{
private:
  Space* s1;
  Space* s2;
  Space* s3;
  Space* s4;
  Space* s5;
  Space* s6;
  Snake* s;
  bool hitWall;
public:
  Game(Space*, Space*, Space*, Space*, Space*, Space*, Snake*);
  ~Game();
  void play();
  void playInEachSpace(Space*, Snake*);
  bool getHitWall();
};
#endif
