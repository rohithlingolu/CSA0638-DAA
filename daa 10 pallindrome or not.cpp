#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isPalindrome(char *str, int start, int end);

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str, 0, strlen(str) - 1))
        printf("The string '%s' is a palindrome.\n", str);
    else
        printf("The string '%s' is not a palindrome.\n", str);

    return 0;
}
bool isPalindrome(char *str, int start, int end) {
    if (start >= end)
        return true;
    if (str[start] == str[end])
        return isPalindrome(str, start + 1, end - 1);
    return false;
}

