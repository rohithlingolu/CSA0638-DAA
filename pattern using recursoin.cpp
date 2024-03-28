#include <stdio.h>

void printPattern(int n, int row, int col) {
    if (row > n)
        return;
    if (col <= row) {
        printf("%d ", col);
        printPattern(n, row, col + 1);
    } else {
        printf("\n");
        printPattern(n, row + 1, 1);
    }
}

int main() {
    int n = 4; 
    printPattern(n, 1, 1);
    return 0;
}

