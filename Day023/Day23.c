/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
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
    newnode->merg_next = NULL;
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
    temp->merg_next = newnode;
}
struct node *merge(struct node **head, struct node **head1)
{
    struct node *head3 = NULL;
    struct node *temp = *head;
    struct node *temp1 = *head1;

    if (temp1->value < temp->value)
    {
        head3 = temp1;
        temp1 = temp1->next;
    }
    else
    {
        head3 = temp;
        temp = temp->next;
    }

    struct node *temp3 = head3;
    while (temp != NULL && temp1 != NULL)
    {
        if (temp1->value < temp->value)
        {
            temp3->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp3->next = temp;
            temp = temp->next;
        }
        temp3 = temp3->next;
    }
    while (temp != NULL)
    {
        temp3->next = temp;
        temp = temp->next;
        temp3 = temp3->next;
    }
    while (temp1 != NULL)
    {
        temp3->next = temp1;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }
    return head3;
}
int main()
{
    int n, node;
    int n1, node1;
    struct node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node);
        insertAtend(&head, node);
    }
    struct node *head1 = NULL;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &node1);
        insertAtend(&head1, node1);
    }
    if (head1 != NULL && head != NULL)
    {
        struct node *head3 = merge(&head, &head1);
        struct node *temp3 = head3;
        while (temp3 != NULL)
        {
            printf("%d", temp3->value);
            printf(" -> ");
            temp3 = temp3->next;
        }
        printf("NULL");
    }
    return 0;
}
