// Develop a menu driven program demonstrating the following operations on Circular Queues:
// enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include <iostream>
using namespace std;
const int maxsize = 20;
class queue
{
    int front, rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    int arr[maxsize];
    bool isempty()
    {
        return ((front > rear) || rear == -1);
    }
    bool isfull()
    {
        return (front == (rear+1)%maxsize);
    }
    void enqueue(int n)
    {
        if (this->isfull())
        {
            cout << "overflow";
        }
        else
        {
            if (front == -1)
            {
                front++;
            }
            rear=(rear+1)%maxsize;
            arr[rear] = n;
        }
    }
    int dequeue()
    {
        if (this->isempty())
        {
            cout << "empty";
            return -1;
        }
        else
        {
            int val = arr[front];
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front+1)%maxsize;
        }
        return val;
        }
    }
    int peek()
    {
        return arr[front];
    }
    void display()
    {
        if (this->isempty())
            cout << "empty";
        else
        {
            int f = front;
            while (true){

                cout << arr[f];
                if(f==rear) break;
                f=(f+1)%maxsize;
            }
        }
    }
};

int main()
{
    queue q;
    int choice, value;

    do
    {
        cout << "\n\n--- Queue Operations Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter an integer value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            value = q.dequeue();
            if (value != -1)
            {
                cout << value << " was dequeued from the queue." << endl;
            }
            break;
        case 3:
            value = q.peek();
            if (value != -1)
            {
                cout << "Front element is: " << value << endl;
            }
            break;
        case 4:
            q.display();
            break;
        case 0:
            cout << "Exiting" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
