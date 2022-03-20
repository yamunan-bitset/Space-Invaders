#include <X11/Xlib.h>
#include "quickcg.h"
using namespace QuickCG;

struct SpaceShip
{
  SpaceShip(XWindowAttributes attr_) : attr(attr_) {}
  XWindowAttributes attr;
  double x = attr.height - 100;
  double dx;
  double y = 10;
  unsigned offset = 10;
};

inline unsigned randint()
{
  long holdrand;
  return (((holdrand = time(0) * 214013L + 2531011L) >> 16) & 0x7fff);
}

int main(int argc, char** argv)
{
  Display* display = XOpenDisplay(NULL);
  XWindowAttributes attr;
  XGetWindowAttributes(display, DefaultRootWindow(display), &attr);
  screen(attr.width, attr.height, 0, "Space Invaders");
  bool running = true;
  SpaceShip ship(attr);
  double incr = 1;
  bool send_bullet = false;
  unsigned posx = randint() % attr.height;
  while (running)
    {
      // ship.x += ship.dx; // FIXME: ship x axis not displacing
      cls(RGB_Black);
      readKeys();
      if (keyDown(SDLK_q))
	running = false;
      if (keyDown(SDLK_SPACE))
	send_bullet = true;
      if (keyDown(SDLK_LEFT))
        ship.x -= incr;
      if (keyDown(SDLK_RIGHT))
        ship.x += incr;
      // Draw Ship
      drawRect(ship.x + ship.dx, ship.y, ship.x + ship.dx + ship.offset, ship.y + ship.offset, RGB_Green);
      // Draw Target
      for (unsigned i = 0; i < attr.width; i += 50)
	drawRect(i, attr.height - 40, i + 10, attr.height - 30, RGB_White);
      // Draw Bullet
      if (send_bullet)
	{ // TODO
	}
      ship.dx = 0;
      redraw();
    }
  
  return 0;
}
