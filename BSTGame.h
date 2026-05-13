#ifndef BSTGAME_H
#define BSTGAME_H

#include <iostream>
#include <string>

using namespace std;

class BSTGame {
private:
// Node class 
  class Node {
  public:
      string question;
      int points;
      string correctAnswer;

      Node* left;
      Node* right;
      Node(string q, int p, string ans);
};

// starting point
Node* root;

//functions for recursion
void deleteTree(Node* node);
int maxPoints(Node* node);

public:
// builds game(constructor)
  BSTGame();
// clears memory(deconstructor)
  ~BSTGame();

  void game();
  int maxPoints();
};

#endif
