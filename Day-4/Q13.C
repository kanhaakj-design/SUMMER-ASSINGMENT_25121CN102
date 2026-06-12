#include <stdio.h>
int main()
{
    int num, term1 = 0, term2 = 1, nextterm;
    printf("enter the no of terms :");
    scanf("%d", &num);
    printf("Fibonacci series :\n");

    for (int i = 1; i <= num; i++)
    {
        printf("%d\t", term1);
        nextterm = term1 + term2;
        term1 = term2;
        term2 = nextterm;
    }
    return 0;
}