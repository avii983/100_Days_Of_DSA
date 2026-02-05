/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m;
    scanf("%d", &n);

    int *nums1 = malloc(n * sizeof(int));
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums1[i]);
    }
    printf("\n");
    scanf("%d", &m);

    printf("\n");
    int *nums2 = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &nums2[i]);
    }
    int i = 0, j = 0;
    int limit = 0;

    int *arr2 = malloc((n + m) * sizeof(int));
    while (limit < (m + n))
    {
        if (i < n && j < m)
        {
            if (nums1[i] < nums2[j])
            {
                arr2[limit] = nums1[i];
                i += 1;
                limit += 1;
            }
            else if (nums1[i] > nums2[j])
            {
                arr2[limit] = nums2[j];
                limit += 1;
                j += 1;
            }
            else
            {
                arr2[limit] = nums1[i];
                i += 1;
                limit += 1;
                arr2[limit] = nums2[j];
                j += 1;
                limit += 1;
            }
        }
        else if (i >= n && j < m)
        {
            arr2[limit] = nums2[j];
            j += 1;
            limit += 1;
        }
        else
        {
            arr2[limit] = nums1[i];
            i += 1;
            limit += 1;
        }
    }
    printf("\n");
    for (int i = 0; i < limit; i++)
    {
        printf("%d", arr2[i]);
        printf(" ");
    }
    return 0;
}