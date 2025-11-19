// Write a program to check if a linked list is Circular Linked List or not.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) { data = x; next = NULL; }
};

class List {
public:
    Node* head;

    List() { head = NULL; }

    void insertEnd(int x) {
        Node* t = new Node(x);

        if (!head) {
            head = t;
            return;
        }

        Node* p = head;
        for (; p->next; p = p->next);
        p->next = t;
    }

    bool isCircular() {
        if (!head) return false;

        Node* p = head->next;

        for (; p && p != head; p = p->next);

        return (p == head);
    }
};

int main() {
    List l;

    l.insertEnd(10);
    l.insertEnd(20);
    l.insertEnd(30);
  
    // l.head->next->next->next = l.head; // for making it circular

    if (l.isCircular())
        cout << "Circular Linked List" << endl;
    else
        cout << "Not Circular" << endl;

    return 0;
}
