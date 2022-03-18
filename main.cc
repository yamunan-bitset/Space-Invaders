#include "quickcg.h"
using namespace QuickCG;

struct SpaceShip
{
  double x = 240;
  double dx;
  double y = 10;
  unsigned offset = 10;
};

#define POSX rand() % 250

int main(int argc, char** argv)
{
  screen(256, 256, 0, "Space Invaders");
  bool running = true;
  SpaceShip ship;
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
      drawRect(ship.x, ship.y, ship.x+ship.offset, ship.y+ship.offset, RGB_Green);
      pset(POSX, 240, RGB_White);
      if (send_bullet)
	{ // TODO
	}
      ship.dx = 0;
      redraw();
    }
  
  return 0;
}
