#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void TOH(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    // Step 1: Move n-1 disks from source to auxiliary
    TOH(n-1, source, destination, auxiliary);
    
    // Step 2: Move nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Step 3: Move n-1 disks from auxiliary to destination
    TOH(n-1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("The sequence of moves are:\n");
    TOH(n, 'A', 'B', 'C'); // A=source, B=auxiliary, C=destination
    return 0;
} 