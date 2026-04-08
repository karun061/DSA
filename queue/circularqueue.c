#include<stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

int isFull()
{
    if ((rear + 1) % N == front)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int x)
{
    if (isFull())
    {
        printf("Queue is overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("Inserted number is %d\n", x);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else if (front == rear)
    {
        printf("Deleted element is: %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Deleted element is: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\t");

        int i = front;
        while (i != rear)
        {
            printf("%d\t", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    enqueue(60);
    enqueue(70);

    display();

    peek();

    return 0;
}