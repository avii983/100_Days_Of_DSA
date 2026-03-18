/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.*/
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
void no_of_times(struct node **head , int times){
    struct node *temp = *head;
    int count = 0;
    while(temp != NULL)
    {
        if(temp->value == times)
        {
           count += 1;
        }
        temp = temp->next;
    }
    printf("The number of times of %d element occured is %d" , times , count);
    return;

}
int main()
{
    int n, node , occured;
    struct node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node);
        insertAtend(&head, node);
    }
    scanf("%d" , &occured);
    no_of_times(&head , occured);
    return 0;
}