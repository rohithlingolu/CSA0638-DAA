#include <stdio.h>

int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10; 
        number /= 10;       
    }

    return sum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Sum of digits: %d\n", sumOfDigits(num));

    return 0;
}

