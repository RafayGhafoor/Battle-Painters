#include <iostream>
#include <windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
WORD wOldColorAttrs;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

void setTextColor(int color = 7, char def = 'n') {
  SetConsoleTextAttribute(h, color | FOREGROUND_INTENSITY);
  if (def == 'y')
    // Resets the text color
    SetConsoleTextAttribute(h, 7 | FOREGROUND_INTENSITY);
}

void gotoxy(int x, int y) {
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void myLine(int x1, int y1, int x2, int y2,
            int color[]) // use three 3 integers if you want colored lines.
{
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255) to get shades
  // of gray. For other colors use 3 integers for colors.
  HPEN pen =
      CreatePen(PS_SOLID, 2,
                RGB(color[0], color[1], color[2])); // 2 is the width of the pen
  SelectObject(device_context, pen);
  MoveToEx(device_context, x1, y1, NULL);
  LineTo(device_context, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
}

void myTriangle(int x1, int y1, int x2, int y2, int color[], int bg[]) {
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255) to get shades
  // of gray. For other colors use 3 integers for colors.
  HPEN pen =
      CreatePen(PS_SOLID, 2,
                RGB(color[0], color[1], color[2])); // 2 is the width of the pen
  SelectObject(device_context, pen);

  int mid = (x1 + x2) / 2;
  MoveToEx(device_context, mid, y1, NULL);
  LineTo(device_context, x2, y2);
  LineTo(device_context, x1, y2);
  LineTo(device_context, mid + 1, y1);

  HBRUSH brush =
      ::CreateSolidBrush(RGB(bg[0], bg[1], bg[2])); // Fill color is black
  SelectObject(device_context, brush);

  FloodFill(device_context, mid, (y1 + y2) / 2,
            RGB(color[0], color[1], color[2]));

  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
  DeleteObject(brush);
}

bool setKey(char key, int value, int &whickKey) {
  key = GetAsyncKeyState(key);
  if (key == 1) {
    whickKey = value;
    return true;
  }
  return false;
}

// This function checks if any of the 4 cursor keys are pressed.
// If any cursor key is pressed, then the function returns true, and whichKey
// identifies which of the 4 cursor keys is pressed. whichkey is assigned
// following values if any cursor key is pressed. 1 for left, 2 for up, 3 for
// right and 4 for left.
bool isCursorKeyPressed(int &whickKey) // whichKey passed as reference....
{
  // 1 - Left
  // 2 - Up
  // 3 - Right
  // 4 - Down
  // 5 - Enter
  char key;
  int default_key = 37;
  for (int i = 37; i <= 40; i++) {
    key = GetAsyncKeyState(i);
    if (key == 1) {
      whickKey = i - default_key + 1;
      return true;
    }
  }

  key = GetAsyncKeyState(13);

  if (key == 1) {
    whickKey = 5;
    return true;
  }

  return false;
}

bool isKeyPressed(int &whickKey) {

  if (setKey('A', 6, whickKey))
    return true;
  if (setKey('W', 7, whickKey))
    return true;
  if (setKey('D', 8, whickKey))
    return true;
  if (setKey('S', 9, whickKey))
    return true;

  return false;
}

void myRect(int x1, int y1, int x2, int y2, int color[], int bg[]) {
  HWND console_handle = GetConsoleWindow();
  // dimensions

  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 7, RGB(color[0], color[1], color[2]));
  SelectObject(device_context, pen);
  HBRUSH brush = ::CreateSolidBrush(
      RGB(bg[0], bg[1],
          bg[2])); // Fill color is passed as parameter to the function!!!

  SelectObject(device_context, brush);

  Rectangle(device_context, x1, y1, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
  DeleteObject(brush);
}

void myEllipse(int x1, int y1, int x2, int y2, int color[], int bg[]) {
  HWND console_handle = GetConsoleWindow();
  HDC device_context = GetDC(console_handle);

  // change the color by changing the values in RGB (from 0-255)
  HPEN pen = CreatePen(PS_SOLID, 5, RGB(color[0], color[1], color[2]));
  SelectObject(device_context, pen);
  HBRUSH brush =
      ::CreateSolidBrush(RGB(bg[0], bg[1], bg[2])); // Fill color is black
  SelectObject(device_context, brush);
  Ellipse(device_context, x1, y1, x2, y2);
  ReleaseDC(console_handle, device_context);
  DeleteObject(pen);
  DeleteObject(brush);
}
