#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[MAX];
int count = 0;

// Add Contact
void addContact() {
    printf("\nEnter Name: ");
    scanf(" %[^\n]", contacts[count].name);

    printf("Enter Phone Number: ");
    scanf("%s", contacts[count].phone);

    count++;
    printf("Contact Added Successfully!\n");
}

// Display Contacts
void displayContacts() {
    int i;

    if (count == 0) {
        printf("\nNo Contacts Available!\n");
        return;
    }

    printf("\n----- Contact List -----\n");
    for (i = 0; i < count; i++) {
        printf("Contact %d\n", i + 1);
        printf("Name : %s\n", contacts[i].name);
        printf("Phone: %s\n\n", contacts[i].phone);
    }
}

// Search Contact
void searchContact() {
    char name[50];
    int i, found = 0;

    printf("\nEnter Name to Search: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < count; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("\nContact Found!\n");
            printf("Name : %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Contact Not Found!\n");
}

// Delete Contact
void deleteContact() {
    char name[50];
    int i, j, found = 0;

    printf("\nEnter Name to Delete: ");
    scanf(" %[^\n]", name);

    for (i = 0; i < count; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            for (j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            found = 1;
            printf("Contact Deleted Successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Contact Not Found!\n");
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                deleteContact();
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