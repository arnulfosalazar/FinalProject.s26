#include "BSTGame.h"

int main() {
  
    BSTGame game;
    game.game();

    cout << endl;
    cout << "Max Possible Points: "
         << game.maxPoints()
         << endl;

    return 0;
}
