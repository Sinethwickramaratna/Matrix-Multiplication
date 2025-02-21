This C++ program implements matrix multiplication using the Divide and Conquer approach. Let’s break down the code step by step for clarity.

### 1. Split Function
```cpp
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
**Purpose:**
This function extracts a submatrix from the given matrix by specifying row and column ranges. It is used to divide the matrix into four quadrants.

**Example Input:**
For matrix A = {{1, 2}, {3, 4}}, calling `split(A, 0, 1, 0, 1)` returns {{1}}.

---

### 2. Brute-Force Matrix Multiplication
```cpp
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
**Purpose:**
This function performs traditional matrix multiplication by iterating through the rows of A and the columns of B.

**Example:**
For A = {{1, 2}, {3, 4}} and B = {{5, 6}, {7, 8}},
the result is {{19, 22}, {43, 50}}.

---

### 3. Addition Function
```cpp
vector<vector<int>> addition(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> result;
    for (int i = 0; i < a.size(); i++) {
        vector<int> row;
        for (int j = 0; j < a[0].size(); j++) {
            row.push_back(a[i][j] + b[i][j]);
        }
        result.push_back(row);
    }
    return result;
}
```
**Purpose:**
This function adds two matrices element by element.

**Example:**
For a = {{1, 2}, {3, 4}} and b = {{5, 6}, {7, 8}}, the result is {{6, 8}, {10, 12}}.

---

### 4. Merge Function
```cpp
vector<vector<int>> merge(vector<vector<int>> c11, vector<vector<int>> c12, vector<vector<int>> c21, vector<vector<int>> c22) {
    int n = c11.size();
    vector<vector<int>> Matrix1, Matrix2;

    // Combine the upper submatrices
    for (vector<int> row : c11) Matrix1.push_back(row);
    for (vector<int> row : c21) Matrix2.push_back(row);

    // Append the right submatrices to each row
    for (int i = 0; i < Matrix1.size(); i++) {
        for (int j = 0; j < n; j++) {
            Matrix1[i].push_back(c12[i][j]);
            Matrix2[i].push_back(c22[i][j]);
        }
    }

    // Combine upper and lower halves
    for (vector<int> a : Matrix2) Matrix1.push_back(a);

    return Matrix1;
}
```
**Purpose:**
This function merges four submatrices C11, C12, C21, and C22 into a single matrix.

---

### 5. Divide and Conquer Matrix Multiplication
```cpp
vector<vector<int>> matrixMultiplication(vector<vector<int>> A, vector<vector<int>> B) {
    int n_A = A.size();

    // Base case: Small matrix (2x2 or less)
    if (n_A <= 2) {
        return bruteForce(A, B);
    }

    // Divide matrices into quadrants
    vector<vector<int>> c11 = addition(
        matrixMultiplication(split(A, 0, n_A / 2, 0, n_A / 2), split(B, 0, n_A / 2, 0, n_A / 2)),
        matrixMultiplication(split(A, 0, n_A / 2, n_A / 2, n_A), split(B, n_A / 2, n_A, 0, n_A / 2))
    );

    vector<vector<int>> c12 = addition(
        matrixMultiplication(split(A, 0, n_A / 2, 0, n_A / 2), split(B, 0, n_A / 2, n_A / 2, n_A)),
        matrixMultiplication(split(A, 0, n_A / 2, n_A / 2, n_A), split(B, n_A / 2, n_A, n_A / 2, n_A))
    );

    vector<vector<int>> c21 = addition(
        matrixMultiplication(split(A, n_A / 2, n_A, 0, n_A / 2), split(B, 0, n_A / 2, 0, n_A / 2)),
        matrixMultiplication(split(A, n_A / 2, n_A, n_A / 2, n_A), split(B, n_A / 2, n_A, 0, n_A / 2))
    );

    vector<vector<int>> c22 = addition(
        matrixMultiplication(split(A, n_A / 2, n_A, 0, n_A / 2), split(B, 0, n_A / 2, n_A / 2, n_A)),
        matrixMultiplication(split(A, n_A / 2, n_A, n_A / 2, n_A), split(B, n_A / 2, n_A, n_A / 2, n_A))
    );

    // Merge results
    return merge(c11, c12, c21, c22);
}
```
**Purpose:**
This function recursively divides the matrices into quadrants, multiplies them, and combines the results.

**Key Steps:**
1. Split matrices A and B into four submatrices each.
2. Calculate submatrix products for each quadrant.
3. Add the corresponding products.
4. Merge the results into the final matrix.

---

### 6. Main Function
```cpp
int main() {
    vector<vector<int>> A = {{2, 4, 1, 7}, {5, 3, 6, 0}, {10, 9, 14, 4}, {3, 5, 1, 8}};
    vector<vector<int>> B = {{3, 1, 6, 9}, {10, 9, 4, 11}, {8, 17, 2, 0}, {-2, 5, 9, 4}};

    vector<vector<int>> result = matrixMultiplication(A, B);

    for (vector<int> row : result) {
        // Display the result
    }
}
```
This code executes the main logic of the matrix multiplication using the functions defined above. 

Feel free to add any display logic in the last loop to show the result!

### 🚀 Summary of the Approach
1. **Divide**: Split each matrix into four quadrants.
2. **Conquer**: Recursively multiply the submatrices.
3. **Combine**: Add the partial results and merge them.
4. **Base Case**: Use a brute-force method for small matrices (2x2 or smaller).

### 📊 Time Complexity Analysis
- **Brute-force**: \(O(n^3)\)
- **Divide and Conquer**: \(O(n^{2.81})\)

While this approach is faster than brute-force, it is not as optimized as Strassen's algorithm, which also has a complexity of \(O(n^{2.81})\).
