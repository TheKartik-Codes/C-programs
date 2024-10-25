#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph
typedef struct {
    int numVertices;
    int **adjMatrix;
} Graph;

// Function to create a graph with given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjMatrix = (int**) malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*) malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    if (src >= 0 && src < graph->numVertices && dest >= 0 && dest < graph->numVertices) {
        graph->adjMatrix[src][dest] = 1;
    }
}

// Function to print the adjacency matrix
void printAdjMatrix(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate in-degree of a vertex
int inDegree(Graph* graph, int vertex) {
    int inDeg = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[i][vertex] == 1) {
            inDeg++;
        }
    }
    return inDeg;
}

// Function to calculate out-degree of a vertex
int outDegree(Graph* graph, int vertex) {
    int outDeg = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1) {
            outDeg++;
        }
    }
    return outDeg;
}

// Function to print in-degree and out-degree of all vertices
void printDegrees(Graph* graph) {
    printf("In-Degree and Out-Degree of all vertices:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("Vertex %d: In-Degree = %d, Out-Degree = %d\n", i, inDegree(graph, i), outDegree(graph, i));
    }
}

int main() {
    int numVertices, numEdges, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    Graph* graph = createGraph(numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    for (int i = 0; i < numEdges; i++) {
        printf("Enter source and destination vertices for edge %d: ", i+1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printAdjMatrix(graph);
    printDegrees(graph);
    return 0;
}
