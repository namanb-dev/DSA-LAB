#include <iostream>
using namespace std;

void diagonalMatrix(int n) {
    int a[n];
    cout << "Enter " << n << " diagonal elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << a[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    diagonalMatrix(n);
 
}
