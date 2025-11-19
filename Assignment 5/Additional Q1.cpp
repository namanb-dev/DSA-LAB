// Find the intersection node of two singly linked lists that merge into a Y-shaped structure.
// The lists may vary in length and have distinct nodes at the beginning, but from the point of
// intersection onward, they share the same sequence of nodes. The task is to identify the first
// common node where the two lists converge. If the two linked lists have no intersection at all,
// return null.

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
        if (!head) head = t;
        else {
            Node* p = head;
            for (; p->next; p = p->next);
            p->next = t;
        }
    }

    static int length(Node* h) {
        int c = 0;
        for (; h; h = h->next) c++;
        return c;
    }

    static Node* intersection(Node* a, Node* b) {
        int n1 = length(a), n2 = length(b);
        int d = (n1 > n2) ? n1 - n2 : n2 - n1;

        if (n1 > n2)
            for (int i = 0; i < d; i++) a = a->next;
        else
            for (int i = 0; i < d; i++) b = b->next;

        for (; a && b; a = a->next, b = b->next)
            if (a == b) return a;

        return NULL;
    }
};

int main() {
    // Example lists:
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    List l1, l2;
    l1.insertEnd(10);
    l1.insertEnd(20);
    l2.insertEnd(5);
    l2.insertEnd(7);

    // creating Y-shape
    Node* p = l1.head;
    for (; p->next; p = p->next);
    p->next = common;

    Node* q = l2.head;
    for (; q->next; q = q->next);
    q->next = common;

    Node* meet = List::intersection(l1.head, l2.head);

    if (meet) cout << meet->data;
    else cout << "null";

    return 0;
}
