#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    int num = 1;

    for (int sum = 0; sum <= 2 * (n - 1); sum++) {
        if (sum % 2 == 0) {
            for (int i = sum; i >= 0; i--) {
                int j = sum - i;
                if (i < n && j < n) a[i][j] = num++;
            }
        } else {
            for (int j = sum; j >= 0; j--) {
                int i = sum - j;
                if (i < n && j < n) a[i][j] = num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", a[i][j]);
            if (j < n - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }

    return 0;
}
