#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent rectangles
struct Rectangle {
    float x, y, width, height;
};

// Define a data structure to represent a segment (line segment between two points)
struct Segment {
    float x1, y1, x2, y2;
};

// Function to compute the vertical piercing line
float ComputeVerticalPiercingLine(struct Rectangle* rectangles, int n) {
    float maxLeftX = rectangles[0].x;
    float minRightX = rectangles[0].x + rectangles[0].width;

    for (int i = 1; i < n; i++) {
        float leftX = rectangles[i].x;
        float rightX = rectangles[i].x + rectangles[i].width;

        if (leftX > maxLeftX) {
            maxLeftX = leftX;
        }

        if (rightX < minRightX) {
            minRightX = rightX;
        }
    }

    return (maxLeftX + minRightX) / 2.0;
}

// Function to compute the boundary
void ComputeBoundary(struct Rectangle* rectangles, int n, struct Segment** boundary, int* boundarySize) {
    // Initialize boundary size to 0
    *boundarySize = 0;

    // Allocate memory for the boundary segments (an upper bound is 4 times the number of rectangles)
    *boundary = (struct Segment*)malloc(4 * n * sizeof(struct Segment));

    // Initialize left and right boundaries
    struct Segment* leftBoundary = *boundary;
    struct Segment* rightBoundary = *boundary + 2 * n;

    for (int i = 0; i < n; i++) {
        struct Rectangle rect = rectangles[i];

        // Left boundary segment
        leftBoundary[i].x1 = rect.x;
        leftBoundary[i].y1 = rect.y;
        leftBoundary[i].x2 = rect.x;
        leftBoundary[i].y2 = rect.y + rect.height;

        // Right boundary segment
        rightBoundary[i].x1 = rect.x + rect.width;
        rightBoundary[i].y1 = rect.y;
        rightBoundary[i].x2 = rect.x + rect.width;
        rightBoundary[i].y2 = rect.y + rect.height;
    }

    // Update boundary size
    *boundarySize = 2 * n;
}

int main() {
    int n;
    printf("Enter the number of rectangles: ");
    scanf("%d", &n);

    struct Rectangle* rectangles = (struct Rectangle*)malloc(n * sizeof(struct Rectangle));

    // Read rectangle data from the user
    printf("Enter the coordinates and dimensions of rectangles (x y width height):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f %f %f", &rectangles[i].x, &rectangles[i].y, &rectangles[i].width, &rectangles[i].height);
    }

    // Compute the vertical piercing line
    float piercingLine = ComputeVerticalPiercingLine(rectangles, n);

    // Compute the boundary segments
    struct Segment* boundary;
    int boundarySize;
    ComputeBoundary(rectangles, n, &boundary, &boundarySize);

    // Print the boundary segments
    printf("Boundary: ");
    for (int i = 0; i < boundarySize; i++) {
        printf("(%f, %f) -> (%f, %f)", boundary[i].x1, boundary[i].y1, boundary[i].x2, boundary[i].y2);
        if (i < boundarySize - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // Free allocated memory
    free(rectangles);
    free(boundary);

    return 0;
}

