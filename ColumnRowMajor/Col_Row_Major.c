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
    
    // Example matrix
    int matrix1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; 

    // Random access in row-major order
    printf("Random access in row-major order:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Using row-major formula to access elements randomly
            printf("Element at [%d][%d] = %d, Address = %p\n", i, j, matrix1[i][j], &matrix1[i][j]);
        }
    }

    printf("\n");

    // Random access in column-major order (by swapping loops)
    printf("Random access in column-major order:\n");
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            // Using column-major logic to access elements randomly
            printf("Element at [%d][%d] = %d, Address = %p\n", i, j, matrix1[i][j], &matrix1[i][j]);
        }
    }
    
    
    return 0;
}



