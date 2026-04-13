#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;

    struct node *node1 = malloc(sizeof(struct node));
    node1->data = 20;

    struct node *node2 = malloc(sizeof(struct node));
    node2->data = 30;

    struct node *node3 = malloc(sizeof(struct node));
    node3->data = 40;

    // Linking nodes
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // Traversing and printing
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}