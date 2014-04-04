#include "Entity.hpp"

Box<int> gameToWinSize(const Box<int>& b, const Point2d<int>& gamesize,
                       const Point2d<int>& win)
{
  return (Box<int>(b.getPos() * (win.x() / gamesize.x()),
                   b.getSize() * (win / gamesize)));
}

Point2d<int> gameToWinSize(const Point2d<int>& b, const Point2d<int>& gamesize,
                       const Point2d<int>& win)
{
  return (Point2d<int>(b * (win.x() / gamesize.x())));
}

Entity::Entity(const Box<int>& b, blockType type)
  : _box(b), _type(type)
{

}

Entity::~Entity()
{
}

bool Entity::action(HandleSnake& game, Entity* collider)
{
  (void)game;
  (void)collider;
  return (false);
}
