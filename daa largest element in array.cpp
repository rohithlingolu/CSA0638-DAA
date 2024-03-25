#include <stdio.h>
int findLargest(int arr[], int size);

int main() {
    int arr[100], size, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = findLargest(arr, size);
    printf("The largest element in the array is: %d\n", largest);

    return 0;
}
int findLargest(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

