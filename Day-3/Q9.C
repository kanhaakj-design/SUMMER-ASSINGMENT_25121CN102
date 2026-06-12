#include<stdio.h>
int main(){

    int i,num ;
    int count=0;
    printf("check whether the number is prime or not :");
    scanf("%d \n", &num);

    for(int i=1; i<=num ;i++){
        if(num%i==0)
        {
            count++;
        }
        

    }

    if(count==2)
    {
        printf("The number is prime");
    }
    else{
        printf("The number is not prime");
    }
    return 0;
}