#include <stdio.h>

int main() {
    int rows = 3, cols = 3; // Define the number of rows and columns
    int matrix[3][3]; // Declare a 3x3 matrix
    
    // Input the matrix elements in row-major order
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Display the matrix in row-major order
    printf("\nMatrix in row-major order:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // Move to the next line after printing a row
    }

    // Display the matrix in column-major order
    printf("\nMatrix in column-major order:\n");
    for (int j = 0; j < cols; j++) {     // Iterate through columns first
        for (int i = 0; i < rows; i++) { // Then iterate through rows
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // Newline after printing one column's values
    }


    
    return 0;
}



