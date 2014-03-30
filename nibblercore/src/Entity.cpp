#include "Entity.hpp"

Entity::Entity(const Box<int>& b, blockType type)
  : _box(b), _type(type)
{

}

Entity::~Entity()
{
}
