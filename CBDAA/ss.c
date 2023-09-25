#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent rectangles
struct Rectangle {
    float x, y, width, height;
};

// Define a data structure to represent a point (x, y)
struct Point {
    float x, y;
};

// Define a data structure to represent a segment (line segment between two points)
struct Segment {
    struct Point start;
    struct Point end;
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
    // Base case: If there are no rectangles, there's no boundary.
    if (n == 0) {
        *boundary = NULL;
        *boundarySize = 0;
        return;
    }

    // Base case: If there's only one rectangle, the boundary is its four corners.
    if (n == 1) {
        *boundarySize = 4;
        boundary = (struct Segment*)malloc(4 * sizeof(struct Segment));
        // Calculate the four corners of the rectangle and populate the boundary array.
        (*boundary)[0].start.x = rectangles[0].x;
        (*boundary)[0].start.y = rectangles[0].y;
        (*boundary)[0].end.x = rectangles[0].x + rectangles[0].width;
        (*boundary)[0].end.y = rectangles[0].y;

        (*boundary)[1].start.x = rectangles[0].x + rectangles[0].width;
        (*boundary)[1].start.y = rectangles[0].y;
        (*boundary)[1].end.x = rectangles[0].x + rectangles[0].width;
        (*boundary)[1].end.y = rectangles[0].y + rectangles[0].height;

        (*boundary)[2].start.x = rectangles[0].x + rectangles[0].width;
        (*boundary)[2].start.y = rectangles[0].y + rectangles[0].height;
        (*boundary)[2].end.x = rectangles[0].x;
        (*boundary)[2].end.y = rectangles[0].y + rectangles[0].height;

        (*boundary)[3].start.x = rectangles[0].x;
        (*boundary)[3].start.y = rectangles[0].y + rectangles[0].height;
        (*boundary)[3].end.x = rectangles[0].x;
        (*boundary)[3].end.y = rectangles[0].y;
        
        return;
    }

    // Find the vertical piercing line.
    float piercingLine = ComputeVerticalPiercingLine(rectangles, n);

    // Split rectangles into two groups based on their x-coordinates relative to the piercing line.
    struct Rectangle* leftRectangles = (struct Rectangle*)malloc(n * sizeof(struct Rectangle));
    struct Rectangle* rightRectangles = (struct Rectangle*)malloc(n * sizeof(struct Rectangle));
    int leftCount = 0;
    int rightCount = 0;

    for (int i = 0; i < n; i++) {
        if (rectangles[i].x + rectangles[i].width <= piercingLine) {
            leftRectangles[leftCount++] = rectangles[i];
        } else if (rectangles[i].x >= piercingLine) {
            rightRectangles[rightCount++] = rectangles[i];
        } else {
            // Rectangle is split into two parts (left and right) by the piercing line.
            // Add code here to split the rectangle into two parts.
        }
    }

    // Recursively compute boundaries for the left and right rectangles.
    struct Segment* leftBoundary = NULL;
    struct Segment* rightBoundary = NULL;
    int leftBoundarySize = 0;
    int rightBoundarySize = 0;

    ComputeBoundary(leftRectangles, leftCount, &leftBoundary, &leftBoundarySize);
    ComputeBoundary(rightRectangles, rightCount, &rightBoundary, &rightBoundarySize);

    // Combine the left and right boundaries to form the final boundary.
    // Add code here to merge the left and right boundaries into the final boundary.
    // You need to consider the vertical segments created by the piercing line.

    // Free the memory allocated for temporary arrays and segments.
    free(leftRectangles);
    free(rightRectangles);
    free(leftBoundary);
    free(rightBoundary);
}

int main() {
    int n;
    printf("Enter the number of rectangles: ");
    scanf("%d", &n);

    struct Rectangle* rectangles = (struct Rectangle*)malloc(n * sizeof(struct Rectangle));

    // Read rectangle data from the user.

    struct Segment* boundary = NULL;
    int boundarySize = 0;

    ComputeBoundary(rectangles, n, &boundary, &boundarySize);

    printf("Boundary: ");
    for (int i = 0; i < boundarySize; i++) {
        printf("(%f, %f) -> (%f, %f)", boundary[i].start.x, boundary[i].start.y, boundary[i].end.x, boundary[i].end.y);
        if (i < boundarySize - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // Free allocated memory.

    return 0;
}