#include <stdio.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

void containerLoader(int items[], int numItems, int containerCapacity) {
    int containers[MAX_CONTAINERS][MAX_ITEMS] = {0};
    int containerLoad[MAX_CONTAINERS] = {0};
    int numContainers = 0;
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = 0; j < numItems - i - 1; j++) {
            if (items[j] < items[j + 1]) {
                int temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < numItems; i++) {
        int j;
        for (j = 0; j < numContainers; j++) {
            if (containerLoad[j] + items[i] <= containerCapacity) {
                containers[j][containerLoad[j]] = items[i];
                containerLoad[j] += items[i];
                break;
            }
        }
        if (j == numContainers) {
            containers[numContainers][containerLoad[numContainers]] = items[i];
            containerLoad[numContainers] += items[i];
            numContainers++;
        }
    }
    printf("Optimized Container Loading:\n");
    for (int i = 0; i < numContainers; i++) {
        printf("Container %d: ", i + 1);
        for (int j = 0; j < containerLoad[i]; j++) {
            printf("%d ", containers[i][j]);
        }
        printf("\n");
    }
    printf("Total number of containers used: %d\n", numContainers);
}

int main() {
    int items[] = {4, 8, 6, 3, 5, 7}; 
    int numItems = sizeof(items) / sizeof(items[0]);
    int containerCapacity = 10;
    containerLoader(items, numItems, containerCapacity);

    return 0;
}

