#include <iostream>
using namespace std;
#define MAX 50

void readSparse(int mat[MAX][3]) {
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];
    cout << "Enter non-zero elements (row col value):\n";
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


void addSparse(int a[MAX][3], int b[MAX][3], int sum[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Matrices cannot be added!\n";
        return;
    }

    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];

    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0]; sum[k][1] = a[i][1]; sum[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (a[i][0] == b[j][0] && b[j][1] < a[i][1])) {
            sum[k][0] = b[j][0]; sum[k][1] = b[j][1]; sum[k][2] = b[j][2];
            j++; k++;
        }
        else {
            sum[k][0] = a[i][0]; sum[k][1] = a[i][1]; 
            sum[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        }
    }

    while (i <= a[0][2]) {
        sum[k][0] = a[i][0]; sum[k][1] = a[i][1]; sum[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        sum[k][0] = b[j][0]; sum[k][1] = b[j][1]; sum[k][2] = b[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1; 
}

int main() {
    int a[MAX][3], b[MAX][3], sum[MAX][3];

    cout << "Enter first sparse matrix:\n";
    readSparse(a);

    cout << "Enter second sparse matrix:\n";
    readSparse(b);

    addSparse(a, b, sum);

    cout << "\nFirst Matrix:";
    printSparse(a);

    cout << "\nSecond Matrix:";
    printSparse(b);

    cout << "\nSum Matrix:";
    printSparse(sum);

   
}
