// Write a program to check if a doubly linked list of characters is palindrome or not.

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char x) { data = x; next = prev = NULL; }
};

class DoublyList {
public:
    Node* head;

    DoublyList() { head = NULL; }

    void insertEnd(char x) {
        Node* t = new Node(x);
        if (!head) head = t;
        else {
            Node* p = head;
            for (; p->next; p = p->next);
            p->next = t;
            t->prev = p;
        }
    }

    bool isPalindrome() {
        if (!head) return true;

        // moving to last node
        Node* left = head;
        Node* right = head;
        for (; right->next; right = right->next);

        // checking hte characters
        for (; left != right && right->next != left; left = left->next, right = right->prev)
            if (left->data != right->data) return false;

        return true;
    }
};

int main() {
    DoublyList dl;

    dl.insertEnd('R');
    dl.insertEnd('A');
    dl.insertEnd('D');
    dl.insertEnd('A');
    dl.insertEnd('R');

    if (dl.isPalindrome()) 
        cout << "Palindrome" << endl;
    else 
        cout << "Not Palindrome" << endl;

    return 0;
}
