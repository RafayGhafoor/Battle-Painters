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

int HEIGHT = 450, WIDTH = 300;

int get_boundary(char axis = 'h') {
  int HEIGHT = 450, WIDTH = 300;

  if (axis == 'h')
    return WIDTH;

  return HEIGHT;
}
void move(char direction, int width = WIDTH, int height = HEIGHT);

int main() {
  // 1 - Left
  // 2 - Up
  // 3 - Right
  // 4 - Down
  // 5 - Enter
  color_picker cp;

  myRect(WIDTH, HEIGHT, 0, 0, cp.dora, cp.white);

  map<string, int> KEYSET = {
      {"left", 1}, {"up", 2}, {"right", 3}, {"down", 4}, {"enter", 5}};

  int left = 50, top = 100, right = 100, bottom = 150;

  while (1) {
    int key;
    isCursorKeyPressed(key);

    bool pressed = 1;

    while (key == KEYSET["right"]) {
      isCursorKeyPressed(key);
      left++;
      top++;
      myEllipse(left, right, top, bottom, cp.red, cp.black);
      Sleep(5);
    }

    while (key == KEYSET["left"]) {
      isCursorKeyPressed(key);
      top--;
      left--;
      myEllipse(left, right, top, bottom, cp.red, cp.black);
      Sleep(5);
    }

    while (key == KEYSET["up"]) {
      isCursorKeyPressed(key);
      right--;
      bottom--;
      myEllipse(left, right, top, bottom, cp.red, cp.black);
      Sleep(5);
    }

    while (key == KEYSET["down"]) {
      isCursorKeyPressed(key);
      bottom++;
      right++;
      myEllipse(left, right, top, bottom, cp.red, cp.black);
      Sleep(5);
    }
  }
  return 0;
}
