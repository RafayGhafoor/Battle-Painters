#include <fstream>
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
  string are;
  ifstream file("z.txt");

  cout << file.tellg() << endl;
  while (file) {
    getline(file, are);
    cout << are << endl;
    file.seekg(16);
    getline(file, are);
    cout << are << endl;
  }
}
