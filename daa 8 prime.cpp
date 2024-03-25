#include <stdio.h>
int isPrime(int num, int divisor);

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num <= 1) {
        printf("Invalid input. Please enter a positive integer greater than 1.\n");
        return 1;
    }

    if (isPrime(num, 2))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}
int isPrime(int num, int divisor) {
    if (divisor == num) {
        return 1; 
    } else if (num % divisor == 0) {
        return 0; 
    } else {
        return isPrime(num, divisor + 1); 
    }
}

