// Given a linked list, remove the loop if it exists.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class List {
public:
    Node* head;
    List() : head(NULL) {}

    void add(int x) {
        Node* t = new Node(x);
        if (!head) head = t;
        else {
            Node* p = head;
            for (; p->next; p = p->next);
            p->next = t;
        }
    }

    void removeLoop() {
        Node *s = head, *f = head;

        for (; f && f->next; ) {
            s = s->next;
            f = f->next->next;
            if (s == f) break;
        }

        if (!f || !f->next) return;

        s = head;

        if (s != f) {
            for (; s->next != f->next; ) {
                s = s->next;
                f = f->next;
            }
            f->next = NULL;
        } else {
            for (; f->next != s; )
                f = f->next;
            f->next = NULL;
        }
    }

    void print() {
        for (Node* p = head; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }
};

int main() {
    List l;
    l.add(1);
    l.add(7);
    l.add(3);
    l.add(6);

    Node* p = l.head;
    for (; p->next; p = p->next);
    p->next = l.head->next;

    l.removeLoop();
    l.print();
    return 0;
}

