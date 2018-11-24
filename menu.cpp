#include <iostream>
#include <map>
using namespace std;

map<int, string> buildMenu(int size, string contents[]) {
  /*
    Constructs a hashmap for game menu
      Parameters:
      size (int): Size of the provided array
      contents (string): An array of n (size) containing elements

      Returns:
      menu (MAP): Pairing index and content elements.
  */

  map<int, string> menu;

  for (int i = 1; i <= size; i++)
    menu[i] = contents[i - 1];

  return menu;
}

// Defines the interface for the initial screen.
void displayMenu(map<int, string> &menu) {
  /*
  Displays the contents in the menu.
    Parameters:
    menu (MAP): Size of the provided array
  */

  for (int i = 1; i <= menu.size(); i++)
    cout << "(" << i << ") " << menu[i] << endl << endl;
}

int chooseMenu(map<int, string> &menu) {
  /*
    Prompts the user to choose the menu

    Parameters:
    menu (MAP)

    Return:
  */
  displayMenu(menu);
  int choice = 0;
  cout << "\nPlease Choose Your Option:\n>>> ";
  cin >> choice;

  // If provided choice is not present in the menu, ask again.
  while (menu.count(choice) == 0) {
    // https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number
    cin.clear();
    cin.ignore();
    cout << "Wrong selection, Please input again!\n>>> ";
    cin >> choice;
  }

  return choice;
}

int main() {
  // Display Welcome Screen!
  cout << R"(
########################################################
########################################################
########################################################
#              _______________________                 #
#                W E L C O M E  T O                    #
#               > BATTLE - PAINTERS <                  #
#              -----------------------                 #
########################################################
########################################################
########################################################
########################################################
########################################################
########################################################
)" << endl;

  string contents[5] = {"<Battle Mode>", "<Ranking Mode>", "<Register>",
                        "<Settings>", "<Quit>"};

  map<int, string> menu = buildMenu(5, contents);

  int x = chooseMenu(menu);
  cout << "You have chosen: " << menu[x] << endl;
  //   initMenu();
}