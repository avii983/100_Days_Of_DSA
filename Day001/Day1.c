/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, position = 0, element = 0;
    scanf("%d", &n);
    printf("\n");
    int *arr = malloc(n * sizeof(int));
    int i = n, j = n - 1;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    scanf("%d", &position);
    printf("\n");
    scanf("%d", &element);
    while (j >= 0)
    {
        arr[i] = arr[j];

        if (j + 1 == position)
        {
            arr[j] = element;
            i -= 1;
        }
        j -= 1;
        i -= 1;
    }
    while (count < n)
    {
        printf("%d", arr[count]);
        printf(" ");
        count += 1;
    }
    return 0;
}