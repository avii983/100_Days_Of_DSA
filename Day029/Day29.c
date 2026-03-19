/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
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

void cycling(struct node **head)
{
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *head;
}

void Rotation(struct node **head, int data)
{
    struct node *temp = *head;
    int count = 1;
    int check = 1;
    while (count < data)
    {
        temp = temp->next;
        count += 1;
    }
    if (check <= data)
    {
        *head = temp->next;
        temp->next = NULL;
    }
    else
    {
        while (temp->next->value != (*head)->value)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void printing(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->value);
        printf(" -> ");
        temp = temp->next;
    }
    printf("NULL");
}
int main()
{
    struct node *head = NULL;
    int n, node;
    int node1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node);
        insertAtend(&head, node);
    }
    cycling(&head);
    scanf("%d", &node1);
    Rotation(&head, abs(n - node1));
    printing(head);
}