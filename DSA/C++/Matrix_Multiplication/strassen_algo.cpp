// Implement Strassen's Algorithm for Matrix Multiplication
//Time Complexity : O(n^2.81)
//Space Complexity : O(n^2)

#include <iostream>
#include <vector>
using namespace std;

// Add two matrices
vector<vector<int>> add(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Subtract matrix B from A
vector<vector<int>> subtract(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Split a matrix into 4 submatrices
void split(const vector<vector<int>> &A,
           vector<vector<int>> &A11, vector<vector<int>> &A12,
           vector<vector<int>> &A21, vector<vector<int>> &A22) {
    int n = A.size() / 2;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n];
            A21[i][j] = A[i + n][j];
            A22[i][j] = A[i + n][j + n];
        }
}

// Join 4 submatrices into one
vector<vector<int>> join(const vector<vector<int>> &C11, const vector<vector<int>> &C12,
                         const vector<vector<int>> &C21, const vector<vector<int>> &C22) {
    int n = C11.size();
    vector<vector<int>> C(2 * n, vector<int>(2 * n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + n] = C12[i][j];
            C[i + n][j] = C21[i][j];
            C[i + n][j + n] = C22[i][j];
        }
    return C;
}

// Strassen's Matrix Multiplication
vector<vector<int>> strassen(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int n = A.size();

    // Base case
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));

    // Split matrices
    split(A, A11, A12, A21, A22);
    split(B, B11, B12, B21, B22);

    // Calculate M1 to M7
    vector<vector<int>> M1 = strassen(add(A11, A22), add(B11, B22));
    vector<vector<int>> M2 = strassen(add(A21, A22), B11);
    vector<vector<int>> M3 = strassen(A11, subtract(B12, B22));
    vector<vector<int>> M4 = strassen(A22, subtract(B21, B11));
    vector<vector<int>> M5 = strassen(add(A11, A12), B22);
    vector<vector<int>> M6 = strassen(subtract(A21, A11), add(B11, B12));
    vector<vector<int>> M7 = strassen(subtract(A12, A22), add(B21, B22));

    // Calculate result submatrices
    vector<vector<int>> C11 = add(subtract(add(M1, M4), M5), M7);
    vector<vector<int>> C12 = add(M3, M5);
    vector<vector<int>> C21 = add(M2, M4);
    vector<vector<int>> C22 = add(subtract(add(M1, M3), M2), M6);

    // Combine result
    return join(C11, C12, C21, C22);
}

// Print matrix
void printMatrix(const vector<vector<int>> &M) {
    for (const auto &row : M) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter size of square matrices (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> B[i][j];

    vector<vector<int>> C = strassen(A, B);

    cout << "Result of A * B:\n";
    printMatrix(C);

    return 0;
}