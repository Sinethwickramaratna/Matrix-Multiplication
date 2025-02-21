# Brute force method
This C++ program performs matrix multiplication using 2D vectors. Let's break down the code step by step:

🔷 **1. Header and Namespace**

```cpp
#include <iostream>
#include <vector>
using namespace std;
```

- `#include <iostream>`: Includes the input-output stream library, allowing the use of `cout` and `cin`.
- `#include <vector>`: Includes the vector library to utilize dynamic arrays.
- `using namespace std;`: Simplifies the code by avoiding the need to use `std::` before functions like `cout` and `vector`.

🔷 **2. Matrix Multiplication Function**

```cpp
vector<vector<int>> matrixMultiplication(vector<vector<int>> A, vector<vector<int>> B)
```

This function takes two 2D vectors (A and B) representing matrices and returns their product as a 2D vector.

**Key Variables:**

```cpp
int row_a = A.size();          // Number of rows in matrix A
int column_a = A[0].size();    // Number of columns in matrix A (also rows in matrix B)
int column_b = B[0].size();    // Number of columns in matrix B
```

🔷 **3. Matrix Multiplication Logic**

```cpp
for (int i = 0; i < row_a; i++) {  // Iterate through rows of matrix A
    vector<int> row;               // Store each row of the result matrix
```

For each row of A and each column of B:
- Multiply corresponding elements.
- Sum the products.
- Store the result in the corresponding cell of the result matrix.

**Example of Cell Calculation:**

For the result cell C[i][j], the calculation is as follows:
\[ C[i][j] = \sum_{k=0}^{column_a} A[i][k] \times B[k][j] \]

**Code for this:**

```cpp
for (int j = 0; j < column_b; j++) { // Iterate through columns of matrix B
    int sum = 0;
    for (int k = 0; k < column_a; k++) { // Multiply row of A by column of B
        sum += A[i][k] * B[k][j];
    }
    row.push_back(sum);  // Add sum to the result row
}
```

🔷 **4. Main Function**

```cpp
int main(){
    vector<vector<int>> A = {{2, 4, 1}, {5, 3, 6}, {10, 9, 14}};
    vector<vector<int>> B = {{3, 1, 6}, {10, 9, 4}, {8, 17, 2}};
```
Matrix A is \(3 \times 3\), and matrix B is also \(3 \times 3\).

🔷 **5. Printing the Result**

```cpp
for (vector<int> row: matrixMultiplication(A, B)) {
    for (int n: row) {
        cout << n << " ";
    }
    cout << endl;
}
```

This nested loop prints each element of the resulting matrix.

🔷 **6. Example Calculation**

For example, the first cell C[0][0] is calculated as follows:
\[ C[0][0] = (2 \times 3) + (4 \times 10) + (1 \times 8) = 6 + 40 + 8 = 54 \]

🔷 **7. Program Output**

The output of the program is:
```
54 81 40
101 136 58
```

🔷 **8. Key Points**
- The number of columns in matrix A must equal the number of rows in matrix B for multiplication to occur.
- The dimensions of the resulting matrix will be (rows of A) x (columns of B).
