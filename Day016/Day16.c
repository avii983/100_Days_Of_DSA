/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
struct node
{
    int value;
    int frequency;
    int check;
    struct node *next;
};

struct node *arr[SIZE];

int hashing(int n)
{
    return abs(n) % SIZE;
}

void inserting(int n)
{
    int index = hashing(n);
    struct node *temp = arr[index];
    while (temp != NULL)
    {
        if (temp->value == n)
        {
            temp->frequency += 1;
            temp->check += 1;
            return;
        }
        temp = temp->next;
    }
    struct node *newnode = malloc(sizeof(struct node));
    newnode->value = n;
    newnode->frequency = 1;
    newnode->check = 1;
    newnode->next = arr[index];
    arr[index] = newnode;
}

int printing(int n)
{
    int index = hashing(n);
    struct node *temp = arr[index];
    while (temp != NULL)
    {
        if (temp->value == n && temp->check > 0)
        {
            printf("%d:%d ", temp->value, temp->frequency);
            temp->check = 0;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int *arr1 = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        inserting(arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printing(arr1[i]);
    }
}