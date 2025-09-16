#include <iostream>
using namespace std;
#define MAX 50


void readSparse(int mat[MAX][3]) {
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];

    cout << "Enter non-zero elements :\n";
    for (int i = 1; i <= mat[0][2]; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}


void printSparse(int mat[MAX][3]) {
    cout << "\nRow Col Val\n";
    for (int i = 0; i <= mat[0][2]; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}


void transposeSparse(int mat[MAX][3], int trans[MAX][3]) {
    int rows = mat[0][0], cols = mat[0][1], nonZero = mat[0][2];
    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = nonZero;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= nonZero; j++) {
            if (mat[j][1] == i) {
                trans[k][0] = mat[j][1];
                trans[k][1] = mat[j][0];
                trans[k][2] = mat[j][2];
                k++;
            }
        }
    }
}

int main() {
    int mat[MAX][3], trans[MAX][3];

    readSparse(mat);
    cout << "\nOriginal Matrix (Triplet form):";
    printSparse(mat);

    transposeSparse(mat, trans);
    cout << "\nTranspose (Triplet form):";
    printSparse(trans);

   
}
