#include "Map.hpp"

#include "Teleporter.hpp"
#include "Wall.hpp"
#include "Apple.hpp"
#include "EventHandling.hpp"

Map::Map(const std::string& filename)
{
  std::fstream file;
  std::string tmp;
  std::stringstream ss;
  int tmpval;
  int tmpval2;

  file.open(filename.c_str(), std::ios::in);
  if (!file.is_open())
    throw nFault(std::string("Can't open ") + filename, true);

  while(std::getline(file, tmp))
    _filedata.push_back(tmp);
  file.close();

  for (std::vector<std::string>::const_iterator it = _filedata.begin(), end =  _filedata.end(); it != end; ++it)
    {
      std::string keyname;
      std::string value;
      size_t postmp;

      ss.clear();
      postmp = it->find(":");
      if (postmp != std::string::npos)
        {
          keyname = it->substr(0, postmp);
          value = it->substr(postmp + 2);
          ss.str(value);
          if (!keyname.compare("size"))
            {
              ss >> tmpval >> tmpval2;
              _gamesize.x() = tmpval;
              _gamesize.y() = tmpval2;
              if (tmpval < 5 || tmpval > 100 || tmpval2 < 5 || tmpval2 > 100)
                throw nFault(value + ": incorrect value", false);
            }
          else if (!keyname.compare("start"))
            {
              ss >> tmpval >> tmpval2;
              _start.x() = tmpval;
              _start.y() = tmpval2;
            }
          else if (!keyname.compare("fps"))
            {
              ss >> _fps;
              if (_fps < 2)
                throw nFault(value + ": incorrect value", false);
            }
          else if (!keyname.compare("accel"))
            {
              ss >> _accel;
            }
        }
    }
}

Map::~Map()
{
}

void Map::getEntities(std::deque<Entity*>& ents, const Point2d<int>& gamesize, const Point2d<int>& win) const
{
  std::stringstream ss;
  int x;
  int y;
  int w;
  int h;
  int d1;
  int d2;
  int dir;

  for (std::vector<std::string>::const_iterator it = _filedata.begin(), end =  _filedata.end(); it != end; ++it)
    {
      std::string keyname;
      std::string value;
      size_t postmp;

      ss.clear();
      postmp = it->find(":");
      if (postmp != std::string::npos)
        {
          keyname = it->substr(0, postmp);
          value = it->substr(postmp + 2);
          if (!keyname.compare("entity"))
            {
              std::string EntityName;
              postmp = value.find(":");
              if (postmp != std::string::npos)
                {
                  EntityName = value.substr(0, postmp);
                  value = value.substr(postmp + 2);
                  ss.str(value);
                  if (!EntityName.compare("Apple"))
                    {
                      ss >> x >> y >> w >> h;
                      ents.push_back(new Apple(gameToWinSize(Box<int>(Point2d<int>(x, y), Point2d<int>(w, h)), gamesize, win)));
                    }
                  else if (!EntityName.compare("Wall"))
                    {
                      ss >> x >> y >> w >> h;
                      ents.push_back(new Wall(gameToWinSize(Box<int>(Point2d<int>(x, y), Point2d<int>(w, h)), gamesize, win)));
                    }
                  else if (!EntityName.compare("Teleporter"))
                    {
                      ss >> x >> y >> w >> h >> d1 >> d2 >> dir;
                      ents.push_back(new Teleporter(gameToWinSize(Box<int>(Point2d<int>(x, y), Point2d<int>(w, h)), gamesize, win), gameToWinSize(Point2d<int>(d1, d2), gamesize, win), static_cast<EventType>(dir)));
                    }
                }
            }
        }
    }
}
