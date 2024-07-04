#include <stdio.h>
#include <stdlib.h>

// Function prototype for matrix multiplication
int** multiplyMatrices(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB);

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter dimensions of the first matrix (rows x columns): ");
    scanf("%d %d", &rowsA, &colsA);
    printf("Enter dimensions of the second matrix (rows x columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrices are not compatible for multiplication.\n");
        return 0;
    }

    // Allocate memory for matrices A and B
    int** A = malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA; ++i)
        A[i] = malloc(colsA * sizeof(int));

    int** B = malloc(rowsB * sizeof(int*));
    for (int i = 0; i < rowsB; ++i)
        B[i] = malloc(colsB * sizeof(int));

    // Input elements of matrices A and B
    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Multiply matrices
    int** C = multiplyMatrices(A, rowsA, colsA, B, rowsB, colsB);

    // Display the result
    printf("\nResultant matrix:\n");
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < rowsA; ++i) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}

// Function definition for matrix multiplication
int** multiplyMatrices(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB) {
    int** C = malloc(rowsA * sizeof(int*));
    for (int i = 0; i < rowsA; ++i)
        C[i] = malloc(colsB * sizeof(int));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
