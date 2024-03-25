#include <stdio.h>

struct Pair {
    int min;
    int max;
};
struct Pair findMinMax(int arr[], int left, int right) {
    struct Pair minMax, leftMinMax, rightMinMax;
    int mid;
    if (left == right) {
        minMax.min = arr[left];
        minMax.max = arr[right];
        return minMax;
    }
    if (right == left + 1) {
        if (arr[left] < arr[right]) {
            minMax.min = arr[left];
            minMax.max = arr[right];
        } else {
            minMax.min = arr[right];
            minMax.max = arr[left];
        }
        return minMax;
    }

    mid = (left + right) / 2;
    leftMinMax = findMinMax(arr, left, mid);
    rightMinMax = findMinMax(arr, mid + 1, right);

    if (leftMinMax.min < rightMinMax.min)
        minMax.min = leftMinMax.min;
    else
        minMax.min = rightMinMax.min;

    if (leftMinMax.max > rightMinMax.max)
        minMax.max = leftMinMax.max;
    else
        minMax.max = rightMinMax.max;

    return minMax;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Pair minMax = findMinMax(arr, 0, n - 1);

    printf("Minimum element in the array: %d\n", minMax.min);
    printf("Maximum element in the array: %d\n", minMax.max);

    return 0;
}

