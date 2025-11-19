// Write a program to implement following sorting techniques:
// a. Selection Sort
// b. Insertion Sort
// c. Bubble Sort
// d. Merge Sort
// e. Quick Sort

#include <iostream>
using namespace std;

class Sort {
public:

    // a) SELECTION SORT
    static void selection(int a[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[minIndex]) minIndex = j;
            swap(a[i], a[minIndex]);
        }
    }

    // b) INSERTION SORT
    static void insertion(int a[], int n) {
        for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            for (; j >= 0 && a[j] > key; j--)
                a[j + 1] = a[j];
            a[j + 1] = key;
        }
    }

    // c) BUBBLE SORT
    static void bubble(int a[], int n) {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }

    // MERGE FUNCTION
    static void merge(int a[], int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        int L[n1], R[n2];

        for (int i = 0; i < n1; i++) L[i] = a[l + i];
        for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

        int i = 0, j = 0, k = l;

        for (; i < n1 && j < n2; k++)
            a[k] = (L[i] < R[j]) ? L[i++] : R[j++];

        for (; i < n1; i++, k++) a[k] = L[i];
        for (; j < n2; j++, k++) a[k] = R[j];
    }

    // d) MERGE SORT
    static void mergeSort(int a[], int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }

    // PARTITION FOR QUICK SORT
    static int partition(int a[], int low, int high) {
        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
            if (a[j] < pivot) swap(a[++i], a[j]);

        swap(a[i + 1], a[high]);
        return i + 1;
    }

    // e) QUICK SORT
    static void quickSort(int a[], int low, int high) {
        if (low < high) {
            int p = partition(a, low, high);
            quickSort(a, low, p - 1);
            quickSort(a, p + 1, high);
        }
    }

    // Display array
    static void display(int a[], int n) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    int a[50], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "\n1 Selection Sort\n2 Insertion Sort\n3 Bubble Sort\n4 Merge Sort\n5 Quick Sort\nChoose: ";
    cin >> choice;

    if (choice == 1) Sort::selection(a, n);
    if (choice == 2) Sort::insertion(a, n);
    if (choice == 3) Sort::bubble(a, n);
    if (choice == 4) Sort::mergeSort(a, 0, n - 1);
    if (choice == 5) Sort::quickSort(a, 0, n - 1);

    cout << "\nSorted Array: ";
    Sort::display(a, n);

    return 0;
}
