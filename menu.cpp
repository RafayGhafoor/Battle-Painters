#include <iostream>
#include <map>
#include <typeinfo>
using namespace std;

map<int, string> buildMenu(int size, string contents[])
{
  /*
    Constructs a hashmap for game menu
      Parameters:
      size (int): Size of the provided array
      contents (string): An array of n (size) containing elements

      Returns:
      menu (hashmap: Pairing index and content elements.
  */

  map<int, string> menu;

  for (int i = 1; i <= size - 1; i++)
    menu[i] = contents[i];

  return menu;
}

// Defines the interface for the initial screen.
void displayMenu(map<int, string> &menu)
{
  /*
  Displays the contents in the menu.
    Parameters:
    menu (int): Size of the provided array
  */

  for (int i = 1; i <= menu.size(); i++)
    cout << "(" << i << ") " << menu[i] << endl;
}

int chooseMenu(map<int, string> &menu)
{
  displayMenu(menu);
  int choice = 0;
  cout << "\nPlease Choose Your Option:\n>>> ";
  cin >> choice;

  // If provided choice is not present in the menu, ask again.
  while (menu.count(choice) == 0)
  {
    // https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number
    cin.clear();
    cin.ignore();
    cout << "Wrong selection, Please input again!\n>>> ";
    cin >> choice;
  }

  return choice;
}

int main()
{
  string contents[4] = {"<Battle Mode>", "<Ranking Mode>", "<Register>",
                        "<Settings>"};

  map<int, string> menu = buildMenu(4, contents);

  int x = chooseMenu(menu);
  cout << "You have chosen: " << menu[x] << endl;
  //   initMenu();
}