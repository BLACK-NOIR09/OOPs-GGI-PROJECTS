#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, 0));
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
    for(int i = 0; i < rowsA; ++i)
        for(int j = 0; j < colsB; ++j)
            for(int k = 0; k < colsA; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(cols, vector<int>(rows, 0));
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            result[j][i] = A[i][j];
    return result;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for(const auto& row : matrix) {
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{2, 1, 3}, {6, 5, 6}, {7, 8, 9}};
    vector<vector<int>> B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    
    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "Matrix B:" << endl;
    printMatrix(B);
    
    cout << "Addition of A and B:" << endl;
    printMatrix(addMatrices(A, B));
    
    cout << "Multiplication of A and B:" << endl;
    printMatrix(multiplyMatrices(A, B));
    
    cout << "Transpose of A:" << endl;
    printMatrix(transposeMatrix(A));

    return 0;
}
