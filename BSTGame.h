#ifndef BSTGAME_H
#define BSTGAME_H

#include <iostream>
#include <string>

using namespace std;

class BSTGame {
private:

  class Node {
  public:
      string question;
      int points;
      string correctAnswer;

      Node* left;
      Node* right;
      Node(string q, int p, string ans);
};

Node* Roo;

void deleteTree(Node* node):
int maxPoints(Node* node);

public:
  BSTGame();
  ~BSTGame();

  void game();
  int maxPoints();
};

#endif
