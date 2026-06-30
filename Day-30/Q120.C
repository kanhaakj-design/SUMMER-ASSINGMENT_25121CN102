#include <stdio.h>
#include <string.h>

#define MAX 100

int roll[MAX], marks[MAX];
char name[MAX][50];
int count = 0;

// Add Student
void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll[count]);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Marks: ");
    scanf("%d", &marks[count]);

    count++;
    printf("Student Added Successfully!\n");
}

// Display Students
void displayStudents() {
    int i;

    if (count == 0) {
        printf("\nNo Student Records Found!\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("Roll No\tName\t\tMarks\n");
    printf("-------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%-15s%d\n", roll[i], name[i], marks[i]);
    }
}

// Search Student
void searchStudent() {
    int r, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &r);

    for (i = 0; i < count; i++) {
        if (roll[i] == r) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", roll[i]);
            printf("Name        : %s\n", name[i]);
            printf("Marks       : %d\n", marks[i]);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student Not Found!\n");
}

// Update Marks
void updateMarks() {
    int r, i;

    printf("\nEnter Roll Number: ");
    scanf("%d", &r);

    for (i = 0; i < count; i++) {
        if (roll[i] == r) {
            printf("Enter New Marks: ");
            scanf("%d", &marks[i]);
            printf("Marks Updated Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

// Delete Student
void deleteStudent() {
    int r, i, j;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &r);

    for (i = 0; i < count; i++) {
        if (roll[i] == r) {
            for (j = i; j < count - 1; j++) {
                roll[j] = roll[j + 1];
                marks[j] = marks[j + 1];
                strcpy(name[j], name[j + 1]);
            }
            count--;
            printf("Student Deleted Successfully!\n");
            return;
        }
    }

    printf("Student Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n========== STUDENT MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Marks\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateMarks();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}