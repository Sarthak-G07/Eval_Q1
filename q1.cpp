#include <iostream>
#include <vector>

using namespace std;

int determinant2x2(const vector<vector<int>>& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

int determinant3x3(const vector<vector<int>>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
         - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
         + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int determinantNxN(const vector<vector<int>>& matrix, int n) {
    if (n == 2) {
        return determinant2x2(matrix);
    }
    if (n == 3) {
        return determinant3x3(matrix);
    }
    int det = 0;
    vector<vector<int>> subMatrix(n - 1, vector<int>(n - 1));
    int sign = 1;
    for (int k = 0; k < n; ++k) {
        int subi = 0;
        for (int i = 1; i < n; ++i) {
            int subj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == k) continue;
                subMatrix[subi][subj] = matrix[i][j];
                ++subj;
            }
            ++subi;
        }
        det += sign * matrix[0][k] * determinantNxN(subMatrix, n - 1);
        sign = -sign;
    }
    return det;
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    if (n < 2) {
        cout << "Matrix size should be at least 2x2." << endl;
        return 1;
    }
    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the matrix elements row by row:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    int det = determinantNxN(matrix, n);
    cout << "The determinant of the matrix is: " << det << endl;
}


