#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;   // Base case
    else if (n == 1)
        return 1;   // Base case
    else
        return fibonacci(n-1) + fibonacci(n-2); // Recursive call
}

int main() {
    int n, i;
    printf("Enter how many Fibonacci numbers to print: ");
    scanf("%d", &n);

    printf("Fibonacci series: ");
    for(i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}