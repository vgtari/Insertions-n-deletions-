#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the array

void insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE) {
        printf("Array is full, insertion not possible.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void delete(int arr[], int *size, int position) {
    if (*size == 0) {
        printf("Array is empty, deletion not possible.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], size = 0, choice, element, position;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                insert(arr, &size, element, position);
                break;
            case 2:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                delete(arr, &size, position);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
