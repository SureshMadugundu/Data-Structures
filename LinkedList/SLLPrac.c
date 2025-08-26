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
        temp = temp->next;
    }
    printf("NULL\n");
}
struct node * moveHead(struct node * head)
{
    struct node * temp = head;
    temp = head -> next;
    free(head);
    return temp;
}
struct node * moveTail(struct node * head)
{
    struct node * temp = head;
    while(temp-> next -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
    free(temp -> next);
    return head;
}
struct node * removekNode(struct node * head, int k)
{
    struct node * prev = NULL;
    struct node * temp = head;
    int count = 0;
    if(k == 1)
    {
        temp = head -> next;
        free(head);
        return temp;
    }
    while(temp != NULL)
    {
        count ++;
        if(count == k)
        {
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
struct node * insertHead(struct node * head, int value)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = head;
    return newnode;
}
struct node * insertTail(struct node * head, int value)
{
    struct node * temp = head;
    while(temp->next != NULL)
    {
        temp = temp -> next;
    }
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;
    temp -> next = newnode;
    return head;
}
struct node * insertatK(struct node * head, int k, int value)
{
    struct node * temp = head;
    int count = 0;
    if(k == 1)
    {
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = value;
        newnode -> next = head;
        return newnode;
    }
    while(temp -> next != NULL)
    {
        count ++;
        if(count == k- 1)
        {
            struct node * newnode = (struct node *)malloc(sizeof(struct node));
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
    struct node * head = NULL, * temp = NULL, * newnode;
    int nodes;
    scanf("%d",&nodes);
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
    temp = insertatK(head,3,100);
    printLL(temp);
    return 0;
}