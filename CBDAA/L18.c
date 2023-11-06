// 9.1 Aim of the program: Given an undirected weighted connected graph G(V, E) and starring
// vertex ‘s’. Maintain a Min-Priority Queue ‘Q’ from the vertex set V and apply Prim’s algorithm
// to
//  Find the minimum spanning tree T(V, E’). Display the cost adjacency matrix of ‘T’.
//  Display total cost of the minimum spanning tree T.
// Note# Nodes will be numbered consecutively from 1 to n (user input), and edges will have
// varying weight. The graph G can be read from an input file “inUnAdjMat.dat”that contains cost
// adjacency matrix. The expected output could be displayed as the cost adjacency matrix of the
// minimum spanning tree and total cost of the tree.
#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

// Function to implement Prim's algorithm
void primMST(int n, int graph[MAX_NODES][MAX_NODES]) {
    int key[MAX_NODES];
    int inMST[MAX_NODES];
    int MST[MAX_NODES][MAX_NODES];
    int totalCost = 0;

    // Initialize key values, inMST, and MST matrix
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = 0;
        for (int j = 0; j < n; j++) {
            MST[i][j] = 0;
        }
    }

    // Start with the first node
    key[0] = 0;

    // Prim's algorithm
    for (int count = 0; count < n - 1; count++) {
        int minKey = INF;
        int u;

        // Find the vertex with the minimum key value
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        // Add u to the MST
        inMST[u] = 1;

        // Update total cost
        totalCost += key[u];

        // Update MST matrix
        if (u != 0) {
            MST[u][u] = key[u];
            MST[u][u] = key[u];
        }

        // Update key values for adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    // Display MST matrix
    printf("Cost adjacency matrix of the Minimum Spanning Tree:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", MST[i][j]);
        }
        printf("\n");
    }

    // Display total cost
    printf("Total cost of the Minimum Spanning Tree: %d\n", totalCost);
}

int main() {
    int n; // Number of nodes
    int graph[MAX_NODES][MAX_NODES]; // Adjacency matrix

    // Read the graph from "inUnAdjMat.dat"
    FILE *inputFile = fopen("inUnAdjMat.dat", "r");
    if (inputFile == NULL) {
        printf("Error: Couldn't open the input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(inputFile, "%d", &graph[i][j]);
        }
    }

    fclose(inputFile);

    // Call the Prim's algorithm function
    primMST(n, graph);

    return 0;
}
