// The school cafeteria offers circular and square sandwiches at lunch break, referred to by
// numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or
// circular sandwiches. The number of sandwiches in the cafeteria is equal to the number of students. The
// sandwiches are placed in a stack. At each step:
// ● If the student at the front of the queue prefers the sandwich on the top of the stack, they
// will take it and leave the queue.
// ● Otherwise, they will leave it and go to the queue's end.
// This continues until none of the queue students want to take the top sandwich and are thus
// unable to eat
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0

#include <iostream>
using namespace std;

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
    int frontVal() { return a[front]; }
    int size() { return empty() ? 0 : rear - front + 1; }
};

class Cafeteria {
public:
    static int countUnable(int students[], int sandwiches[], int n) {

        Queue q;
        for (int i = 0; i < n; i++)
            q.enqueue(students[i]);

        int top = 0, rounds = 0;

        for (; top < n && !q.empty(); ) {

            if (q.frontVal() == sandwiches[top]) {
                q.dequeue();
                top++;
                rounds = 0;
            }
            else {
                int x = q.dequeue();
                q.enqueue(x);
                rounds++;

                if (rounds == q.size())
                    break;
            }
        }

        return q.size();
    }
};

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;

    cout << Cafeteria::countUnable(students, sandwiches, n);
    return 0;
}
