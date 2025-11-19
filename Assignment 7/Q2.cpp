// A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
// every pass on the array, and place it at its correct position. The idea is to take also the maximum on
// every pass and place it at its correct position. So in every pass, we keep track of both maximum and
// minimum and array becomes sorted from both ends. Implement this logic.

#include <iostream>
using namespace std;

class Sort {
public:
    static void improvedSelection(int a[], int n) {

        for (int left = 0, right = n - 1; left < right; left++, right--) {

            int minIndex = left;
            int maxIndex = right;

            for (int i = left; i <= right; i++) {
                if (a[i] < a[minIndex]) minIndex = i;
                if (a[i] > a[maxIndex]) maxIndex = i;
            }

            // minimum at correct left position
            swap(a[left], a[minIndex]);

            // fixing the index if the element was moved by previous swap
            if (maxIndex == left) maxIndex = minIndex;

            // maximum at correct right position
            swap(a[right], a[maxIndex]);
        }
    }

    static void display(int a[], int n) {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    int a[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    Sort::improvedSelection(a, n);

    cout << "Sorted Array: ";
    Sort::display(a, n);

    return 0;
}
