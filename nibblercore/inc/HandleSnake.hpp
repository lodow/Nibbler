#ifndef HANDLESNAKE_HPP_INCLUDED
#define HANDLESNAKE_HPP_INCLUDED

#include "Point2d.hpp"

class HandleSnake
{
public:
  HandleSnake();
  ~HandleSnake();

  void change_dir(int dir); //to change the direction of the snake
  void update();
  void drawn();

  int sget_size(int game_size);

private:
  pos m_screen; //the screen widht and height
  snake* m_head; //a pointer on the head of the snake
  int m_dir; //the direction of the snake
  pos m_pos_apple; //the pos of the apple
  int m_score;
  bool m_lost; //if we ha ve lost
  int m_size; //the size of the snake
};


#endif // HANDLESNAKE_HPP_INCLUDED
