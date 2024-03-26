#include <stdio.h>
void printMinMaxSequences(int arr[], int n) {
    int minSeq[n], maxSeq[n];
    int minVal = arr[0];
    int maxVal = arr[0];
    minSeq[0] = arr[0];
    maxSeq[0] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minSeq[i] = arr[i];
        } else {
            minSeq[i] = minVal;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxSeq[i] = arr[i];
        } else {
            maxSeq[i] = maxVal;
        }
    }
    printf("Minimum value sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", minSeq[i]);
    }
    printf("\n");
    printf("Maximum value sequence:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", maxSeq[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3, 1, 4, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printMinMaxSequences(arr, n);
    
    return 0;
}

