# Matrix-Multiplication

The Brute Force Method and the Strassen Method are two different approaches to matrix multiplication, each with distinct algorithms, complexities, and use cases.

### 1. Brute Force Method (Conventional Method)

**Explanation:**  
This is the traditional way of multiplying two matrices. For each cell (i,j) in the result matrix C, you calculate the sum of products from the corresponding row of matrix A and the corresponding column of matrix B.

**Formula:**  
C[i][j] = ∑(k=0 to n-1) A[i][k] × B[k][j]

**Steps:**  
1. Take the i-th row of matrix A.  
2. Take the j-th column of matrix B.  
3. Multiply the corresponding elements and sum them up.  
4. Store the result in C[i][j].

**Time Complexity:**  
O(n³), where n is the size of the matrix (assuming square matrices of size n × n).

**Advantages:**  
- Simple to implement.  
- Works for any matrix size.

**Disadvantages:**  
- Slow for large matrices due to cubic complexity.  
- Not efficient for high-performance computing.

---

### 2. Strassen Method

**Explanation:**  
The Strassen algorithm is a divide-and-conquer approach proposed by Volker Strassen in 1969. It reduces the number of multiplications by splitting the matrices into submatrices.

**Steps:**  
1. Divide each matrix into four equal submatrices.  
2. Calculate 7 intermediate matrices (M₁, M₂, …, M₇) using specific formulas.  
3. Combine these intermediate results to form the final matrix.

**Time Complexity:**  
O(n².81), which is faster than the brute force method.

**Advantages:**  
- Faster than the brute force method for large matrices.  
- Reduces the number of multiplications from 8 to 7 per recursion step.

**Disadvantages:**  
- More complex to implement.  
- Increased memory usage due to the need for intermediate matrices.  
- Less efficient for small matrices due to overhead.

---

### 3. Comparison Summary

| Feature                  | Brute Force Method | Strassen Method    |
|--------------------------|---------------------|---------------------|
| Approach                 | Iterative (triple loop) | Divide-and-Conquer  |
| Time Complexity          | O(n³)               | O(n².81)            |
| Space Complexity         | O(1)                | O(n²) (due to recursion) |
| Multiplications          | n³                  | 7 per recursion step |
| Efficiency               | Efficient for small matrices | Efficient for large matrices |
| Implementation           | Simple              | Complex             |

### When to Use:
- **Brute Force:** For small matrices where simplicity is more important than speed.  
- **Strassen:** For large matrices where performance is crucial, especially in scientific computing.
