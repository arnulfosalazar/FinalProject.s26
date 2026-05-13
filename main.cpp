#include "BSTGame.h"

int main() {
  //starts program
    BSTGame game;
  //creates game object
    game.game();

    cout << endl;
    cout << "Max Possible Points: "
         << game.maxPoints()
         << endl;

    return 0;
}
