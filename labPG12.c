// Program to find degrees of separation using BFS in a social network
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for(int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void add_friendship(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int degrees_of_separation(struct Graph* graph, int start, int end) {
    int visited[100] = {0};
    int distance[100] = {0};
    int queue[100];

    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while(front < rear) {
        int current = queue[front++];

        struct Node* temp = graph->adjLists[current];

        while(temp) {
            int adj = temp->vertex;

            if(!visited[adj]) {
                visited[adj] = 1;
                distance[adj] = distance[current] + 1;
                queue[rear++] = adj;

                if(adj == end)
                    return distance[adj];
            }

            temp = temp->next;
        }
    }

    return -1;
}

int main() {
    struct Graph* graph = createGraph(6);

    add_friendship(graph, 0, 1);
    add_friendship(graph, 0, 2);
    add_friendship(graph, 1, 3);
    add_friendship(graph, 2, 4);
    add_friendship(graph, 3, 5);

    int result = degrees_of_separation(graph, 0, 5);

    if(result != -1)
        printf("Degrees of separation: %d\n", result);
    else
        printf("No connection\n");

    return 0;
}