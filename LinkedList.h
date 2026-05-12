#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value);
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

    void insertSorted(Node*& sortedHead, Node*& sortedTail, Node* node);

    Node* getMiddle(Node* start);
    Node* merge(Node* left, Node* right);
    Node* mergeSortHelper(Node* start);

    Node* partition(Node* low, Node* high);
    void quickSortHelper(Node* low, Node* high);

    void updateTail();

public:
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
