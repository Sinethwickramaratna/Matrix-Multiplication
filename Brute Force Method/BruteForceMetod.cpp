#include <iostream>
#include <vector>
using namespace std;

// Function to perform matrix multiplication
vector <vector <int>> matrixMultiplication(vector <vector <int>> A, vector <vector <int>> B){
    int row_a = A.size();          // Number of rows in matrix A
    int column_a = A[0].size();    // Number of columns in matrix A (also rows in matrix B)
    int column_b = B[0].size();    // Number of columns in matrix B
    vector <vector <int>> resultMatrix;  // Resultant matrix to store the multiplication result

    // Iterate through each row of matrix A
    for (int i = 0; i < row_a; i++){
        vector <int> row;  // Temporary vector to store the current row of the result matrix
        
        // Iterate through each column of matrix B
        for (int j = 0; j < column_b; j++){
            int sum = 0;  // Variable to accumulate the sum for the current cell
            
            // Multiply corresponding elements from the current row of A and column of B
            for (int k = 0; k < column_a; k++){
                sum += A[i][k] * B[k][j];
            }
            
            row.push_back(sum);  // Store the calculated sum in the current row of the result matrix
        }

        resultMatrix.push_back(row);  // Add the completed row to the result matrix
    }

    return resultMatrix;  // Return the final result matrix
}

int main(){
    // Define two matrices A and B for multiplication
    vector <vector <int>> A = {{2, 4, 1}, {5, 3, 6}, {10, 9, 14}};
    vector <vector <int>> B = {{3, 1, 6}, {10, 9, 4}, {8, 17, 2}};

    // Perform matrix multiplication and print the result
    for (vector <int> row: matrixMultiplication(A, B)){
        for (int n: row){
            cout << n << " ";  // Print each element of the result matrix
        }
        cout << endl;  // Move to the next line after printing each row
    }

    return 0;  // Indicate successful program execution
}
