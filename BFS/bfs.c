#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// struct node to represent a node in adjacency list.
struct Node {
    int data;
    struct Node* next;
};

// Create a node
struct Node* createNode(int data) {
    
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode-> next = NULL;
    
    return newNode;
}

// function to add an edge to the graph
void addEdge(struct Node* adj[], int u, int v) {
    
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    //undirected graph
    newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

//function to perform bfs
void bfs(struct Node* adj[], int v, int s, int visited[]) {

    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[s] = 1; // source is marked as visited.
    queue[rear++] = s; //enqueue
    
    while(front != rear) {
        int curr = queue[front++];
        printf("%d ", curr);
    
        //Get all adjacent vertices of curr
        struct Node* temp = adj[curr];
        while(temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1; // Mark as visited
                queue[rear++] = neighbor; // enqueue
            }
            temp = temp->next;
        }
    }   
}

//Perform bfs for the entire graph
void bfsDisconnected(struct Node* adj[], int v) {

    // Mark all nodes as not visited.
    int visited[v];
    for (int i = 0; i < v; ++i) {
        visited[i] = 0;
    }

    for (int i = 0; i < v; ++i) {
        if(!visited[i]) { // i.e. 0
            bfs(adj, v, i, visited);
        }
    }
}

int main() {
    int v = 6; // vertices
    struct Node* adj[v];
    
    for (int i = 0; i < v; ++i) {
        adj[i] = NULL; // init adjancency list
    }

    //add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    
    // bfs transversal for the entire graph
    bfsDisconnected(adj, v);
    return 0;
}

    
