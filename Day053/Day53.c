/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Build tree from level-order array (-1 = NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = (arr[i] == -1) ? NULL : createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1, r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

#define QMAX 1000
struct Node* qNode[QMAX];
int qHD[QMAX];
int front = 0, rear = -1;

void enqueue(struct Node* node, int hd) {
    qNode[++rear] = node;
    qHD[rear] = hd;
}

int isEmptyQ() {
    return front > rear;
}

void dequeue(struct Node** node, int* hd) {
    *node = qNode[front];
    *hd = qHD[front];
    front++;
}

#define MAXN 1000

int cols[2*MAXN][MAXN]; 
int colSize[2*MAXN];

void verticalOrder(struct Node* root) {
    if (!root) return;

    // reset
    for (int i = 0; i < 2*MAXN; i++) colSize[i] = 0;
    front = 0; rear = -1;

    int offset = MAXN; 

    enqueue(root, 0);

    int minHD = 0, maxHD = 0;

    while (!isEmptyQ()) {
        struct Node* cur;
        int hd;
        dequeue(&cur, &hd);

        int idx = hd + offset;
        cols[idx][colSize[idx]++] = cur->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (cur->left)  enqueue(cur->left,  hd - 1);
        if (cur->right) enqueue(cur->right, hd + 1);
    }

    for (int hd = minHD; hd <= maxHD; hd++) {
        int idx = hd + offset;
        for (int i = 0; i < colSize[idx]; i++) {
            printf("%d ", cols[idx][i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}