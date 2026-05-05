// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];

int queue[MAX];
int front = 0, rear = -1;

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

    indegree[v]++;
}

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];

        while (temp != NULL) {
            int neighbor = temp->vertex;

            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                enqueue(neighbor);
            }

            temp = temp->next;
        }
    }

    if (count != n) {
        printf("\nCycle detected! Topological sort not possible");
    }

    return 0;
}