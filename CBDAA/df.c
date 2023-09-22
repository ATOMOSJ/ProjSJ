#include <stdio.h>
#include <stdlib.h>

// Structure to represent a rectangle
struct Rectangle {
    double x, y, width, height;
};

// Function to compare two rectangles based on y-coordinate
int compareRectangles(const void* a, const void* b) {
    struct Rectangle* r1 = (struct Rectangle*)a;
    struct Rectangle* r2 = (struct Rectangle*)b;
    return (r1->y > r2->y) ? 1 : -1;
}

// Function to compute the vertical piercing line
double computeVerticalPiercingLine(struct Rectangle* rectangles, int n) {
    qsort(rectangles, n, sizeof(struct Rectangle), compareRectangles);
    double max_x = rectangles[0].x + rectangles[0].width;
    
    for (int i = 1; i < n; ++i) {
        if (rectangles[i].x > max_x) {
            max_x = rectangles[i].x + rectangles[i].width;
        }
    }
    
    return max_x;
}

int main() {
    int n;
    printf("Enter the number of rectangles: ");
    scanf("%d", &n);
    
    // Allocate memory for rectangles
    struct Rectangle* rectangles = (struct Rectangle*)malloc(n * sizeof(struct Rectangle));
    
    // Read rectangle specifications
    for (int i = 0; i < n; ++i) {
        printf("Enter x, y, width, and height of rectangle %d: ", i + 1);
        scanf("%lf %lf %lf %lf", &rectangles[i].x, &rectangles[i].y, &rectangles[i].width, &rectangles[i].height);
    }
    
    // Compute the vertical piercing line
    double verticalPiercingLine = computeVerticalPiercingLine(rectangles, n);
    
    // Output the boundary points
    printf("Boundary: ");
    for (int i = 0; i < n; ++i) {
        printf("(%.2lf, %.2lf), ", rectangles[i].x, rectangles[i].y);
        printf("(%.2lf, %.2lf), ", rectangles[i].x, rectangles[i].y + rectangles[i].height);
        printf("(%.2lf, %.2lf), ", rectangles[i].x + rectangles[i].width, rectangles[i].y + rectangles[i].height);
        printf("(%.2lf, %.2lf), ", rectangles[i].x + rectangles[i].width, rectangles[i].y);
    }
    printf("\n");
    
    // Free allocated memory
    free(rectangles);

    return 0;
}
