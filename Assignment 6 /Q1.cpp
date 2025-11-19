// Develop a menu driven program for the following operations of on a Circular as well
// as a Doubly Linked List.
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and
// after/before a specific node).
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be
// deleted may appear as a head node, last node or a node in between.
// (c) Search for a node.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) { data = x; next = prev = NULL; }
};

class DoublyList {
public:
    Node* head;

    DoublyList() { head = NULL; }

    void insertFirst(int x) {
        Node* t = new Node(x);
        if (!head) head = t;
        else {
            t->next = head;
            head->prev = t;
            head = t;
        }
    }

    void insertLast(int x) {
        Node* t = new Node(x);
        if (!head) head = t;
        else {
            Node* p = head;
            for (; p->next; p = p->next);
            p->next = t;
            t->prev = p;
        }
    }

    void insertBefore(int key, int x) {
        if (!head) return;
        if (head->data == key) { insertFirst(x); return; }

        Node* p = head;
        for (; p && p->data != key; p = p->next);
        if (!p) return;

        Node* t = new Node(x);
        t->prev = p->prev;
        t->next = p;
        p->prev->next = t;
        p->prev = t;
    }

    void insertAfter(int key, int x) {
        Node* p = head;
        for (; p && p->data != key; p = p->next);
        if (!p) return;

        Node* t = new Node(x);
        t->next = p->next;
        t->prev = p;
        if (p->next) p->next->prev = t;
        p->next = t;
    }

    void deleteNode(int key) {
        if (!head) return;

        if (head->data == key) {
            Node* t = head;
            head = head->next;
            if (head) head->prev = NULL;
            delete t;
            return;
        }

        Node* p = head;
        for (; p && p->data != key; p = p->next);
        if (!p) return;

        if (p->prev) p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        delete p;
    }

    bool search(int key) {
        Node* p = head;
        for (; p; p = p->next)
            if (p->data == key) return true;
        return false;
    }

    void display() {
        for (Node* p = head; p; p = p->next)
            cout << p->data << " ";
        cout << endl;
    }
};


// ------------------- CIRCULAR LINKED LIST ------------------- //

class CircularList {
public:
    Node* head;

    CircularList() { head = NULL; }

    void insertFirst(int x) {
        Node* t = new Node(x);
        if (!head) {
            head = t;
            head->next = head->prev = head;
        } else {
            Node* last = head->prev;
            t->next = head;
            t->prev = last;
            last->next = t;
            head->prev = t;
            head = t;
        }
    }

    void insertLast(int x) {
        if (!head) { insertFirst(x); return; }

        Node* t = new Node(x);
        Node* last = head->prev;

        t->next = head;
        t->prev = last;
        last->next = t;
        head->prev = t;
    }

    void insertAfter(int key, int x) {
        if (!head) return;

        Node* p = head;
        for (; p->data != key; p = p->next)
            if (p->next == head) return;

        Node* t = new Node(x);
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }

    void insertBefore(int key, int x) {
        if (!head) return;

        Node* p = head;
        for (; p->data != key; p = p->next)
            if (p->next == head) return;

        if (p == head) { insertFirst(x); return; }

        Node* t = new Node(x);
        t->next = p;
        t->prev = p->prev;
        p->prev->next = t;
        p->prev = t;
    }

    void deleteNode(int key) {
        if (!head) return;

        Node* p = head;

        // find node
        for (; p->data != key; p = p->next)
            if (p->next == head) return;

        if (p->next == p) { delete p; head = NULL; return; }

        p->prev->next = p->next;
        p->next->prev = p->prev;

        if (p == head) head = p->next;

        delete p;
    }

    bool search(int key) {
        if (!head) return false;
        Node* p = head;
        for (; ; p = p->next) {
            if (p->data == key) return true;
            if (p->next == head) break;
        }
        return false;
    }

    void display() {
        if (!head) { cout << "Empty\n"; return; }

        Node* p = head;
        for (; ; p = p->next) {
            cout << p->data << " ";
            if (p->next == head) break;
        }
        cout << endl;
    }
};


// ------------------- MENU (Can choose DLL or CLL) ------------------- //

int main() {
    DoublyList dl;
    CircularList cl;
    int choice, listType, val, key;

    cout << "1. Doubly List\n2. Circular List\nChoose: ";
    cin >> listType;

    while (true) {
        cout << "\n1 Insert First\n2 Insert Last\n3 Insert After\n4 Insert Before\n";
        cout << "5 Delete Node\n6 Search\n7 Display\n8 Exit\nChoose: ";
        cin >> choice;

        if (choice == 8) break;

        cout << "Enter value: ";
        cin >> val;

        if (choice == 3 || choice == 4 || choice == 5) {
            cout << "Enter reference key: ";
            cin >> key;
        }

        if (listType == 1) {
            if (choice == 1) dl.insertFirst(val);
            if (choice == 2) dl.insertLast(val);
            if (choice == 3) dl.insertAfter(key, val);
            if (choice == 4) dl.insertBefore(key, val);
            if (choice == 5) dl.deleteNode(val);
            if (choice == 6) cout << (dl.search(val) ? "Found\n" : "Not Found\n");
            if (choice == 7) dl.display();
        } else {
            if (choice == 1) cl.insertFirst(val);
            if (choice == 2) cl.insertLast(val);
            if (choice == 3) cl.insertAfter(key, val);
            if (choice == 4) cl.insertBefore(key, val);
            if (choice == 5) cl.deleteNode(val);
            if (choice == 6) cout << (cl.search(val) ? "Found\n" : "Not Found\n");
            if (choice == 7) cl.display();
        }
    }

    return 0;
}
