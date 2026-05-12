#include "BSTGame.h"

// Node constructor
BSTGame::Node::Node(string q, int p, string ans) {
    question = q;
    points = p;
    correctAnswer = ans;

    left = nullptr;
    right = nullptr;
}
BSTGame::BSTGame() {
    root = new Node(
        "A Tarnished maiden offers guidance. Accept her accord? (yes/no)",
        10,
        "yes"
    );
    root->left = new Node(
        "You discover a Site of Grace. Rest beside it? (yes/no)",
        20,
        "yes"
    );
    root->right = new Node(
        "A Rune Bear attacks from the woods! Fight it? (yes/no)",
        -10,
        "yes"
    );
    root->left->left = new Node(
        "You gain the blessing of the Erdtree! Victory awaits!",
        50,
        "yes"
    );
    root->left->right = new Node(
        "A hidden trap chest sends you to Caelid. Doom falls upon you!",
        -30,
        "yes"
    );
    root->right->left = new Node(
        "You slay the Rune Bear and claim legendary runes!",
        40,
        "yes"
    );
    root->right->right = new Node(
        "The Rune Bear crushes the Tarnished. You Died.",
        -50,
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
int BSTGame::maxPoints(Node* node) {

    if (node == nullptr)
        return 0;

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
