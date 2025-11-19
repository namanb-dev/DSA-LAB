// Write a program to find size of
// i. Doubly Linked List.
// ii. Circular Linked List.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x) { data = x; next = prev = NULL; }
};

// ---------------- DOUBLY LINKED LIST ----------------
class DoublyList {
public:
    Node* head;

    DoublyList() { head = NULL; }

    void insertEnd(int x) {
        Node* t = new Node(x);
        if (!head) head = t;
        else {
            Node* p = head;
            for (; p->next; p = p->next);
            p->next = t;
            t->prev = p;
        }
    }

    int size() {
        int count = 0;
        for (Node* p = head; p; p = p->next) count++;
        return count;
    }
};

// ---------------- CIRCULAR LINKED LIST ----------------
class CircularList {
public:
    Node* head;

    CircularList() { head = NULL; }

    void insertEnd(int x) {
        Node* t = new Node(x);

        if (!head) {
            head = t;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* last = head->prev;
        last->next = t;
        t->prev = last;
        t->next = head;
        head->prev = t;
    }

    int size() {
        if (!head) return 0;

        int count = 0;
        Node* p = head;

        for (; ; p = p->next) {
            count++;
            if (p->next == head) break;
        }
        return count;
    }
};

int main() {

    DoublyList dl;
    dl.insertEnd(10);
    dl.insertEnd(20);
    dl.insertEnd(30);

    CircularList cl;
    cl.insertEnd(5);
    cl.insertEnd(15);
    cl.insertEnd(25);
    cl.insertEnd(35);

    cout << "Size of Doubly Linked List: " << dl.size() << endl;
    cout << "Size of Circular Linked List: " << cl.size() << endl;

    return 0;
}
