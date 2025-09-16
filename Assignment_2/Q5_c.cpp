#include <iostream>
using namespace std;

void lowerTriangular(int n) {
    int size = (n*(n+1))/2;
    int a[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) cin >> a[i];

    cout << "\nlower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << a[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    lowerTriangular(n);
  
}
