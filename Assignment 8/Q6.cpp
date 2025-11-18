// Implement priority queues using heaps.

#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int heap[100];
    int size;
    bool maxHeap;

    void moveUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            bool shouldSwap = maxHeap ? (heap[i] > heap[parent]) : (heap[i] < heap[parent]);
            if (shouldSwap) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }

    void moveDown(int i) {
        while (true) {
            int priority = i;
            int left = 2 * i + 1, right = 2 * i + 2;
            
            if (maxHeap) {
                if (left < size && heap[left] > heap[priority]) priority = left;
                if (right < size && heap[right] > heap[priority]) priority = right;
            } else {
                if (left < size && heap[left] < heap[priority]) priority = left;
                if (right < size && heap[right] < heap[priority]) priority = right;
            }
            
            if (priority != i) {
                swap(heap[i], heap[priority]);
                i = priority;
            } else break;
        }
    }

public:
    PriorityQueue(bool isMax = true) : size(0), maxHeap(isMax) {}

    void insert(int val) {
        heap[size] = val;
        moveUp(size);
        size++;
    }

    int remove() {
        int top = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) moveDown(0);
        return top;
    }

    int top() { return heap[0]; }
    bool empty() { return size == 0; }

    void show() {
        for (int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    cout << "Max Priority Queue (Higher number = Higher priority)\n";
    PriorityQueue maxPQ(true);
    
    maxPQ.insert(5);
    maxPQ.insert(20);
    maxPQ.insert(10);
    maxPQ.insert(3);
    maxPQ.insert(15);
    
    cout << "Queue: "; maxPQ.show();
    cout << "Processing: ";
    while (!maxPQ.empty()) cout << maxPQ.remove() << " ";
    cout << "\n\n";
    
    cout << "Min Priority Queue (Lower number = Higher priority)\n";
    PriorityQueue minPQ(false);
    
    minPQ.insert(5);
    minPQ.insert(20);
    minPQ.insert(10);
    minPQ.insert(3);
    minPQ.insert(15);
    
    cout << "Queue: "; minPQ.show();
    cout << "Processing: ";
    while (!minPQ.empty()) cout << minPQ.remove() << " ";
    cout << endl;
    
    return 0;
}
