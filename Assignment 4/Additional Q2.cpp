// Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The
// operations allowed on queue are:
// 1. enqueue() : Adds an item to rear of queue.
// 2. dequeue() : Removes an item from front of queue.
// 3. isEmpty() : Checks if a queue is empty.
// Input: 11, 5, 4, 21
// Output: 4, 5, 11, 21

#include <iostream>
using namespace std;

class Queue {
public:
    int a[50], front, rear;

    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }

    void enqueue(int x) {
        if (rear == 49) return;
        if (front == -1) front = 0;
        a[++rear] = x;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int x = a[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }

    int size() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    int findMinIndex(int sortedCount) {
        int n = size();
        int minIndex = -1;
        int minValue = 999999;

        for (int i = 0; i < n; i++) {
            int x = dequeue();
            if (i < n - sortedCount && x < minValue) {
                minValue = x;
                minIndex = i;
            }
            enqueue(x);
        }
        return minIndex;
    }

    int removeMin(int minIndex) {
        int n = size();
        int minValue = -1;

        for (int i = 0; i < n; i++) {
            int x = dequeue();
            if (i == minIndex) minValue = x;
            else enqueue(x);
        }
        return minValue;
    }

    void sortQueue() {
        int n = size();

        for (int i = 0; i < n; i++) {
            int minIndex = findMinIndex(i);
            int minValue = removeMin(minIndex);
            enqueue(minValue);
        }
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(11);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(21);

    q.sortQueue();
    q.display();

    return 0;
}
