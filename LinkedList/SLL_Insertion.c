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
struct node * insHead(struct node * head, int value)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = head;
    return newnode;
}
struct node * insTail(struct node * head, int value)
{
    struct node * temp = head;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    return head;
}
struct node *insKNode(struct node *head, int k, int value) {
    // Insert at head (position 1)
    if (k == 1) {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = head;
        return newnode;
    }

    struct node *temp = head;
    int count = 1;

    // Traverse to (k-1)th node
    while (temp != NULL && count < k - 1) {
        temp = temp->next;
        count++;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;

    if (temp == NULL) {
        // If k is greater than length → insert at end
        struct node *last = head;
        if (last == NULL) {
            // empty list case
            return newnode;
        }
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newnode;
        newnode->next = NULL;
    } else {
        // Normal insertion at position k
        newnode->next = temp->next;
        temp->next = newnode;
    }

    return head;
}
int main()
{
    int nodes;
    scanf("%d",&nodes);

    struct node * head = NULL, *temp = NULL, *newnode = NULL;
    for(int i = 0 ; i < nodes ; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode -> next = NULL;

        if(head == NULL)
        {
            temp = head = newnode;
        }
        else
        {
            temp -> next = newnode;
            temp = newnode;
        }
    }
    temp = insKNode(head,5,13);
    printLL(temp);
    return 0;
}