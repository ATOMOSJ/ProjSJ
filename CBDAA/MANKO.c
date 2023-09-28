#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};
void swap(struct person *a, struct person *b)
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(struct person arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
void buildMinHeap(struct person arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}
void maxHeapify(struct person arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
void buildMaxHeap(struct person arr[], int n)
{
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}
void displayYoungestWeight(struct person arr[], int n)
{
    if (n == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    printf("Weight of the youngest person: %d\n", arr[0].weight);
}
void insertPerson(struct person arr[], int *n, struct person newPerson)
{
    (*n)++;
    int i = (*n) - 1;
    while (i > 0 && newPerson.age < arr[(i - 1) / 2].age)
    {
        arr[i] = arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    arr[i] = newPerson;
}
void deleteOldestPerson(struct person arr[], int *n)
{
    if (*n == 0)
    {
        printf("Heap is empty.\n");
        return;
    }
    swap(&arr[0], &arr[(*n) - 1]);
    (*n)--;
    minHeapify(arr, *n, 0);
}
void readFromFile(struct person **persons, int *n)
{
    FILE *file = fopen("stud.txt", "r+");
    if (file == NULL)
    {
        printf("File not found or unable to open.\n");
        return;
    }
    fscanf(file, "%d", n);
    *persons = (struct person *)malloc((*n) * sizeof(struct person));

    for (int i = 0; i < *n; i++)
    {
        (*persons)[i].id = i + 1;
        char name[50];
        fscanf(file, "%s %d %d %d",
               name, &(*persons)[i].age, &(*persons)[i].height, &(*persons)[i].weight);
        (*persons)[i].name = strdup(name);
    }

    fclose(file);
    printf("Data loaded from file.\n");
}
void saveToFile(struct person *persons, int n)
{
    FILE *file = fopen("stud.txt", "a+");
    if (file == NULL)
    {
        printf("Unable to create or open the file.\n");
        return;
    }

    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s %d %d %d\n",
                persons[i].name, persons[i].age, persons[i].height, persons[i].weight);
    }

    fclose(file);
    printf("saved\n");
}

int main()
{
    int choice;
    int n = 0;
    struct person *persons = NULL;

    do
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data from File\n");
        printf("2. Create a Min-heap based on age\n");
        printf("3. Create a Max-heap based on weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Save Data to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            readFromFile(&persons, &n);
            break;
        case 2:
            if (persons != NULL)
            {
                buildMinHeap(persons, n);
                printf("Min-heap based on age has been created.\n");
            }
            else
            {
                printf("read data first\n");
            }
            break;
        case 3:
            if (persons != NULL)
            {
                buildMaxHeap(persons, n);
                printf("Max-heap based on weight has been created.\n");
            }
            else
            {
                printf("read data first\n");
            }
            break;
        case 4:
            displayYoungestWeight(persons, n);
            break;
        case 5:
            if (persons != NULL)
            {
                struct person newPerson;
                newPerson.id = n + 1;
                printf("Enter data for the new person:\n");
                printf("Name: ");
                char name[50];
                scanf("%s", name);
                newPerson.name = strdup(name);
                printf("Age: ");
                scanf("%d", &newPerson.age);
                printf("Height: ");
                scanf("%d", &newPerson.height);
                printf("Weight: ");
                scanf("%d", &newPerson.weight);
                insertPerson(persons, &n, newPerson);
                printf("inserted.\n");
            }
            else
            {
                printf("read data first\n");
            }
            break;
        case 6:
            if (persons != NULL)
            {
                deleteOldestPerson(persons, &n);
                printf("deleted\n");
            }
            else
            {
                printf("read data first\n");
            }
            break;
        case 7:
            if (persons != NULL)
            {
                saveToFile(persons, n);
            }
            else
            {
                printf("read data first\n");
            }
            break;
        case 8:
            if (persons != NULL)
            {
                for (int i = 0; i < n; i++)
                {
                    free(persons[i].name);
                }
                free(persons);
            }
            printf("exit\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 8);
    return 0;
}
