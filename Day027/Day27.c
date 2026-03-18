/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
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
void intersection(struct node *head, struct node *head1, int n, int n1)
{
    struct node *temp = head;
    struct node *temp1 = head1;
    int count = abs(n - n1);
    if (n > n1)
    {
        for (int i = 0; i < count; i++)
        {
            temp = temp->next;
        }
    }
    if (n < n1)
    {
        for (int i = 0; i < count; i++)
        {
            temp1 = temp1->next;
        }
    }
    while (temp != NULL && temp1 != NULL)
    {
        if (temp->value == temp1->value)
        {
            printf("Yes Intersection is there at element %d", temp->value);
            return;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    printf("No intersection found");
}
int main()
{
    int n, node;
    int n1, node1;
    scanf("%d", &n);
    struct node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node);
        insertAtend(&head, node);
    }
    scanf("%d", &n1);
    struct node *head1 = NULL;
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &node1);
        insertAtend(&head1, node1);
    }
    intersection(head, head1, n, n1);
}