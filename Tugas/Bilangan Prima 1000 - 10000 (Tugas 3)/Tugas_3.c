#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    if (n % 2 == 0 && n != 2) return 0;

    for (int i = 3; i <= n / 2; i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    printf("Bilangan prima dari 1000 sampai 10000:\n");

    for (int n = 1000; n <= 10000; n++) {
        if (isPrime(n)) {
            printf("%d ", n);
        }
    }

    printf("\n");
    return 0;
}