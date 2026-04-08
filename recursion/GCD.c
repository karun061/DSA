#include <stdio.h>

// Recursive function to find GCD
int gcd(int a, int b) {
    if (b == 0)       // Base case
        return a;
    else
        return gcd(b, a % b);  // Recursive call
}

int main() {
    int x, y;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    return 0;
}