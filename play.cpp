#include "help.h"
#include <map>
#include <math.h>
#include <stdio.h>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

struct color_picker {
  int black[3] = {0, 0, 0};
  int white[3] = {255, 255, 255};
  int red[3] = {255, 0, 0};
  int lime[3] = {0, 255, 0};
  int blue[3] = {0, 0, 255};
  int cyan[3] = {0, 255, 255};
  int yellow[3] = {255, 255, 0};
  int GREEN = 2;
  int CYAN = 3;
  int RED = 4;
};

void getinput(int &key, int &key1) {
  // Waits for the input from both users and modifies the key value to the
  // pressed value
  isCursorKeyPressed(key);
  isKeyPressed(key1);
}

bool isCollision(int x1, int y1, int x2, int y2, int a1, int a2, int b1,
                 int b2) {
  // Checks if the two players collide with each other and return the modified
  // boolean value of collision

  bool collision = false;

  float r = (x2 - x1) / 2, R = (b1 - a1) / 2, centerV = (a1 + b1) / 2,
        centerW = (a2 + b2) / 2, centerX = (x1 + x2) / 2,
        centerY = (y1 + y2) / 2;

  float A = centerX - centerV;

  float B = centerY - centerW;

  if (r + R >= sqrt((A * A) + (B * B)))
    collision = true;

  return collision;
}

int main()

{
  time_t start = time(NULL);
  time_t seconds = 30;
  time_t endwait = start + seconds;

  // Set the total area covered

  int HEIGHT = 550, WIDTH = 600;

  color_picker cp;

  // Distance from left and right corners of the screen

  int left_offset = 20, up_offset = 30;

  myRect(WIDTH, HEIGHT, left_offset, up_offset, cp.white, cp.white);

  map<string, int> DIRECTION = {{"left", 1}, {"up", 2},     {"right", 3},
                                {"down", 4}, {"enter", 5},  {"left1", 6},
                                {"up1", 7},  {"right1", 8}, {"down1", 9}};

  int temp_time;

  int x1 = 50, y1 = 100, x2 = 100, y2 = 150;

  int a1 = 200, a2 = 250, b1 = 250, b2 = 300;

  myEllipse(x1, y1, x2, y2, cp.red, cp.black);

  myEllipse(a1, a2, b1, b2, cp.yellow, cp.black);

  int key = DIRECTION["up"], key1 = DIRECTION["down1"];

  int sleep_timer = 3, track_time = 30;

  int timer, eta;

  bool is_sec = true, collision_enabled = 0, timer_enabled = 0,
       restore_speed = false;

  setTextColor(cp.GREEN);

  cout << "\t<ETA> " << track_time << "s ";

  while (start < endwait) {

    if (endwait - start == track_time - 2 || !is_sec) {
      cout << endwait - start << "s ";
      is_sec = false;
      track_time -= 2;
    }

    is_sec = true;

    getinput(key, key1);

    if (key1 == DIRECTION["right1"] && b1 <= WIDTH)
      myEllipse(++a1, a2, ++b1, b2, cp.yellow, cp.black);

    if (key1 == DIRECTION["left1"] && a1 > left_offset)
      myEllipse(--a1, a2, --b1, b2, cp.yellow, cp.black);

    if (key1 == DIRECTION["up1"] && a2 > up_offset)
      myEllipse(a1, --a2, b1, --b2, cp.yellow, cp.black);

    if (key1 == DIRECTION["down1"] && b2 <= HEIGHT)
      myEllipse(a1, ++a2, b1, ++b2, cp.yellow, cp.black);

    if (key == DIRECTION["right"] && x2 <= WIDTH)
      myEllipse(++x1, y1, ++x2, y2, cp.red, cp.black);

    if (key == DIRECTION["left"] && x1 > left_offset)
      myEllipse(--x1, y1, --x2, y2, cp.red, cp.black);

    if (key == DIRECTION["up"] && y1 > up_offset)
      myEllipse(x1, --y1, x2, --y2, cp.red, cp.black);

    if (key == DIRECTION["down"] && y2 <= HEIGHT)
      myEllipse(x1, ++y1, x2, ++y2, cp.red, cp.black);

    if (!collision_enabled && isCollision(x1, y1, x2, y2, a1, a2, b1, b2)) {
      timer = track_time - 4;
      collision_enabled = true;

      if (isCollision(x1, y1, x2, y2, a1, a2, b1, b2)) {
        // Set the opposite direction
        if (key1 > 5 && key1 < 8)
          key1 += 2;

        else if (key1 > 7 && key1 <= 9)
          key1 -= 2;

        if (key > 0 && key < 3)
          key += 2;

        else if (key > 2 && key <= 4)
          key -= 2;
      }

      sleep_timer *= 3;
    }

    if (track_time == timer && !restore_speed) {
      sleep_timer /= 3;
      restore_speed = true;
      collision_enabled = false;
    }

    start = time(NULL);

    Sleep(sleep_timer);
  }

  cout << "Calculating Results" << endl;

  cout << endl;
  system("cls");
}
