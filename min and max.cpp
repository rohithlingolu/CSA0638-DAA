#include <stdio.h>
#include <limits.h>

int main() {
    int num_list[] = {3, 5, -7, 10, 2, 8};
    int num_elements = sizeof(num_list) / sizeof(num_list[0]);

    int min_value = INT_MAX;
    int max_value = INT_MIN;
    for (int i = 0; i < num_elements; i++) {
        if (num_list[i] < min_value)
            min_value = num_list[i];
        if (num_list[i] > max_value)
            max_value = num_list[i];
    }

    printf("Minimum value: %d\n", min_value);
    printf("Maximum value: %d\n", max_value);

    return 0;
}

