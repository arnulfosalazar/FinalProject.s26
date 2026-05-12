#include <iostream>
#include "linkedlist.h"
using namespace std;

int main() {
    DoublyLinkedList list1;

    list1.push_back(4);
    list1.push_back(2);
    list1.push_back(5);
    list1.push_back(1);
    list1.push_back(3);

    cout << "Original list: ";
    list1.print();

    list1.insertionSort();
    cout << "Insertion sort: ";
    list1.print();

    DoublyLinkedList list2;
    list2.push_back(4);
    list2.push_back(2);
    list2.push_back(5);
    list2.push_back(1);
    list2.push_back(3);

    list2.selectionSort();
    cout << "Selection sort: ";
    list2.print();

    DoublyLinkedList list3;
    list3.push_back(4);
    list3.push_back(2);
    list3.push_back(5);
    list3.push_back(1);
    list3.push_back(3);

    list3.mergeSort();
    cout << "Merge sort: ";
    list3.print();

    DoublyLinkedList list4;
    list4.push_back(4);
    list4.push_back(2);
    list4.push_back(5);
    list4.push_back(1);
    list4.push_back(3);

    list4.quickSort();
    cout << "Quick sort: ";
    list4.print();

    return 0;
}