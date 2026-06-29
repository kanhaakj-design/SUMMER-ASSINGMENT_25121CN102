#include <stdio.h>

int main() {
    char name[50];
    int roll;
    float marks[5], total = 0, percentage;
    int i;

    printf("Enter Student Name: ");
    scanf("%s", name);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter marks of 5 subjects:\n");
    for (i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &marks[i]);
        total += marks[i];
    }

    percentage = total / 5;

    printf("\n===== MARKSHEET =====\n");
    printf("Name       : %s\n", name);
    printf("Roll No.   : %d\n", roll);
    printf("Total Marks: %.2f/500\n", total);
    printf("Percentage : %.2f%%\n", percentage);

    if (percentage >= 90)
        printf("Grade      : A+\n");
    else if (percentage >= 80)
        printf("Grade      : A\n");
    else if (percentage >= 70)
        printf("Grade      : B\n");
    else if (percentage >= 60)
        printf("Grade      : C\n");
    else if (percentage >= 50)
        printf("Grade      : D\n");
    else
        printf("Grade      : Fail\n");

    return 0;
}