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

#define POSX rand() % 250

int main(int argc, char** argv)
{
  Display* display = XOpenDisplay(NULL);
  XWindowAttributes attr;
  XGetWindowAttributes(display, DefaultRootWindow(display), &attr);
  screen(attr.width, attr.height, 0, "Space Invaders");
  bool running = true;
  SpaceShip ship(attr);
  double incr = 0.1;
  bool send_bullet = false;
  while (running)
    {
      ship.x += ship.dx; // FIXME: ship x axis not displacing
      cls(RGB_Black);
      readKeys();
      if (keyDown(SDLK_q))
	running = false;
      if (keyDown(SDLK_SPACE))
	send_bullet = true;
      if (keyDown(SDLK_LEFT))
        ship.dx -= incr;
      if (keyDown(SDLK_RIGHT))
        ship.dx += incr;
      // Draw Ship
      drawRect(ship.x, ship.y, ship.x+ship.offset, ship.y+ship.offset, RGB_Green);
      // Draw Target
      drawRect(POSX, attr.height - 20, POSX + 10, attr.height - 10, RGB_White);
      // Draw Bullet
      if (send_bullet)
	{ // TODO
	}
      ship.dx = 0;
      redraw();
    }
  
  return 0;
}
