// Problem: Given intervals, merge all overlapping ones.
// Sort first, then compare with previous.
#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start, end;
};

int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    struct Interval result[n];
    int k = 0;

    result[k++] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[k - 1].end) {
            if (arr[i].end > result[k - 1].end)
                result[k - 1].end = arr[i].end;
        } else {
            result[k++] = arr[i];
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}