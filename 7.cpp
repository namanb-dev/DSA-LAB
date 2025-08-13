#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    long long inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (right > left) {
        int mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long getInversionCount(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    vector<int> temp(n);
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    long long inversion_count = getInversionCount(arr);
    
    cout << "Number of inversions are: " << inversion_count << endl;

    return 0;
}