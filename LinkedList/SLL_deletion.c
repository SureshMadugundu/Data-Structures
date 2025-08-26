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
struct node * deleteAtBeginning(struct node * head)
{
    if(head == NULL) return NULL;
    struct node * temp = head -> next;
    free(head);
    return temp;
}
struct node * deleteAtEndining(struct node * head)
{
    if(head == NULL) return NULL;
    struct node * temp = head;if(head == NULL) return NULL;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
    free(temp -> next);
    return head;
}
struct node * deleteAtPosition(struct node * head, int position)
{
    struct node * temp = head;
    struct node * prev = NULL;
    int count = 0;
    if(position == 1)
    {
        temp = head -> next;
        free(head);
        return temp;
    }
    while(temp != NULL)
    {
        count ++;
        if(count == position)
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
int main()
{
    int nodes;
    scanf("%d",&nodes);
    
    struct node * head = NULL, *temp = NULL, *newnode = NULL;
    for(int i = 0 ; i < nodes ; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
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
    temp = deleteAtPosition(head,3);
    printLL(temp);
    return 0;
}