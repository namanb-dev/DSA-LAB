#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int diff = (arr[n - 1] - arr[0]) / n;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] != diff) return arr[i] + diff;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 12};
    int n = 5;
    cout << "Missing number: " << findMissing(arr, n);
    return 0;
}
