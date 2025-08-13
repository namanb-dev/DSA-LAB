#include <iostream>
#include <vector>

using namespace std;

// This function sorts the array in ascending order using a simple bubble sort.
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// This function counts the distinct elements in the array.
int countDistinct(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
        return 0;
    }

    // Sort the array using the custom bubble sort function
    bubbleSort(arr);

    int distinct_count = 1; // Start with 1, as the first element is always distinct

    // Iterate through the sorted array to count distinct elements
    for (int i = 1; i < n; ++i) {
        // If the current element is different from the previous one, it's a new distinct element.
        if (arr[i] != arr[i - 1]) {
            distinct_count++;
        }
    }

    return distinct_count;
}

int main() {
    vector<int> arr = {10, 20, 20, 10, 30, 10};

    cout << "Original array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    int distinct_count = countDistinct(arr);

    cout << "The number of distinct elements in the array is: " << distinct_count << endl;

    return 0;
}