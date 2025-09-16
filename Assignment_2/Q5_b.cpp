#include <iostream>
using namespace std;

void triDiagonalMatrix(int n) {
    int size = 3*n - 2;   
    int a[size];

    cout << "Enter " << size << " elements for tri-diagonal \n";
    for (int i = 0; i < size; i++) cin >> a[i];

    cout << "\nTri-diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << a[k++] << " ";         
            else if (i == j+1) cout << a[k++] << " "; 
            else if (i+1 == j) cout << a[k++] << " "; 
            else cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    triDiagonalMatrix(n);
   
}
