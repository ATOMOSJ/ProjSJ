#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

// Function to perform max heapify on the given array of items
void maxHeapify(struct ITEM* items, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && items[left].profit_weight_ratio > items[largest].profit_weight_ratio) {
        largest = left;
    }

    if (right < n && items[right].profit_weight_ratio > items[largest].profit_weight_ratio) {
        largest = right;
    }

    if (largest != i) {
        // Swap items[i] and items[largest]
        struct ITEM temp = items[i];
        items[i] = items[largest];
        items[largest] = temp;

        maxHeapify(items, n, largest);
    }
}

// Function to perform heap sort on the array of items
void heapSort(struct ITEM* items, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(items, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        // Swap items[0] and items[i]
        struct ITEM temp = items[0];
        items[0] = items[i];
        items[i] = temp;

        maxHeapify(items, i, 0);
    }
}

// Function to solve the Fractional Knapsack problem
float fractionalKnapsack(struct ITEM* items, int n, float capacity) {
    // Calculate profit-to-weight ratios for all items
    for (int i = 0; i < n; i++) {
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    // Sort items based on profit-to-weight ratio in non-increasing order
    heapSort(items, n);

    float maxProfit = 0.0;
    float currentWeight = 0.0;

    // Fill the knapsack with items
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].item_weight <= capacity) {
            maxProfit += items[i].item_profit;
            currentWeight += items[i].item_weight;
        } else {
            // Take a fraction of the item to maximize profit
            float remainingCapacity = capacity - currentWeight;
            maxProfit += (remainingCapacity / items[i].item_weight) * items[i].item_profit;
            break;
        }
    }

    return maxProfit;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM* items = (struct ITEM*)malloc(n * sizeof(struct ITEM));

    printf("Enter the details of each item:\n");
    for (int i = 0; i < n; i++) {
        items[i].item_id = i + 1;
        printf("Item %d:\n", i + 1);
        printf("Profit: ");
        scanf("%f", &items[i].item_profit);
        printf("Weight: ");
        scanf("%f", &items[i].item_weight);
    }

    float capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);

    float maxProfit = fractionalKnapsack(items, n, capacity);

    printf("Maximum Profit: %.2f\n", maxProfit);

    free(items);
    return 0;
}
