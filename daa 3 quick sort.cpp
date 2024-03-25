#include <stdio.h>
int partition(int array[], int low, int high) {
    int pivot = array[high]; 
    int i = (low - 1); 
    
    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            i++; 
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
int main() {
    int array[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    
    printf("Original array: \n");
    printArray(array, n);
    
    quickSort(array, 0, n - 1);
    
    printf("Sorted array: \n");
    printArray(array, n);
    
    return 0;
}

