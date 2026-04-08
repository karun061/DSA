#include<stdio.h>

#define N 5

int stack[N];
int top = -1;

int isfull()
{
    if (top == N-1)
        return 1;
    else 
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int x)
{
    if (isfull())
    {
        printf("Overflow condition\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

void pop()
{
    int y;

    if (isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        y = stack[top];
        top--;
        printf("Pop element: %d\n", y);
    }
}

void peek()
{
    if (isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Peek element: %d\n", stack[top]);
    }
}

void display()
{
    if (isempty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    push(5);
    push(10);
    push(11);

    display();

    pop();
    peek();

    return 0;
}