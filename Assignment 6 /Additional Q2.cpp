// Given a Doubly linked list and Circular singly linked list containing N nodes, the task is
// to remove all the nodes from each list which contains elements whose parity is even. 

#include <iostream>
using namespace std;

int parity(int x) {
    int c = 0;
    for (; x; x >>= 1) c += (x & 1);
    return c;
}

class CLL {
public:
    struct Node { int d; Node* n; Node(int x):d(x),n(NULL){} };
    Node* head = NULL;

    void add(int x) {
        Node* t = new Node(x);
        if (!head) { head = t; head->n = head; }
        else {
            Node* p = head;
            for (; p->n != head; p = p->n);
            p->n = t; t->n = head;
        }
    }

    void removeEvenParity() {
        if (!head) return;

        Node *p = head, *prev = NULL;

        do {
            if (parity(p->d) % 2 == 0) {
                if (p == head) {
                    Node* last = head;
                    for (; last->n != head; last = last->n);
                    if (head->n == head) { head = NULL; return; }
                    head = head->n;
                    last->n = head;
                    p = head;
                } else {
                    prev->n = p->n;
                    p = prev->n;
                }
            } else {
                prev = p;
                p = p->n;
            }
        } while (p != head);
    }

    void print() {
        if (!head) { cout << "\n"; return; }
        Node* p = head;
        do {
            cout << p->d << " ";
            p = p->n;
        } while (p != head);
        cout << "\n";
    }
};

class DLL {
public:
    struct Node { int d; Node *l, *r; Node(int x):d(x),l(NULL),r(NULL){} };
    Node* head = NULL;

    void add(int x) {
        Node* t = new Node(x);
        if (!head) head = t;
        else {
            Node* p = head;
            for (; p->r; p = p->r);
            p->r = t; t->l = p;
        }
    }

    void removeEvenParity() {
        Node* p = head;
        for (; p;) {
            if (parity(p->d) % 2 == 0) {
                if (p->l) p->l->r = p->r;
                else head = p->r;
                if (p->r) p->r->l = p->l;
            }
            p = p->r;
        }
    }

    void print() {
        for (Node* p = head; p; p = p->r)
            cout << p->d << " ";
        cout << "\n";
    }
};

int main() {
    int type;
    cin >> type;

    int n, x;
    cin >> n;

    if (type == 1) {
        CLL cl;
        for (int i = 0; i < n; i++) { cin >> x; cl.add(x); }
        cl.removeEvenParity();
        cl.print();
    } else {
        DLL dl;
        for (int i = 0; i < n; i++) { cin >> x; dl.add(x); }
        dl.removeEvenParity();
        dl.print();
    }

    return 0;
}
