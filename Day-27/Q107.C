#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary, hra, da, netSalary;
};

int main() {
    struct Employee emp[100];
    int n, i;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d\n", i + 1);

        printf("Employee ID: ");
        scanf("%d", &emp[i].id);

        printf("Employee Name: ");
        scanf("%s", emp[i].name);

        printf("Basic Salary: ");
        scanf("%f", &emp[i].basicSalary);

        // Calculate HRA, DA and Net Salary
        emp[i].hra = emp[i].basicSalary * 0.20;
        emp[i].da = emp[i].basicSalary * 0.10;
        emp[i].netSalary = emp[i].basicSalary + emp[i].hra + emp[i].da;
    }

    printf("\n===== Salary Report =====\n");
    printf("ID\tName\tBasic\t\tNet Salary\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\t%.2f\n",
               emp[i].id,
               emp[i].name,
               emp[i].basicSalary,
               emp[i].netSalary);
    }

    return 0;
}