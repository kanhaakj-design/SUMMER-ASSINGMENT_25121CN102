#include <stdio.h>

long long largestPrimeFactor(long long n) {
    long long largest = -1;

    // Remove factors of 2
    while (n % 2 == 0) {
        largest = 2;
        n /= 2;
    }

    // Check odd factors
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largest = i;
            n /= i;
        }
    }

    // If n is still greater than 2, it is prime
    if (n > 2)
        largest = n;

    return largest;
}

int main() {
    long long num;

    printf("Enter a number: ");
    scanf("%lld", &num);

    printf("Largest Prime Factor = %lld\n", largestPrimeFactor(num));

    return 0;
}