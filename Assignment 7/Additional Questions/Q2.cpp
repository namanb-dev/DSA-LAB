// Radix sort

#include <iostream>
using namespace std;

class Sort {
public:
    static int getMax(int a[], int n) {
        int m = a[0];
        for (int i = 1; i < n; i++)
            if (a[i] > m) m = a[i];
        return m;
    }

    static void countDigit(int a[], int n, int exp) {
        int count[10], out[n];
        for (int i = 0; i < 10; i++) count[i] = 0;

        for (int i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
            out[--count[(a[i] / exp) % 10]] = a[i];

        for (int i = 0; i < n; i++)
            a[i] = out[i];
    }

    static void radixSort(int a[], int n) {
        int m = getMax(a, n);
        for (int exp = 1; m / exp > 0; exp *= 10)
            countDigit(a, n, exp);
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

    Sort::radixSort(a, n);
    Sort::display(a, n);

    return 0;
}
