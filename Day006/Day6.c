/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d" , &n);
    int* arr = malloc(n * sizeof(n));
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d" , &arr[i]);
    }
    int b = 0, check_duplicate = 0;
    printf("\n");
    printf("%d" , arr[b]);
    printf(" ");
    check_duplicate = arr[b];
    while(b < n)
    {
       if(arr[b] != check_duplicate)
       {
         printf("%d" , arr[b]);
         printf(" ");
         check_duplicate = arr[b];
       }
       b += 1;
    }
    return 0;
}
