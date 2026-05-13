#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
// Node class stores
    int data;
    Node* next;
    Node* prev;

    Node(int value);
};

class DoublyLinkedList {
private:
//pointer
    Node* head;
    Node* tail;

// Helps sort list
    void insertSorted(Node*& sortedHead, Node*& sortedTail, Node* node);

    Node* getMiddle(Node* start);
    Node* merge(Node* left, Node* right);
    Node* mergeSortHelper(Node* start);

    Node* partition(Node* low, Node* high);
    void quickSortHelper(Node* low, Node* high);

    void updateTail();

public:
//constructs lisy and deconstructs memory
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_back(int value);
    void print();

    void insertionSort();
    void selectionSort();
    void mergeSort();
    void quickSort();
};

#endif#pragma once
