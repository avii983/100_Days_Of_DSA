/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node *next;
    struct node *prev;
};
struct node *createnode(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->value = data;
    newnode->next = NULL;
    newnode->prev = NULL;
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
    return;
}
int main()
{
    struct node *head = NULL;
    int n, node;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node);
        insertAtend(&head, node);
    }
    printing(head);
}