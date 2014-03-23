#ifndef TIMEHANDLING_HPP_INCLUDED
#define TIMEHANDLING_HPP_INCLUDED

#include <ctime>

class TimeHandler
{
public:
  TimeHandler(float fps);
  ~TimeHandler();

  void setFps(float fps);
  float getFps() const {return _targetFps;};
  float getActualFps() const {return _fps;};
  unsigned int getFramesCount() const {return _frames;};

  void startFrame();
  void endFrame();
  float getElapsedTime() const;
  void alignOnFps();

private:
  float _targetFps;
  float _fps;
  unsigned int _frames;
  clock_t _start;
  clock_t _end;
};

#endif // TIMEHANDLING_HPP_INCLUDED
