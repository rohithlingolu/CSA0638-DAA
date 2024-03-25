#include <stdio.h>

void stringCopy(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0';
        return;
    }
    *destination = *source;
    stringCopy(source + 1, destination + 1); 
}

int main() {
    char source[] = "Hello, World!";
    char destination[20]; 
    stringCopy(source, destination);
    printf("Copied string: %s\n", destination);

    return 0;
}

