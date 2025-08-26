#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void printLL(struct node * head)
{
    struct node * temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

struct node * insertAtBegining(struct node * head, int value)
{
    printf("Inserting a node at the begining of SLL\n");
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = head;
    return newnode;
}
struct node * insertAtEnding(struct node * head, int value)
{
    printf("Inserting a node at the end of SLL\n");
    struct node * temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    temp -> next = newnode;
    newnode -> data = value;
    newnode -> next = NULL;

    return head;
}
struct node * insertAtPosition(struct node * head, int position, int value)
{
    struct node * temp = head;
    int count = 1;
    if(position == 1)
    {
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = value;
        newnode -> next = head;
        return newnode;
    }
    while(temp -> next != NULL)
    {
        count ++;
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        if(count == position - 1)
        {
            newnode -> data = value;
            newnode -> next = temp -> next;
            temp -> next = newnode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}
int main()
{
    struct node * head = NULL, *temp = NULL, * newnode;
    int nodes;
    scanf("%d",&nodes);

    for(int i = 0 ; i < nodes ; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode -> next = NULL;

        if(head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
    }
    printLL(head);
    struct node * pointer = insertAtPosition(head,5,100);
    printLL(pointer);
    return 0;
}