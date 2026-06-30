#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int bookId[MAX], issued[MAX];
    char title[MAX][50];
    char author[MAX][50];
    int count = 0, choice, i, id, found;

    do {
        printf("\n===== MINI LIBRARY SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &bookId[count]);

            printf("Enter Book Title: ");
            scanf(" %[^\n]", title[count]);

            printf("Enter Author Name: ");
            scanf(" %[^\n]", author[count]);

            issued[count] = 0;
            count++;

            printf("Book Added Successfully!\n");
            break;

        case 2:
            if (count == 0) {
                printf("No Books Available!\n");
            } else {
                printf("\nID\tTitle\t\tAuthor\t\tStatus\n");
                printf("----------------------------------------------------\n");
                for (i = 0; i < count; i++) {
                    printf("%d\t%-15s%-15s%s\n",
                           bookId[i],
                           title[i],
                           author[i],
                           issued[i] ? "Issued" : "Available");
                }
            }
            break;

        case 3:
            printf("Enter Book ID to Search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (bookId[i] == id) {
                    printf("\nBook Found!\n");
                    printf("ID     : %d\n", bookId[i]);
                    printf("Title  : %s\n", title[i]);
                    printf("Author : %s\n", author[i]);
                    printf("Status : %s\n",
                           issued[i] ? "Issued" : "Available");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book Not Found!\n");
            break;

        case 4:
            printf("Enter Book ID to Issue: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < count; i++) {
                if (bookId[i] == id) {
                    if (issued[i] == 0) {
                        issued[i] = 1;
                        printf("Book Issued Successfully!\n");
                    } else {
                        printf("Book Already Issued!\n");
                    }
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book Not Found!\n");
            break;

        case 5:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}