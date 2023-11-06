#include <stdio.h>
#include <stdlib.h>
struct Item {
    int item_id;
    float item_profit;
    float item_weight;
};
int compare(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    float ratio1 = item1->item_profit / item1->item_weight;
    float ratio2 = item2->item_profit / item2->item_weight;
    if (ratio1 > ratio2) return -1;
    else if (ratio1 < ratio2) return 1;
    else return 0;
}

float fractionalKnapsack(struct Item* items, int n, float capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    float maxProfit = 0.0;
    float currentWeight = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].item_weight <= capacity) {
            maxProfit += items[i].item_profit;
            currentWeight += items[i].item_weight;
        } else {
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

    struct Item* items = (struct Item*)malloc(n * sizeof(struct Item));

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
