#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isSubsetSum(int set[], int n, int sum) {
   
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);
    return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

void displaySubset(int set[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

void subsetSumUtil(int set[], int target, int currSum, int index, int size, int subset[]) {
    if (currSum == target) {
        displaySubset(subset, index);
        return;
    }
    if (index == size || currSum > target)
        return;

    subset[index] = set[index];
    subsetSumUtil(set, target, currSum + set[index], index + 1, size, subset);

    subsetSumUtil(set, target, currSum, index + 1, size, subset);
}

void subsetSum(int set[], int size, int target) {
    int subset[MAX_SIZE];
    subsetSumUtil(set, target, 0, 0, size, subset);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int size = sizeof(set) / sizeof(set[0]);
    int target = 35;

    printf("Subsets with sum equal to %d are:\n", target);
    subsetSum(set, size, target);

    return 0;
}

