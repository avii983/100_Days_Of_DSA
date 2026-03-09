/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node* next;
};
struct node* createnode(int data){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->value = data;
    newnode->next = NULL;
    return newnode;
}
void insertAtBeginning(struct node **head , int data){
    struct node* newnode = createnode(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    newnode->next = *head;
    (*head) = newnode;
}
void insertAtend(struct node **head , int data){
    struct node* newnode = createnode(data);
    if(*head == NULL)
    {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void printing(struct node *head){
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d " , temp->value);
        printf("-> ");
        temp = temp->next;
    }
    printf("NULL");
}
int main(){
    int n , node;
    scanf("%d" , &n);
    struct node* head = NULL;
    for(int i = 0; i < n; i++)
    {
        scanf("%d" , &node);
      insertAtend(&head , node);
    }
    printing(head);
    return 0;
     
}