#include "Graphique.hpp"

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <GL/freeglut_ext.h>
#include <cmath>

#include <ft2build.h>
#include <freetype2/freetype/freetype.h>
#include <freetype2/freetype/ftglyph.h>
#include <freetype2/freetype/ftoutln.h>
#include <freetype2/freetype/fttrigon.h>

int		key = -1;
int		pressedkey = -1;

void		pressed_key(unsigned char k, int x, int y)
{
  (void)x;
  (void)y;

  if (key == -1 || key == 0)
    key = k;
  if (key != 27 && key != 13)
    key -= 32;
}

void		arrow_key(int k, int x, int y)
{
  (void)x;
  (void)y;

  if (key == -1 || key == 0)
    key = k;
}

void		up_pressed_key(unsigned char k, int x, int y)
{
  (void)x;
  (void)y;

  if (k != 13)
    pressedkey = k;
}

double aspect_ratio = 0;
void reshape(int w, int h)
{
  aspect_ratio = (double)w / (double)h;
  glViewport(0, 0, w, h);
}

Graphique::Graphique()
{
  int		i = 1;

  glutInit(&i, NULL);
  _colors[APPLE].push_back(0);
  _colors[APPLE].push_back(181);
  _colors[APPLE].push_back(96);

  _colors[HEAD].push_back(181);
  _colors[HEAD].push_back(96);
  _colors[HEAD].push_back(0);

  _colors[SNAKE].push_back(96);
  _colors[SNAKE].push_back(0);
  _colors[SNAKE].push_back(181);

  _colors[WALL].push_back(255);
  _colors[WALL].push_back(0);
  _colors[WALL].push_back(0);

  _colors[TELEP].push_back(0);
  _colors[TELEP].push_back(0);
  _colors[TELEP].push_back(204);

  _colors[EMPTY].push_back(0);
  _colors[EMPTY].push_back(0);
  _colors[EMPTY].push_back(0);

  _keys['Q'] = LEFT;
  _keys['D'] = RIGHT;
  _keys['Z'] = UP;
  _keys['S'] = DOWN;
  _keys['P'] = PAUSE;
  _keys[GLUT_KEY_LEFT] = LEFT;
  _keys[GLUT_KEY_RIGHT] = RIGHT;
  _keys[GLUT_KEY_DOWN] = DOWN;
  _keys[GLUT_KEY_UP] = UP;
  _keys[13] = ENTER;
  _keys[27] = QUIT;
}

Graphique::~Graphique()
{
}

void Graphique::createWindows(const Point2d<int>& size)
{
  _win = size;
  glutInitWindowSize(size.x(), size.y());
  glutInitWindowPosition(0, 0);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("Snake_GL");

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glutKeyboardUpFunc(up_pressed_key);
  glutKeyboardFunc(pressed_key);
  glutSpecialFunc(arrow_key);
  // glutReshapeFunc(reshape);
}

void Graphique::drawSquare(const Box<int>& square, blockType type)
{
  Point2d<double>		tmp = square.getSize();
  const std::vector<int>&	col = _colors.at(type);

  tmp /= (_win / 2.0);
  glPushMatrix();
  glColor3d(col[0], col[1], col[2]);
  glTranslatef(((static_cast<double>(square.getPos().x())) / _win.x() - 0.5) * 2.0,
	       (((static_cast<double>(_win.y() - square.getPos().y()))) / _win.y() - 0.5) * 2.0, 0.0);
  glRectf(0, 0, tmp.w(), -tmp.h());
  glPopMatrix();
}

void Graphique::clearScreen()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphique::drawScreen()
{
  glutSwapBuffers();
}

void Graphique::affText(const Point2d<int>& pos, const std::stringstream& text)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10*aspect_ratio, 10*aspect_ratio, -10, 10, -1, 1);

  glColor3ub(255,0,0);
  glPushMatrix();
  glTranslatef(((static_cast<double>(pos.x())) / _win.x() - 0.5) * 2.0,
	       (((static_cast<double>(_win.y() - pos.y()))) / _win.y() - 0.5) * 1.9, 0);
  glScalef(1/3552.38, 1/2552.38, 0);
  for( const char* p = text.str().c_str(); *p; p++)
    {
      glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *p);
    }
  glPopMatrix();
  // glutSwapBuffers();
}

void Graphique::updateEvent(EventHandler& eventHandler)
{
  EventType ev;

  glutMainLoopEvent();
  glutPostRedisplay();
  while (1)
    {
      if (pressedkey == 111)
	{
	  ev = CHANGELIB;
	  eventHandler.addEvent(new Event(false, ev));
	  pressedkey = 0;
	  return ;
	}
      else if (key)
	{
	  ev = _keys[key];
	  eventHandler.addEvent(new Event(true, ev));
	  key = 0;
	  return ;
	}
      break;
    }
}
