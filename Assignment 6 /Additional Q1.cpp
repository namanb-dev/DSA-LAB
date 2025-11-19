// Given a Circular linked list. The task is split into two Circular Linked lists. If there are an
// odd number of nodes in the given circular linked list then out of the resulting two halved
// lists, the first list should have one node more than the second list.
// Input: 10->4->9
// Output: 10->4 , 9

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class CList {
public:
    Node* head;
    Node* tail;

    CList() : head(NULL), tail(NULL) {}

    void add(int x) {
        Node* t = new Node(x);
        if (!head) {
            head = tail = t;
            head->next = head;
        } else {
            tail->next = t;
            tail = t;
            tail->next = head;
        }
    }

    static void split(Node* h, Node* &h1, Node* &h2) {
        if (!h || h->next == h) {
            h1 = h;
            h2 = NULL;
            return;
        }

        Node *slow = h, *fast = h;
        for (; fast->next != h && fast->next->next != h; ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next->next == h) fast = fast->next;

        h1 = h;
        h2 = slow->next;

        slow->next = h1;
        fast->next = h2;
    }

    static void printCirc(Node* h) {
        if (!h) {
            cout << "\n";
            return;
        }
        Node* p = h;
        for (;;) {
            cout << p->data << " ";
            p = p->next;
            if (p == h) break;
        }
        cout << "\n";
    }
};

int main() {
    int n;
    cin >> n;

    CList cl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cl.add(x);
    }

    Node *h1 = NULL, *h2 = NULL;
    CList::split(cl.head, h1, h2);

    CList::printCirc(h1);
    CList::printCirc(h2);

    return 0;
}
