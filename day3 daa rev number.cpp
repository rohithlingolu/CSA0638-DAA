#include <stdio.h>
int reverseNumber(int num, int rev) {
    if (num == 0)
        return rev;
    int digit = num % 10;
    rev = rev * 10 + digit;
    return reverseNumber(num / 10, rev);
}
int main() {
    int num, reversedNum;
    printf("Enter a number: ");
    scanf("%d", &num);
    reversedNum = reverseNumber(num, 0);
    
    printf("Reverse of the number: %d\n", reversedNum);
    return 0;
}

