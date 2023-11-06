#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void displayCostMatrix(int V, int costMatrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", costMatrix[i][j]);
        }
        printf("\n");
    }
}

void primMST(int V, int costMatrix[MAX_VERTICES][MAX_VERTICES], int startVertex) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[startVertex] = 0;
    parent[startVertex] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (costMatrix[u][v] && !mstSet[v] && costMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = costMatrix[u][v];
            }
        }
    }

    // Display the cost adjacency matrix of the minimum spanning tree
    displayCostMatrix(V, costMatrix);

    // Calculate and display the total cost of the minimum spanning tree
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        totalWeight += costMatrix[i][parent[i]];
    }
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main() {
    int V;
    int startVertex;

    // Read input values
    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    int costMatrix[MAX_VERTICES][MAX_VERTICES];
    
    // Read the cost adjacency matrix from the "inUnAdjMat.dat" file
    FILE *file = fopen("inUnAdjMat.dat", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(file, "%d", &costMatrix[i][j]);
        }
    }
    fclose(file);

    // Read the starting vertex
    printf("Enter the Starting Vertex: ");
    scanf("%d", &startVertex);

    // Apply the Prim's MST algorithm
    primMST(V, costMatrix, startVertex - 1);

    return 0;
}
