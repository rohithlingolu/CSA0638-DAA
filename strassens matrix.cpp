#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen's algorithm
void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Divide matrices A and B into submatrices
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // P1 = (A11 + A22)*(B11 + B22)
    add(newSize, A11, A22, temp1);
    add(newSize, B11, B22, temp2);
    strassen(newSize, temp1, temp2, C11);

    // P2 = (A21 + A22)*B11
    add(newSize, A21, A22, temp1);
    strassen(newSize, temp1, B11, C12);

    // P3 = A11*(B12 - B22)
    subtract(newSize, B12, B22, temp1);
    strassen(newSize, A11, temp1, C21);

    // P4 = A22*(B21 - B11)
    subtract(newSize, B21, B11, temp1);
    strassen(newSize, A22, temp1, C22);

    // P5 = (A11 + A12)*B22
    add(newSize, A11, A12, temp1);
    strassen(newSize, temp1, B22, temp2);

    // P6 = (A21 - A11)*(B11 + B12)
    subtract(newSize, A21, A11, temp1);
    add(newSize, B11, B12, temp2);
    strassen(newSize, temp1, temp2, temp1);

    // P7 = (A12 - A22)*(B21 + B22)
    subtract(newSize, A12, A22, temp1);
    add(newSize, B21, B22, temp2);
    strassen(newSize, temp1, temp2, temp2);

    // C11 = P1 + P4 - P5 + P7
    add(newSize, C11, C22, temp1);
    subtract(newSize, temp1, temp2, temp1);
    add(newSize, temp1, C12, C11);

    // C12 = P3 + P5
    add(newSize, C21, C22, C12);

    // C21 = P2 + P4
    add(newSize, C11, C12, C21);

    // C22 = P1 - P2 + P3 + P6
    subtract(newSize, C11, C21, temp1);
    add(newSize, temp1, C12, C22);

    // Combine submatrices into result matrix C
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of matrices (must be a power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(n, A, B, C);

    printf("Resultant matrix C:\n");
    printMatrix(n, C);

    return 0;
}

