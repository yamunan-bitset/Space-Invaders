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

int main(int argc, char** argv)
{
  Display* display = XOpenDisplay(NULL);
  XWindowAttributes attr;
  XGetWindowAttributes(display, DefaultRootWindow(display), &attr);
  screen(attr.width, attr.height, 0, "Space Invaders");
  bool running = true;
  SpaceShip ship(attr);
  double incr = attr.width / 1000;
  bool send_bullet = false;
  double target_move = 1;
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
      for (unsigned i = target_move; i < target_move + 200; i += 50)
	drawRect(i, attr.height - 40, i + 10, attr.height - 30, RGB_White);
      // Draw Bullet
      if (send_bullet)
	{ // TODO
	}
      ship.dx = 0;
      target_move += 0.1;
      redraw();
    }
  
  return 0;
}
