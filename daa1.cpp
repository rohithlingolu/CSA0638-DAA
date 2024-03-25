#include <stdio.h>
void bubbleSort(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void printArray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
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
    
    bubbleSort(array, n);
    
    printf("Sorted array: \n");
    printArray(array, n);
    
    return 0;
}

