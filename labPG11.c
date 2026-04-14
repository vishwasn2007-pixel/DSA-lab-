// Program to detect cycle in an undirected graph using DFS
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
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
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for(int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void add_edge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

int dfs_cycle(struct Graph* graph, int vertex, int parent) {
    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];
    while(temp) {
        int adjVertex = temp->vertex;

        if(graph->visited[adjVertex] == 0) {
            if(dfs_cycle(graph, adjVertex, vertex))
                return 1;
        } else if(adjVertex != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int detect_cycle(struct Graph* graph) {
    for(int i = 0; i < graph->numVertices; i++) {
        if(graph->visited[i] == 0) {
            if(dfs_cycle(graph, i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    struct Graph* graph = createGraph(5);

    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 1);

    if(detect_cycle(graph))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}