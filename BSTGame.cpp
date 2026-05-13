#include "BSTGame.h"

// Node constructor creates 1 node
BSTGame::Node::Node(string q, int p, string ans) {
    question = q;
    points = p;
    correctAnswer = ans;

    left = nullptr;
    right = nullptr;
}
//BST constructor O n
BSTGame::BSTGame() {
    root = new Node(
        "You awake in a place called limgrave. Do you wish to go to west? (yes/no) ",
        10,
        "yes"
    );
    root->left = new Node(
        "You go west and end up in a place called caelid and stumble upom a katana called moonveil. You enter a castle far into caelid and go down a Lift and see the Lagendary Warrior Radahn. Do you wish to fight him? (yes/no)",
        20,
        "yes"
    );
    root->right = new Node(
        "You head north to the Capital where the erdtree is located. You go to the foot of the Erdtree. Do you wish to enter? (yes/no)",
        10,
        "yes"
    );
    root->left->left = new Node(
        "You and Radahn battle it out and in a hard fought fight you are the victor and sit alone in the Red Desert of Caelid!",
        500,
        "yes"
    );
    root->left->right = new Node(
        "You turn your back on radahn and he strikes you down in a blink of an eye. Your journey ends here",
        -100000,
        "yes"
    );
    root->right->left = new Node(
        "As you enter the Erdtree the legendary Rivers of blood katana spawns in your hand. You see the Legendary Elden beast and defeat it in battle. You have now became the Elden Lord",
        1000000,
        "yes"
    );
    root->right->right = new Node(
        "You turn your back on the Erdtree. You walk away and the first Elden Lord Godfrey strikes you down because you have no weapons.  You Died.",
        -50000,
        "yes"
    );
}
BSTGame::~BSTGame() {
    deleteTree(root);
}
void BSTGame::deleteTree(Node* node) {

    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

//Follows one path oh...
void BSTGame::game() {

    Node* current = root;

    int totalPoints = 0;

    string answer;

    cout << "===== Elden Ring Adventure =====" << endl;

    while (current != nullptr) {

        cout << endl;
        cout << current->question << endl;

        totalPoints += current->points;

        cout << "Runes gained/lost: "
             << current->points << endl;

        if (current->left == nullptr &&
            current->right == nullptr) {

            break;
        }

        cout << "Answer: ";
        cin >> answer;

        if (answer == current->correctAnswer) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    cout << endl;
    cout << "===== Journey Complete =====" << endl;
    cout << "Total Runes: "
         << totalPoints << endl;
}
//Checks highest scoring path
int BSTGame::maxPoints(Node* node) {
//nothing? return 0
    if (node == nullptr)
        return 0;
//checks both paths and adds current points to better
    if (node->left == nullptr &&
        node->right == nullptr) {

        return node->points;
    }
    int leftMax = maxPoints(node->left);
    int rightMax = maxPoints(node->right);

    return node->points + max(leftMax, rightMax);
}

int BSTGame::maxPoints() {
    return maxPoints(root);
}



//g++ main.cpp BSTGame.cpp -o game
//./game
