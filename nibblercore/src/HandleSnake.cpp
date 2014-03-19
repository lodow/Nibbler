#include "HandleSnake.hpp"

HandleSnake::HandleSnake(const Point2d<int>& start, const Point2d<int>& win)
  : _win(win), _gamesize(10), _snake(Box<int>(start, Point2d<int>(_gamesize, _gamesize)))
{
}

HandleSnake::~HandleSnake()
{

}

void HandleSnake::changeDirection(Direction dir)
{
  _dir = dir;
}

int HandleSnake::getSize() const
{
// not implemented
  return (0);
}

void HandleSnake::update()
{
  Box<int> head = _snake.getBox();

  switch(_dir)
    {
    case UP:
      head.getmPos.mx() = (head.getmPos.my() - _gamesize);
      break;
    case DOWN:
      snake_pos.y = (snake_pos.y + m_size);
      break;
    case LEFT:
      snake_pos.x = (snake_pos.x - m_size) % ((m_screen.x) - 1);
      break;
    case RIGHT:
      snake_pos.x = (snake_pos.x + m_size) % ((m_screen.x) - 1);
      break;
    default :
      break;
    }
  //if we are out of screen
  if(snake_pos.x <= 1)
    {
      snake_pos.x = m_screen.x;
    }

  if(snake_pos.y <= 1)
    {
      snake_pos.y = m_screen.y;
    }


  //we return the new position of the head
  m_head->set_pos(snake_pos);

//we verifie collisoon:
  if(m_head->collisions_itself(m_size)) //itself colision
    {
      m_lost = true;  //Lost game
    }

  //obstacle collison
//we verifie that we are not on the apple:


  if(CollisionAABB(convert_to_AABB(m_pos_apple.x, m_pos_apple.y, m_size, m_size),
                   convert_to_AABB(snake_pos.x, snake_pos.y, m_size, m_size)))
    {
      m_score++;
      //we add a part
      m_head->add_part();
      //we add a new apple :
      m_pos_apple.x = rand() % ((m_screen.x) - 1);
      m_pos_apple.y = rand() % ((m_screen.y) - 1);

      //verifie that the apple is not in a wall :
    }

  //do moving stuff
  //first we update the snake position
  //check out of screen
  //we verifie collisoon:
  //we verifie that we are not on the apple:
}

void HandleSnake::drawn(IGui* lib) const
{
  //draw stuff
}
