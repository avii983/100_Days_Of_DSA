/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int element = 0;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    element = arr[0];

    for (int j = 0; j < n; j++)
    {
        if (element < arr[j])
        {
            element = arr[j];
        }
    }

    printf("\nMax: %d\n", element);

    element = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (element > arr[i])
        {
            element = arr[i];
        }
    }
    printf("Min: %d\n", element);
    free(arr);
    return 0;
}
