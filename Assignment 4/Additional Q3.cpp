// Given a Queue consisting of first n natural numbers (in random order). The task is to check whether
// the given Queue elements can be arranged in increasing order in another Queue using a stack. The
// operation allowed are:
// 1. Push and pop elements from the stack
// 2. Pop (Or Dequeue) from the given Queue.
// 3. Push (Or Enqueue) in the another Queue.
// Input : Queue[] = { 5, 1, 2, 3, 4 }
// Output : Yes

#include <iostream>
using namespace std;

class Stack {
public:
    int a[50], top;
    Stack() { top = -1; }
    bool empty() { return top == -1; }
    void push(int x) { a[++top] = x; }
    int pop() { return a[top--]; }
    int peek() { return a[top]; }
};

class Queue {
public:
    int a[50], front, rear;

    Queue() { front = rear = -1; }

    void enqueue(int x) {
        if (rear == 49) return;
        if (front == -1) front = 0;
        a[++rear] = x;
    }

    int dequeue() {
        int x = a[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }

    bool empty() { return front == -1; }
};

class CheckQueue {
public:
    static bool canBeSorted(int q[], int n) {

        Queue input, output;
        Stack st;

        for (int i = 0; i < n; i++)
            input.enqueue(q[i]);

        int expected = 1;

        for (; expected <= n; expected++) {

            if (!st.empty() && st.peek() == expected) {
                st.pop();
                output.enqueue(expected);
                continue;
            }

            for (; !input.empty() && input.a[input.front] != expected; ) {
                st.push(input.dequeue());
            }

            if (!input.empty() && input.a[input.front] == expected) {
                input.dequeue();
                output.enqueue(expected);
                continue;
            }

            if (!st.empty() && st.peek() == expected) {
                st.pop();
                output.enqueue(expected);
            }
            else return false;
        }
        return true;
    }
};

int main() {
    int q[] = {5, 1, 2, 3, 4};
    int n = 5;

    if (CheckQueue::canBeSorted(q, n))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
