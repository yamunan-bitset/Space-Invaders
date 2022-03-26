#include <X11/Xlib.h>
#include "quickcg.h"
using namespace QuickCG;

struct SpaceShip
{
  SpaceShip(XWindowAttributes attr_) : attr(attr_) {}
  XWindowAttributes attr;
  double x = attr.width - 100;
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
  double incr = attr.width / 100;
  short target_move = 2;
  bool negate = false;
  bool moving_bullet = false;
  unsigned bullet_x = ship.x, bullet_y = ship.y;
  while (running)
    {
      cls(RGB_Black);
      readKeys();
      if (keyDown(SDLK_q))
	running = false;
      if (keyDown(SDLK_SPACE))
	moving_bullet = true;
      if (keyDown(SDLK_LEFT))
        ship.x -= incr;
      if (keyDown(SDLK_RIGHT))
        ship.x += incr;
      if (ship.x < 0) ship.x = 1;
      if (ship.x > attr.width) ship.x = attr.width - 50;
      // Draw Ship
      drawRect(ship.x, ship.y, ship.x + ship.offset, ship.y + ship.offset, RGB_Green);
      // Draw Target
      for (unsigned i = target_move; i < target_move + 200; i += incr)
	drawRect(i, attr.height - 40, i + 10, attr.height - 30, RGB_White);
      if (getTicks() % 5 == 0) target_move += 1;
      if (target_move == attr.width) negate = true;
      if (target_move == 1) target_move = -target_move;
      if (negate) target_move = -target_move;
      if (moving_bullet)
	{
	  pset(bullet_x, bullet_y, ColorRGB(255, 10, 80));
	  bullet_y++;
	  if (bullet_y == attr.height) moving_bullet = false;
	}
      redraw();
    }  
  return 0;
}
