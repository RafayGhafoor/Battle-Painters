#include "help.h"
#include <iostream>

using namespace std;

int main() {
  int black[3] = {0, 0, 0};
  int cyan[3] = {0, 255, 255};

  int x1 = 50, y1 = 100, x2 = 100, y2 = 150;

  int HEIGHT = 550, WIDTH = 600;

  myRect(WIDTH, HEIGHT, 0, 0, black, cyan);

  myEllipse(x1, y1, x2, y2, cyan, black);

  int key;

  while (1) {
    isCursorKeyPressed(key);

    if (key == 1 && x1 > 0)
      myEllipse(x1--, y1, x2--, y2, cyan, black);

    if (key == 2 && y1 > 0)
      myEllipse(x1, y1--, x2, y2--, cyan, black);

    if (key == 3 && x2 < WIDTH)
      myEllipse(x1++, y1, x2++, y2, cyan, black);

    if (key == 4 && y2 < HEIGHT)
      myEllipse(x1, y1++, x2, y2++, cyan, black);

    Sleep(3);
  }
}