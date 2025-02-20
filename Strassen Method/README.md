# Strassen Method
This C++ program implements matrix multiplication using the Divide and Conquer approach. Let me break down the code step by step for clarity.

## 1. Split Function

``` C++
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
```
Purpose:
This function extracts a submatrix from the given matrix by specifying row and column ranges. It's used to divide the matrix into 4 quadrants.

**Example Input:**

For matrix ` A = {{1,2},{3,4}}`,
`split(A,0,1,0,1)` returns `{{1}}`.

## 2. Brute-Force Matrix Multiplication

``` C++
vector<vector<int>> bruteForce(vector<vector<int>> A, vector<vector<int>> B) {
    int row_a = A.size();         // Rows of A
    int column_a = A[0].size();   // Columns of A (same as rows of B)
    int column_b = B[0].size();   // Columns of B
    vector<vector<int>> resultMatrix(row_a, vector<int>(column_b, 0));

    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < column_b; j++) {
            for (int k = 0; k < column_a; k++) {
                resultMatrix[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return resultMatrix;
}
```
Performs traditional matrix multiplication by iterating through rows of `A` and columns of `B`.

**Example:**
For A = [[1,2],[3,4]] and B = [[5,6],[7,8]],
result = [[19,22],[43,50]]

## 3. Addition Function
