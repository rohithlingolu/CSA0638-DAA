#include <stdio.h>
unsigned long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
unsigned long long binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}
void printPascalTriangle(int rows) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j <= i; j++) {
            printf("%llu ", binomialCoefficient(i, j));
        }

        printf("\n");
    }
}

int main() {
    int rows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &rows);

    printPascalTriangle(rows);

    return 0;
}

