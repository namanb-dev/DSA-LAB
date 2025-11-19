// counting sort

#include <iostream>
using namespace std;

class Sort {
public:
    static void countingSort(int a[], int n) {
        int maxVal = a[0];
        for (int i = 1; i < n; i++)
            if (a[i] > maxVal) maxVal = a[i];

        int count[maxVal + 1];
        for (int i = 0; i <= maxVal; i++)
            count[i] = 0;

        for (int i = 0; i < n; i++)
            count[a[i]]++;

        for (int i = 1; i <= maxVal; i++)
            count[i] += count[i - 1];

        int output[n];
        for (int i = n - 1; i >= 0; i--)
            output[--count[a[i]]] = a[i];

        for (int i = 0; i < n; i++)
            a[i] = output[i];
    }

    static void display(int a[], int n) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    int n, a[50];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    Sort::countingSort(a, n);
    Sort::display(a, n);

    return 0;
}
