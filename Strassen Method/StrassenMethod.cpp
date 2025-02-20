#include <iostream>
#include <vector>
using namespace std;

// Function to split a matrix into a submatrix defined by row and column ranges
vector<vector<int>> split(vector<vector<int>> matrix, int row_start, int row_end, int column_start, int column_end) {
    vector<vector<int>> submatrix;
    for (int i = row_start; i < row_end; i++) {
        vector<int> row;
        for (int j = column_start; j < column_end; j++) {
            row.push_back(matrix[i][j]);  // Add elements within the specified range
        }
        submatrix.push_back(row);
    }
    return submatrix;
}

// Function for standard matrix multiplication (brute-force approach)
vector<vector<int>> bruteForce(vector<vector<int>> A, vector<vector<int>> B) {
    int row_a = A.size();         // Number of rows in matrix A
    int column_a = A[0].size();   // Number of columns in matrix A
    int column_b = B[0].size();   // Number of columns in matrix B
    vector<vector<int>> resultMatrix;

    // Iterate through each row of A and column of B to calculate the product
    for (int i = 0; i < row_a; i++) {
        vector<int> row;
        for (int j = 0; j < column_b; j++) {
            int sum = 0;
            for (int k = 0; k < column_a; k++) {
                sum += A[i][k] * B[k][j];  // Multiply corresponding elements and sum
            }
            row.push_back(sum);  // Add the result to the current row
        }
        resultMatrix.push_back(row);  // Add the completed row to the result matrix
    }

    return resultMatrix;
}

// Function to add two matrices element-wise
vector<vector<int>> addition(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> result;
    for (int i = 0; i < a.size(); i++) {
        vector<int> row;
        for (int j = 0; j < a[0].size(); j++) {
            row.push_back(a[i][j] + b[i][j]);  // Add corresponding elements
        }
        result.push_back(row);
    }
    return result;
}

// Function to merge four submatrices into a single matrix
vector<vector<int>> merge(vector<vector<int>> c11, vector<vector<int>> c12, vector<vector<int>> c21, vector<vector<int>> c22) {
    int n = c11.size();
    vector<vector<int>> Matrix1, Matrix2;

    // Combine c11 and c21 into Matrix1, and c12 and c22 into Matrix2
    for (vector <int> row : c11){
        Matrix1.push_back(row);
    }

    for (vector <int> row : c21){
        Matrix2.push_back(row);
    }

    // Append c12 and c22 to the corresponding matrices
    for (int i = 0; i < Matrix1.size(); i++) {
        for (int j = 0; j < n; j++) {
            Matrix1[i].push_back(c12[i][j]);
            Matrix2[i].push_back(c22[i][j]);
        }
    }

    // Combine Matrix1 and Matrix2 into the final result
    for (vector<int> a : Matrix2) {
        Matrix1.push_back(a);
    }

    return Matrix1;
}

// Recursive function for matrix multiplication using divide and conquer
vector<vector<int>> matrixMultiplication(vector<vector<int>> A, vector<vector<int>> B) {
    int n_A = A.size();

    // Base case: Use brute-force multiplication for small matrices
    if (n_A <= 2) {
        return bruteForce(A, B);
    }

    // Split matrices A and B into 4 submatrices each
    vector<vector<int>> c11, c12, c21, c22, result;
    c11 = addition(matrixMultiplication(split(A, 0, n_A / 2, 0, n_A / 2), split(B, 0, n_A / 2, 0, n_A / 2)),
                   matrixMultiplication(split(A, 0, n_A / 2, n_A / 2, n_A), split(B, n_A / 2, n_A, 0, n_A / 2)));
    c12 = addition(matrixMultiplication(split(A, 0, n_A / 2, 0, n_A / 2), split(B, 0, n_A / 2, n_A / 2, n_A)),
                   matrixMultiplication(split(A, 0, n_A / 2, n_A / 2, n_A), split(B, n_A / 2, n_A, n_A / 2, n_A)));
    c21 = addition(matrixMultiplication(split(A, n_A / 2, n_A, 0, n_A / 2), split(B, 0, n_A / 2, 0, n_A / 2)),
                   matrixMultiplication(split(A, n_A / 2, n_A, n_A / 2, n_A), split(B, n_A / 2, n_A, 0, n_A / 2)));
    c22 = addition(matrixMultiplication(split(A, n_A / 2, n_A, 0, n_A / 2), split(B, 0, n_A / 2, n_A / 2, n_A)),
                   matrixMultiplication(split(A, n_A / 2, n_A, n_A / 2, n_A), split(B, n_A / 2, n_A, n_A / 2, n_A)));

    // Merge the results into the final matrix
    result = merge(c11, c12, c21, c22);

    return result;
}

int main() {
    // Define two matrices for multiplication
    vector<vector<int>> A = {{2, 4, 1, 7}, {5, 3, 6, 0}, {10, 9, 14, 4}, {3, 5, 1, 8}};
    vector<vector<int>> B = {{3, 1, 6, 9}, {10, 9, 4, 11}, {8, 17, 2, 0}, {-2, 5, 9, 4}};

    // Perform matrix multiplication and display the result
    for (vector<int> row : matrixMultiplication(A, B)) {
        for (int i : row) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}