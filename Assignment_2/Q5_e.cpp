#include <iostream>
using namespace std;

void symmetricMatrix(int n) {
    int size = (n * (n + 1)) / 2; 
    int a[size];

    cout << "Enter " << size << " elements (lower triangle row-major):\n";
    for (int i = 0; i < size; i++) cin >> a[i];

    cout << "\nSymmetric Matrix:\n";
    int k = 0;
    int mat[n][n] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            mat[i][j] = a[k++];    
            mat[j][i] = mat[i][j]; 
        }
    }

  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    symmetricMatrix(n);

}
