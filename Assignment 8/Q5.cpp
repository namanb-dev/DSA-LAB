// Implement Heapsort (Increasing/Decreasing order)

#include <iostream>
using namespace std;

// Maintain heap property by comparing with children in binary tree
void makeHeap(int arr[], int size, int index, bool isMaxHeap) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    
    if (isMaxHeap) {
        if (leftChild < size && arr[leftChild] > arr[largest])
            largest = leftChild;
        if (rightChild < size && arr[rightChild] > arr[largest])
            largest = rightChild;
    } else {
        if (leftChild < size && arr[leftChild] < arr[largest])
            largest = leftChild;
        if (rightChild < size && arr[rightChild] < arr[largest])
            largest = rightChild;
    }
    
    if (largest != index) {
        swap(arr[index], arr[largest]);
        makeHeap(arr, size, largest, isMaxHeap);
    }
}

void heapSort(int arr[], int n, bool sortAscending) {
    for (int i = n / 2 - 1; i >= 0; i--)
        makeHeap(arr, n, i, sortAscending);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        makeHeap(arr, i, 0, sortAscending);
    }
}

void display(int arr[], int n, const char* label) {
    cout << label;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = 7;
    
    int ascending[7], descending[7];
    
    for (int i = 0; i < size; i++) {
        ascending[i] = numbers[i];
        descending[i] = numbers[i];
    }
    
    display(numbers, size, "Original: ");
    
    heapSort(ascending, size, true);
    display(ascending, size, "Ascending: ");
    
    heapSort(descending, size, false);
    display(descending, size, "Descending: ");
    
    return 0;
}
