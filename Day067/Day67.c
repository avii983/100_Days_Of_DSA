// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            dfs(neighbor);
        }

        temp = temp->next;
    }

    push(v);

int main() {
    int n, m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}