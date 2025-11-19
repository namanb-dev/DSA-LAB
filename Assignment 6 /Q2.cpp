// Display all the node values in a circular linked list, repeating value of head node at the
// end too.
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) { data = x; next = NULL; }
};

class CircularList {
public:
    Node* head;

    CircularList() { head = NULL; }

    void insertEnd(int x) {
        Node* t = new Node(x);

        if (!head) {
            head = t;
            head->next = head;
            return;
        }

        Node* p = head;
        for (; p->next != head; p = p->next);
        p->next = t;
        t->next = head;
    }

    void displayWithRepeat() {
        if (!head) return;

        Node* p = head;

        // print all nodes
        for (; ; p = p->next) {
            cout << p->data << " ";
            if (p->next == head) break;
        }

        // print head again
        cout << head->data << endl;
    }
};

int main() {
    CircularList c;
    c.insertEnd(20);
    c.insertEnd(100);
    c.insertEnd(40);
    c.insertEnd(80);
    c.insertEnd(60);

    c.displayWithRepeat();

    return 0;
}
