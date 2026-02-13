/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int (*arr)[m] = malloc(sizeof(int) * n * m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int first = 0 , last = n - 1;
    int left = 0 , right = m - 1;
    int count = 0;
    while (count < m * n)
    {
        for(int i = left; i <= right && count < (m * n); i++)
        {
            printf("%d " , arr[first][i]);
            count += 1;
        }
        first += 1;
        for(int i = first; i <= last && count < (m * n); i++)
        {
            printf("%d " , arr[i][right]);
            count += 1;
        }
        right -= 1;
        for(int i = right; i >= left && count < (m * n); i--)
        {
            printf("%d " , arr[last][i]);
            count += 1;
        }
        last -= 1;
        for(int i = last; i >= first && i < (m * n); i--)
        {
            printf("%d " , arr[i][left]);
            count += 1;
        }
        left += 1;
    }
    free(arr);
    return 0;
}