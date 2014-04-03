#include "Graphique.hpp"

#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <GL/freeglut_ext.h>

#include "EventHandling.hpp"

int		key = -1;

void		pressed_key(unsigned char k, int x, int y)
{
  (void)x;
  (void)y;

  key = k;
}

void		pressed_key_arrow(int k, int x, int y)
{
  (void)x;
  (void)y;

  key = k;
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
}

Graphique::~Graphique()
{
}

void Graphique::createWindows(const Point2d<int>& size)
{
  _win = size;
  glutInitWindowSize(size.x(), size.y());
  glutInitWindowPosition(50, 50);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("Snake_GL");
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
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
  (void)pos;
  (void)text;
}

void Graphique::updateEvent(EventHandler& eventHandler)
{
  EventType ev;

  glutMainLoopEvent();
  glutPostRedisplay();
  while (key != 0)
    {
      glutKeyboardUpFunc(pressed_key);
      if (key == 'o')
	{
	  ev = CHANGELIB;
	  eventHandler.addEvent(new Event(false, ev));
	}
      glutKeyboardFunc(pressed_key);
      glutSpecialFunc(pressed_key_arrow);
      if (key)
	{
	  if (key == 27)
	    ev = QUIT;
	  else if (key == 'z' || key == GLUT_KEY_UP)
	    ev = UP;
	  else if (key == 's' || key == GLUT_KEY_DOWN)
	    ev = DOWN;
	  else if (key == 'q' || key == GLUT_KEY_LEFT)
	    ev = LEFT;
	  else if (key == 'd' || key == GLUT_KEY_RIGHT)
	    ev = RIGHT;
	  else
	    ev = NONE;
	  eventHandler.addEvent(new Event(true, ev));
	  key = 0;
	}
      break;
    }
}
