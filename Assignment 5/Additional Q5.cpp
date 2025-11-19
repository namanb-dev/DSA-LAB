// Given two polynomial numbers represented by two linked lists. The task is
// to add these lists (meaning the coefficients with the same variable powers will be
// added). 

#include <iostream>
using namespace std;

class Node {
public:
    int coef, pow;
    Node* next;
    Node(int c, int p) : coef(c), pow(p), next(NULL) {}
};

class Poly {
public:
    Node* head;
    Poly() : head(NULL) {}

    void addTerm(int c, int p) {
        Node* t = new Node(c, p);
        if (!head) head = t;
        else {
            Node* x = head;
            for (; x->next; x = x->next);
            x->next = t;
        }
    }

    Node* addPoly(Node* a, Node* b) {
        Node* res = NULL;
        Node* tail = NULL;

        for (; a || b; ) {
            int c = 0, p = 0;

            if (a && b && a->pow == b->pow) {
                c = a->coef + b->coef;
                p = a->pow;
                a = a->next;
                b = b->next;
            }
            else if (b == NULL || (a && a->pow > b->pow)) {
                c = a->coef;
                p = a->pow;
                a = a->next;
            }
            else {
                c = b->coef;
                p = b->pow;
                b = b->next;
            }

            Node* t = new Node(c, p);
            if (!res) res = tail = t;
            else { tail->next = t; tail = t; }
        }
        return res;
    }

    void print(Node* h) {
        for (; h; h = h->next)
            cout << "[" << h->coef << ", " << h->pow << "] ";
        cout << endl;
    }
};

int main() {
    Poly p1, p2;

    p1.addTerm(5,2);
    p1.addTerm(4,1);
    p1.addTerm(2,0);

    p2.addTerm(5,1);
    p2.addTerm(5,0);

    Node* ans = p1.addPoly(p1.head, p2.head);
    p1.print(ans);

    return 0;
}
