#include "help.h"
#include <iostream>
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
  myRect(500, 100, 150, 600, cp.dora, cp.dora);
  myEllipse(200, 200, 250, 150, cp.white, cp.white);
  myEllipse(200, 400, 250, 350, cp.white, cp.white);
  system("pause");
  return 0;
}
