#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int empId[MAX], salary[MAX];
    char name[MAX][50], department[MAX][50];
    int count = 0, choice, i, id, found;

    do {
        printf("\n===== MINI EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("Enter Employee ID: ");
            scanf("%d", &empId[count]);

            printf("Enter Employee Name: ");
            scanf(" %[^\n]", name[count]);

            printf("Enter Department: ");
            scanf(" %[^\n]", department[count]);

            printf("Enter Salary: ");
            scanf("%d", &salary[count]);

            count++;
            printf("Employee Added Successfully!\n");
            break;

        case 2:
            if(count == 0) {
                printf("No Employee Records Available!\n");
            } else {
                printf("\nID\tName\t\tDepartment\tSalary\n");
                printf("--------------------------------------------------------\n");
                for(i = 0; i < count; i++) {
                    printf("%d\t%-15s%-15s%d\n",
                           empId[i], name[i], department[i], salary[i]);
                }
            }
            break;

        case 3:
            printf("Enter Employee ID to Search: ");
            scanf("%d", &id);

            found = 0;
            for(i = 0; i < count; i++) {
                if(empId[i] == id) {
                    printf("\nEmployee Found!\n");
                    printf("ID         : %d\n", empId[i]);
                    printf("Name       : %s\n", name[i]);
                    printf("Department : %s\n", department[i]);
                    printf("Salary     : %d\n", salary[i]);
                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("Employee Not Found!\n");
            break;

        case 4:
            printf("Enter Employee ID: ");
            scanf("%d", &id);

            found = 0;
            for(i = 0; i < count; i++) {
                if(empId[i] == id) {
                    printf("Enter New Salary: ");
                    scanf("%d", &salary[i]);
                    printf("Salary Updated Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if(!found)
                printf("Employee Not Found!\n");
            break;

        case 5:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}