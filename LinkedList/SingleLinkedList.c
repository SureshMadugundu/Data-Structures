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
    if(head == NULL)
    {
        return NULL;
    }
    struct node * temp = head -> next;
    //free(head); We should not do this
    return temp;
}
struct node * moveTail(struct node * head)
{
    struct node * temp = head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
    free(temp->next);
    return head;
}
struct node * removeKnode(struct node * head, int k)
{
    struct node * temp = head,*prev=NULL;
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
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = value;
    temp -> next = head;
    return temp;
}
struct node * insertTail(struct node * head, int value)
{
    struct node * temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = value;
    newnode -> next = NULL;
    temp -> next = newnode;
    return head;
}
struct node * insertPosition(struct node * head,int k, int value)
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
    while(temp != NULL)
    {
        count ++;
        if(count == k - 1)
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
struct node * insertBeforeELement(struct node * head,int element, int value)
{
    struct node * temp = head;
    if(head->data == element)
    {
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
        newnode -> data = value;
        newnode -> next = head;
        return newnode;
    }
    while(temp->next != NULL)
    {
        if(temp->next->data == element)
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
    struct node *head = NULL, *temp = NULL, *newnode,*temp2 = NULL;
    int nodes;
    scanf("%d",&nodes);

    for(int i = 0 ; i < nodes ; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode -> data);
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
    // temp = moveHead(head);
    // printLL(temp);
    // temp2 = moveTail(head);
    // printLL(temp2);
    // temp = removeKnode(head,1);
    //printLL(temp);
    temp = insertBeforeELement(head,4,100);
    printLL(temp);
  
}