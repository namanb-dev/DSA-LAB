// Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining
// nodes after multiples of k should be left as it is.

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

    Node* reverseK(Node* h, int k) {
        Node* curr = h;
        Node* prev = NULL;
        Node* nxt = NULL;

        int c = 0;
        for (; curr && c < k; c++) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        if (nxt)
            h->next = reverseK(nxt, k);

        return prev;
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
    l.add(2);
    l.add(3);
    l.add(4);
    l.add(5);
    l.add(6);
    l.add(7);

    int k = 3;
    l.head = l.reverseK(l.head, k);

    l.print();
    return 0;
}
