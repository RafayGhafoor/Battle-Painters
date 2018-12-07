#include "help.h"
#include <conio.h>
#include <iostream>
#include <map>
#include <string>
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

// Set the total area covered
int HEIGHT = 450, WIDTH = 300;

void getinput(int &key, int &key1) {
  isCursorKeyPressed(key);
  isKeyPressed(key1);
}

int main() {
  color_picker cp;

  // Draws boundary
  myRect(WIDTH, HEIGHT, 0, 0, cp.red, cp.dora);

  // Generate key-mapping for player 1 and 2
  map<string, int> KEYSET = {{"left", 1},   {"up", 2},    {"right", 3},
                             {"down", 4},   {"enter", 5}, {"left1", 8},
                             {"right1", 9}, {"up1", 6},   {"down1", 7}};

  int left = 50, top = 100, right = 100, bottom = 150;

  int left1 = 200, top1 = 250, right1 = 250, bottom1 = 300;

  // Draw Ellipse's at initial positions
  myEllipse(left, right, top, bottom, cp.red, cp.black);

  myEllipse(left1, right1, top1, bottom1, cp.yellow, cp.olive);

  // Set default direction for movement
  int key = KEYSET["right"], key1 = KEYSET["right1"];

  while (1) {
    getinput(key, key1);

    if (key1 == KEYSET["right1"] && left1 <= WIDTH - 50)
      myEllipse(++left1, right1, ++top1, bottom1, cp.yellow, cp.olive);

    if (key == KEYSET["right"] && left <= WIDTH - 50)
      myEllipse(++left, right, ++top, bottom, cp.red, cp.black);

    if (key == KEYSET["left"] && left > 0)
      myEllipse(--left, right, --top, bottom, cp.red, cp.black);

    if (key1 == KEYSET["left1"] && left1 > 0)
      myEllipse(--left1, right1, --top1, bottom1, cp.yellow, cp.olive);

    if (key1 == KEYSET["up1"] && right1 > 0)
      myEllipse(left1, --right1, top1, --bottom1, cp.yellow, cp.olive);

    if (key == KEYSET["up"] && right > 0)
      myEllipse(left, --right, top, --bottom, cp.red, cp.black);

    if (key1 == KEYSET["down1"] && right1 <= HEIGHT - 50)
      myEllipse(left1, ++right1, top1, ++bottom1, cp.yellow, cp.olive);

    if (key == KEYSET["down"] && right <= HEIGHT - 50)
      myEllipse(left, ++right, top, ++bottom, cp.red, cp.black);

    Sleep(3);
  }
}
