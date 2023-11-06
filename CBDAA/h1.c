#include <stdio.h>
#include <stdlib.h>

// Define the SYMBOL structure
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Define a structure to represent a Huffman tree node
struct Node {
    struct SYMBOL symbol;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(struct SYMBOL symbol) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a Min-Priority Queue (array of nodes)
struct Node** createQueue(int size) {
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * size);
    for (int i = 0; i < size; i++) {
        queue[i] = NULL;
    }
    return queue;
}

// Function to enqueue a node into the queue
void enqueue(struct Node** queue, int* rear, struct Node* node) {
    queue[(*rear)++] = node;
}

// Function to dequeue a node from the queue (remove and return)
struct Node* dequeue(struct Node** queue, int* front) {
    return queue[(*front)++];
}

// Function to build the Huffman Tree
struct Node* buildHuffmanTree(struct SYMBOL symbols[], int size) {
    // Create a Min-Priority Queue (array of nodes)
    struct Node** queue = createQueue(size);
    int front = 0;  // Front of the queue
    int rear = 0;   // Rear of the queue

    // Initialize the queue with nodes for each symbol
    for (int i = 0; i < size; i++) {
        enqueue(queue, &rear, createNode(symbols[i]));
    }

    // Build the Huffman Tree
    while (rear - front > 1) {
        // Sort the queue based on frequencies (ascending order)
        for (int i = front; i < rear - 1; i++) {
            for (int j = front; j < rear - i - 1; j++) {
                if (queue[j]->symbol.frequency > queue[j + 1]->symbol.frequency) {
                    struct Node* temp = queue[j];
                    queue[j] = queue[j + 1];
                    queue[j + 1] = temp;
                }
            }
        }

        // Create a new internal node with the two lowest frequency nodes
        struct Node* newNode = createNode((struct SYMBOL){0, 0});
        newNode->left = dequeue(queue, &front);
        newNode->right = dequeue(queue, &front);

        // Add the new node to the queue
        enqueue(queue, &rear, newNode);
    }

    // The remaining node in the queue is the root of the Huffman Tree
    return queue[front];
}

// Function to print Huffman codes
void printHuffmanCodes(struct Node* root, int* code, int top) {
    if (root->left) {
        code[top] = 0;
        printHuffmanCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printHuffmanCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->symbol.alphabet);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

int main() {
    // Create an array of SYMBOL structures with your characters and frequencies
    int size = 45;
    struct SYMBOL symbols[size];

    // Populate the symbols array with your data

    // Build the Huffman Tree
    struct Node* root = buildHuffmanTree(symbols, size);

    // Print Huffman codes
    int code[size];
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, 0);

    return 0;
}
