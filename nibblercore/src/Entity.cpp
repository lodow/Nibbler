#include "Entity.hpp"

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
