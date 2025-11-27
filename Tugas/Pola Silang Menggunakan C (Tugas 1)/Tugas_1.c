#include <stdio.h>

int main() {
    int n;
    printf("Masukkan ukuran (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Ukuran harus bilangan positif!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == n - i - 1)
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}