#include "help.h"
#include <map>
#include <math.h>
#include <string>
#include <windows.h>

using namespace std;

struct color_picker
{
  int black[3] = {0, 0, 0};
  int white[3] = {255, 255, 255};
  int cyan[3] = {0, 255, 255};
  int yellow[3] = {255, 255, 0};
  int GREEN = 2;
  int CYAN = 3;
  int RED = 4;
};

void getinput(int &key, int &key1)
{
  // Waits for the input from both users and modifies the key value to the
  // pressed value
  isCursorKeyPressed(key);
  isKeyPressed(key1);
}

bool isCollision(int x1, int y1, int x2, int y2, int v1, int w1, int v2,
                 int w2)
{
  // Checks if the two players collide with each other and return the modified
  // boolean value of collision

  bool collision = false;

  float r = (x2 - x1) / 2, R = (v2 - v1) / 2, centerV = (v1 + v2) / 2,
        centerW = (w1 + w2) / 2, centerX = (x1 + x2) / 2,
        centerY = (y1 + y2) / 2;

  float A = centerX - centerV;

  float B = centerY - centerW;

  if (r + R >= sqrt((A * A) + (B * B)))
    collision = true;

  return collision;
}

int main()
{
  // Set the total area covered

  int HEIGHT = 550, WIDTH = 600;

  color_picker cp;

  // Distance from left and right corners of the screen

  int left_offset = 20, up_offset = 30;

  // Draws boundary
  myRect(WIDTH, HEIGHT, left_offset, up_offset, cp.white, cp.white);

  // Generate key-mapping for player 1 and 2
  map<string, int> DIRECTION = {{"left", 1}, {"up", 2}, {"right", 3}, {"down", 4}, {"enter", 5}, {"left1", 6}, {"up1", 7}, {"right1", 8}, {"down1", 9}};

  // Define Coordinates for player 1
  int x1 = 50, y1 = 100, x2 = 100, y2 = 150;

  // Define Coordinates for player 2
  int v1 = 200, w1 = 250, v2 = 250, w2 = 300;

  // Draw Ellipse's at initial positions

  // Player 1
  myEllipse(x1, y1, x2, y2, cp.cyan, cp.black);

  // PlayeR
  myEllipse(v1, w1, v2, w2, cp.yellow, cp.black);

  // Set default direction for movement
  int key = DIRECTION["up"], key1 = DIRECTION["down1"];

  // mseconds = Milliseconds
  int timer = 0, mseconds = 35, counter = mseconds, threshold = 2,
      sleep_timer = 5, collision_timeout = 4, note_timer = 0;

  bool collision_enabled = 0, test = 1;

  // Sets the colour for the timer
  setTextColor(cp.GREEN);
  cout << "\t\t\t<TIMER> ";

  // Conversion from milliseconds to seconds | mseconds * 10 ^ 3 |
  while (timer <= mseconds * 1000)
  {

    if (timer % (threshold * 1000) == 0)
    {
      cout << '*';
      counter -= threshold;
    }

    if (counter == mseconds / 3) // When 1/3 time is remaining
      setTextColor(cp.RED);

    if (counter == mseconds / 2) // When half  time is passed
      setTextColor(cp.CYAN);

    getinput(key, key1);

    if (key1 == DIRECTION["right1"] && v2 <= WIDTH)
      myEllipse(++v1, w1, ++v2, w2, cp.yellow, cp.black);

    if (key1 == DIRECTION["left1"] && v1 > left_offset)
      myEllipse(--v1, w1, --v2, w2, cp.yellow, cp.black);

    if (key1 == DIRECTION["up1"] && w1 > up_offset)
      myEllipse(v1, --w1, v2, --w2, cp.yellow, cp.black);

    if (key1 == DIRECTION["down1"] && w2 <= HEIGHT)
      myEllipse(v1, ++w1, v2, ++w2, cp.yellow, cp.black);

    if (key == DIRECTION["right"] && x2 <= WIDTH)
      myEllipse(++x1, y1, ++x2, y2, cp.cyan, cp.black);

    if (key == DIRECTION["left"] && x1 > left_offset)
      myEllipse(--x1, y1, --x2, y2, cp.cyan, cp.black);

    if (key == DIRECTION["up"] && y1 > up_offset)
      myEllipse(x1, --y1, x2, --y2, cp.cyan, cp.black);

    if (key == DIRECTION["down"] && y2 <= HEIGHT)
      myEllipse(x1, ++y1, x2, ++y2, cp.cyan, cp.black);

    if (!collision_enabled && isCollision(x1, y1, x2, y2, v1, w1, v2, w2))
    {
      collision_enabled = true;
      // Set the opposite direction
      if (key1 > 5 && key1 < 8)
        key1 += 2;

      else if (key1 > 7 && key1 <= 9)
        key1 -= 2;

      if (key > 0 && key < 3)
        key += 2;

      else if (key > 2 && key <= 4)
        key -= 2;

      note_timer = timer;
      sleep_timer *= 5;
    }

    if (test && collision_enabled &&
        timer >= note_timer + collision_timeout * 1000)
    {
      sleep_timer /= collision_timeout;
      test = false;
      collision_enabled = false;
    }

    // else if (collision_timeout <= 0) {
    //   sleep_timer /= 5;
    // }

    Sleep(sleep_timer);
    timer += sleep_timer; // mseconds * 10 + Sleep_count
  }
  cout << endl;
  system("cls");
}
