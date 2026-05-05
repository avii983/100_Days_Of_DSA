/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include <stdio.h>

int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currTime + arr[i] > maxTime) {
            painters++;
            currTime = arr[i];

            if (painters > k)
                return 0;
        } else {
            currTime += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal;
    int high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;    
    }

    printf("%d", ans);

    return 0;
}