#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, t1, x2, y2;
    scanf("%lf %lf %lf %lf %lf", &x1, &y1, &t1, &x2, &y2);

    if (x1 == x2 && y1 == y2) {
        printf("Halo, Dan, aku Iel!");
    } else {
        double t2 = atan2(y2 - y1, x2 - x1);
        if (fabs(t1 - t2) < 1e-2)
            printf("Aku akan berjalan lurus ke Dan!");
        else
            printf("Aku akan berputar ke arah tujuan!");
    }

    return 0;
}