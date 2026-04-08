#include<stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

int isfull()
{
    if (rear == N - 1)
        return 1;
    else 
        return 0;
}

int isempty()
{
    if (front == -1 || front > rear)
        return 1;
    else 
        return 0;
}

void enqueue(int x)
{
    if (isfull())
    {
        printf("Queue is overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = x;
        printf("Inserted number is %d\n", x);
    }
}

void dequeue()
{
    if (isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element is: %d\n", queue[front]);
        front++;
    }
}

void peek()
{
    if (isempty())
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
    if (isempty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are:\t");
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(50);
    enqueue(70);

    display();

    dequeue();
    peek();

    return 0;
}