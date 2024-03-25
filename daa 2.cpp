#include <stdio.h>

// Function to perform selection sort
void selectionSort(int array[], int n) {
    int i, j, min_index, temp;
    // Traverse through the entire array
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (array[j] < array[min_index])
                min_index = j;
        }
        // Swap the found minimum element with the first element
        temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

// Function to print an array
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Main function
int main() {
    int array[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    printf("Original array: \n");
    printArray(array, n);
    
    selectionSort(array, n);
    
    printf("Sorted array: \n");
    printArray(array, n);
    
    return 0;
}

