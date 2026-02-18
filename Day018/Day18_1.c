/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr, int first, int last)
{

    while (first < last)
    {
         int temp = arr[first];
        arr[first] = arr[last];
        arr[last] = temp;
        first += 1;
        last -= 1;
    }
}
int main()
{
    int n, k;
    scanf("%d", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    k = k % n;
    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}