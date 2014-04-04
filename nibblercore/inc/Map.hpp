#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

#include "Fault.hpp"
#include "Point2d.hpp"
#include "Box.hpp"
#include "Entity.hpp"

class Map
{
public:
  Map(const std::string& filename);
  ~Map();

  const Point2d<int>& getGamesize() const {return _gamesize;};
  double getFps() const {return _fps;};
  double getAccel() const {return _accel;};
  const Point2d<int>& getStart() const {return _start;};
  void getEntities(std::deque<Entity*>& ents, const Point2d<int>& gamesize, const Point2d<int>& win) const;
private:
  std::vector<std::string> _filedata;
  Point2d<int> _gamesize;
  Point2d<int> _start;
  double _fps;
  double _accel;
};

#endif // MAP_HPP_INCLUDED
