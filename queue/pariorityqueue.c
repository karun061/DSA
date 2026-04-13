#include <stdio.h>

#define N 5

int queue[N];
int priority[N];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % N == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int x, int p) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
        queue[rear] = x;
        priority[rear] = p;
    } else {
        // Find the right position based on priority (Higher p value = Higher priority)
        int i = rear;
        rear = (rear + 1) % N;
        
        // Shift elements to keep the queue sorted by priority
        while (i != (front - 1 + N) % N && priority[i] < p) {
            queue[(i + 1) % N] = queue[i];
            priority[(i + 1) % N] = priority[i];
            i = (i - 1 + N) % N;
        }
        
        queue[(i + 1) % N] = x;
        priority[(i + 1) % N] = p;
    }
    printf("Inserted %d with priority %d\n", x, p);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("Deleted element is: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Deleted element is: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Highest priority element: %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue (Val|Prio): ");
        int i = front;
        while (i != rear) {
            printf("%d|%d  ", queue[i], priority[i]);
            i = (i + 1) % N;
        }
        printf("%d|%d\n", queue[rear], priority[rear]);
    }
}

int main() {
    enqueue(10, 1);
    enqueue(20, 3); // Higher priority than 10
    enqueue(30, 2);
    
    display(); 

    dequeue();
    display();

    peek();

    return 0;
}