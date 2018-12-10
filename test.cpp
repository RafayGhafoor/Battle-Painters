#include "help.h"
#include <iostream>
// #include <windows.h>

using namespace std;

int main()
{

  // Set default Height and Width
  int HEIGHT = 450, WIDTH = 300;

  // Defines colours for the ellipse's
  int w[3] = {255, 255, 255}, b[3] = {0, 0, 255};

  // Draw Boundary
  myRect(WIDTH, HEIGHT, 0, 0, w, b);

  // Set default coordinates for Ellipse
  int x1 = 50, y1 = 100, x2 = 100, y2 = 150;

  int key = 1;

  myEllipse(x1, y1, x2, y2, b, w);
  while (true)
  {
    isCursorKeyPressed(key);

    // Move Left
    if (key == 1 && x1 > 0)
      myEllipse(--x1, y1, --x2, y2, b, w);

    // Move Up
    if (key == 2 && y1 > 0)
      myEllipse(x1, --y1, x2, --y2, b, w);

    // Move Right
    if (key == 3 && x2 < WIDTH)
      myEllipse(++x1, y1, ++x2, y2, b, w);

    // Move Down
    if (key == 4 && y2 < HEIGHT)
      myEllipse(x1, ++y1, x2, ++y2, b, w);

    Sleep(3);
  }
}