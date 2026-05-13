#include "linkedlist.h"


Node::Node(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
}
//initialize empty list
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}
//add to end
void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::print() {
    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}
//insert in order
void DoublyLinkedList::insertSorted(Node*& sortedHead, Node*& sortedTail, Node* node) {
    node->next = nullptr;
    node->prev = nullptr;

    if (sortedHead == nullptr) {
        sortedHead = node;
        sortedTail = node;
    }
    else if (node->data <= sortedHead->data) {
        node->next = sortedHead;
        sortedHead->prev = node;
        sortedHead = node;
    }
    else if (node->data >= sortedTail->data) {
        sortedTail->next = node;
        node->prev = sortedTail;
        sortedTail = node;
    }
    else {
        Node* current = sortedHead;

        while (current != nullptr && current->data < node->data) {
            current = current->next;
        }

        node->next = current;
        node->prev = current->prev;
        current->prev->next = node;
        current->prev = node;
    }
}
//insertion Sort
void DoublyLinkedList::insertionSort() {
    Node* sortedHead = nullptr;
    Node* sortedTail = nullptr;

    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;
        insertSorted(sortedHead, sortedTail, current);
        current = nextNode;
    }

    head = sortedHead;
    tail = sortedTail;
}
//Selection Sort
void DoublyLinkedList::selectionSort() {
    Node* current = head;

    while (current != nullptr) {
        Node* minNode = current;
        Node* checker = current->next;

        while (checker != nullptr) {
            if (checker->data < minNode->data) {
                minNode = checker;
            }

            checker = checker->next;
        }

        int temp = current->data;
        current->data = minNode->data;
        minNode->data = temp;

        current = current->next;
    }
}
//find minddle
Node* DoublyLinkedList::getMiddle(Node* start) {
    if (start == nullptr) {
        return nullptr;
    }

    Node* slow = start;
    Node* fast = start->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* DoublyLinkedList::merge(Node* left, Node* right) {
    if (left == nullptr) {
        return right;
    }

    if (right == nullptr) {
        return left;
    }

    if (left->data <= right->data) {
        left->next = merge(left->next, right);

        if (left->next != nullptr) {
            left->next->prev = left;
        }

        left->prev = nullptr;
        return left;
    }
    else {
        right->next = merge(left, right->next);

        if (right->next != nullptr) {
            right->next->prev = right;
        }

        right->prev = nullptr;
        return right;
    }
}
//Recursive split merge
Node* DoublyLinkedList::mergeSortHelper(Node* start) {
    if (start == nullptr || start->next == nullptr) {
        return start;
    }

    Node* middle = getMiddle(start);
    Node* secondHalf = middle->next;

    middle->next = nullptr;

    if (secondHalf != nullptr) {
        secondHalf->prev = nullptr;
    }

    Node* left = mergeSortHelper(start);
    Node* right = mergeSortHelper(secondHalf);

    return merge(left, right);
}

void DoublyLinkedList::mergeSort() {
    head = mergeSortHelper(head);
    updateTail();
}
//rearage arround pivot
Node* DoublyLinkedList::partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            if (i == nullptr) {
                i = low;
            }
            else {
                i = i->next;
            }

            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }

    if (i == nullptr) {
        i = low;
    }
    else {
        i = i->next;
    }

    int temp = i->data;
    i->data = high->data;
    high->data = temp;

    return i;
}

void DoublyLinkedList::quickSortHelper(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(low, high);

        quickSortHelper(low, pivot->prev);
        quickSortHelper(pivot->next, high);
    }
}

void DoublyLinkedList::quickSort() {
    quickSortHelper(head, tail);
}

void DoublyLinkedList::updateTail() {
    tail = head;

    if (tail == nullptr) {
        return;
    }

    while (tail->next != nullptr) {
        tail = tail->next;
    }
}
