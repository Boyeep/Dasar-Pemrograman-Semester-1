#include <stdio.h>

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    long long x = a, y = b, z = c;
    if (x > y) { long long t = x; x = y; y = t; }
    if (y > z) { long long t = y; y = z; z = t; }
    if (x > y) { long long t = x; x = y; y = t; }

    if (x > 0 && y > 0 && z > 0 && x*x + y*y == z*z)
        printf("Yatta, aku bisa membentuk segitiga!");
    else
        printf("Gomenasai, segitiga tidak dapat dibuat.");

    return 0;
}