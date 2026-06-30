#include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product inventory[MAX];
int count = 0;

// Add Product
void addProduct() {
    printf("\nEnter Product ID: ");
    scanf("%d", &inventory[count].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", inventory[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &inventory[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory[count].price);

    count++;
    printf("Product Added Successfully!\n");
}

// Display Products
void displayProducts() {
    int i;

    if (count == 0) {
        printf("\nNo Products Available!\n");
        return;
    }

    printf("\n----- Inventory -----\n");
    printf("ID\tName\t\tQuantity\tPrice\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].quantity,
               inventory[i].price);
    }
}

// Search Product
void searchProduct() {
    int id, i, found = 0;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("\nProduct Found!\n");
            printf("ID       : %d\n", inventory[i].id);
            printf("Name     : %s\n", inventory[i].name);
            printf("Quantity : %d\n", inventory[i].quantity);
            printf("Price    : %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Product Not Found!\n");
}

// Update Quantity
void updateQuantity() {
    int id, qty, i;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Enter New Quantity: ");
            scanf("%d", &qty);

            inventory[i].quantity = qty;
            printf("Quantity Updated Successfully!\n");
            return;
        }
    }

    printf("Product Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Quantity\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateQuantity();
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