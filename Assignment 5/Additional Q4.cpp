// Given a linked list, and an integer k, rotate the list to the left by k positions and return
// the updated head.

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

    Node* rotateLeft(int k) {
        if (!head || k == 0) return head;

        int n = 0;
        Node* p = head;
        for (; p; p = p->next) n++;

        k = k % n;
        if (k == 0) return head;

        Node* curr = head;
        for (int i = 1; i < k; i++)
            curr = curr->next;

        Node* newHead = curr->next;
        curr->next = NULL;

        Node* q = newHead;
        for (; q->next; q = q->next);
        q->next = head;

        return newHead;
    }

    void print() {
        for (Node* p = head; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }
};

int main() {
    List l;
    l.add(10);
    l.add(20);
    l.add(30);
    l.add(40);
    l.add(50);

    int k = 4;
    l.head = l.rotateLeft(k);
    l.print();
    return 0;
}
