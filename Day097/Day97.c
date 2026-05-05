// Problem: Given meeting intervals, find minimum number of rooms required.
// Sort by start time and use min-heap on end times.
#include <stdio.h>
#include <stdlib.h>

struct Meeting {
    int start, end;
};

int compare(const void* a, const void* b) {
    return ((struct Meeting*)a)->start - ((struct Meeting*)b)->start;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int heap[], int i) {
    while (i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int l = 2*i+1, r = 2*i+2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    heapifyUp(heap, *size);
    (*size)++;
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    heapifyDown(heap, *size, 0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    qsort(meetings, n, sizeof(struct Meeting), compare);

    int heap[n];
    int size = 0;

    push(heap, &size, meetings[0].end);

    for (int i = 1; i < n; i++) {
        if (heap[0] <= meetings[i].start) {
            pop(heap, &size); 
        }

        push(heap, &size, meetings[i].end);
    }

    printf("%d", size);

    return 0;
}