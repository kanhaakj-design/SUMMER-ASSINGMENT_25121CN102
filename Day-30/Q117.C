#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int roll[MAX], marks[MAX];
    char name[MAX][50];
    int n = 0, choice, i, searchRoll, found;

    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter Roll Number: ");
            scanf("%d", &roll[n]);

            printf("Enter Student Name: ");
            scanf(" %[^\n]", name[n]);

            printf("Enter Marks: ");
            scanf("%d", &marks[n]);

            n++;
            printf("Student Record Added Successfully!\n");
            break;

        case 2:
            if (n == 0) {
                printf("No Student Records Available!\n");
            } else {
                printf("\nRoll No\tName\t\tMarks\n");
                printf("-----------------------------------------\n");
                for (i = 0; i < n; i++) {
                    printf("%d\t%-15s%d\n", roll[i], name[i], marks[i]);
                }
            }
            break;

        case 3:
            printf("Enter Roll Number to Search: ");
            scanf("%d", &searchRoll);

            found = 0;
            for (i = 0; i < n; i++) {
                if (roll[i] == searchRoll) {
                    printf("\nStudent Found!\n");
                    printf("Roll Number : %d\n", roll[i]);
                    printf("Name        : %s\n", name[i]);
                    printf("Marks       : %d\n", marks[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Student Record Not Found!\n");
            break;

        case 4:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}