#include <stdio.h>

int main() {
    int arr[100], n, i, choice;
    int element, found;
    int max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    do {
        printf("\n===== MENU DRIVEN ARRAY OPERATIONS =====\n");
        printf("1. Enter Array Elements\n");
        printf("2. Display Array\n");
        printf("3. Search Element\n");
        printf("4. Find Maximum Element\n");
        printf("5. Find Minimum Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter %d elements:\n", n);
            for(i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Array Created Successfully!\n");
            break;

        case 2:
            printf("Array Elements: ");
            for(i = 0; i < n; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d", &element);
            found = 0;

            for(i = 0; i < n; i++) {
                if(arr[i] == element) {
                    printf("Element found at position %d\n", i + 1);
                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("Element not found.\n");
            break;

        case 4:
            max = arr[0];
            for(i = 1; i < n; i++) {
                if(arr[i] > max)
                    max = arr[i];
            }
            printf("Maximum Element = %d\n", max);
            break;

        case 5:
            min = arr[0];
            for(i = 1; i < n; i++) {
                if(arr[i] < min)
                    min = arr[i];
            }
            printf("Minimum Element = %d\n", min);
            break;

        case 6:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}