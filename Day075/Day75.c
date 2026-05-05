/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/
#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0, maxLen = 0;

    int hash[20001];
    for (int i = 0; i < 20001; i++)
        hash[i] = -2;

    int offset = 10000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + offset] == -2) {
            hash[sum + offset] = i;
        } else {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        }
    }

    printf("%d", maxLen);

    return 0;
}