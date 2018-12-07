#include "help.h"
#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

struct color_picker {
  int black[3] = {0, 0, 0};
  int white[3] = {255, 255, 255};
  int red[3] = {255, 0, 0};
  int lime[3] = {0, 255, 0};
  int blue[3] = {0, 0, 255};
  int yellow[3] = {255, 255, 0};
  int cyan[3] = {0, 255, 255};
  int magenta[3] = {255, 0, 255};
  int silver[3] = {192, 192, 192};
  int gray[3] = {128, 128, 128};
  int maroon[3] = {128, 0, 0};
  int olive[3] = {128, 128, 0};
  int green[3] = {0, 128, 0};
  int purple[3] = {128, 0, 128};
  int teal[3] = {0, 128, 128};
  int navy[3] = {0, 0, 128};
  int dora[3] = {0, 135, 255};
  int BLACK = 0;
  int BLUE = 1;
  int GREEN = 2;
  int CYAN = 3;
  int RED = 4;
  int MAGENTA = 5;
  int BROWN = 6;
  int LIGHTGRAY = 7;
  int DARKGRAY = 8;
  int LIGHTBLUE = 9;
  int LIGHTGREEN = 10;
  int LIGHTCYAN = 11;
  int LIGHTRED = 12;
  int LIGHTMAGENTA = 13;
  int YELLOW = 14;
  int WHITE = 15;
};

int main() {
  color_picker cp;
  int x1 = 300, x2 = 450, y1 = 100, y2 = 200;
  for (int x1 = 300; x1 < 400; x1++, x2++) {
    myEllipse(tan(x1) * x1, cos(y1) * y1, tan(x2) * x2, y2, cp.dora, cp.blue);
    Sleep(200);
  }
}