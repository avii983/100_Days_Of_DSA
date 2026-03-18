/*Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->value = data;
    newnode->next = NULL;
    return newnode;
}
void insertAtend(struct node **head, int data)
{
    struct node *newnode = createnode(data);
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void deletion(struct node **head, int key)
{
    struct node *temp = *head;
    while(temp->next->value != key || temp != NULL)
    {
       temp = temp->next;
    }
    temp->next = temp->next->next;
    return;
}
void printing(struct node *head){
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d" , temp->value);
        printf(" -> ");
        temp = temp->next;
    }
    printf("NULL");
    return;
}
int main()
{
    struct node *head = NULL;
    int n, node, key;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node);
        insertAtend(&head, node);
    }
    scanf("%d", &key);
    deletion(&head, key);
    printing(head);
    return 0;
}