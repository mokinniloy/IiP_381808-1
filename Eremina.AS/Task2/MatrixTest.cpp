#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    int n1;
    cout << "Enter the size of the matrix: ";
    cin >> n1;
	Matrix M1(n1);

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            M1[i][j] = rand() % 1000;
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            cout << M1[i][j] << " ";
        }
        cout << endl;
    }

    int n2;
    cout << "Enter the size of the matrix: ";
    cin >> n2;
	Matrix M2(n2);

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            M2[i][j] = rand() % 1000;
        }
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            cout << M2[i][j] << " ";
        }
        cout << endl;
    }

    Matrix Res;

    Res = M1 + M2;

    cout << "Their summa: \n";
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            cout << Res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}