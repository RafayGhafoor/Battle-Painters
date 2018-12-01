#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream file("z.txt");
  string s;
  file.seekg(15);
  while (file) {
    if (s.compare("\n"))
      cout << "T";
    getline(file, s);
    cout << s << endl;
  }
}