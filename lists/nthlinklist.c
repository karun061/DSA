#include<stdio.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newnode = NULL;

    for(int i = 1; i <= 1000; i++)
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Traversal
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}