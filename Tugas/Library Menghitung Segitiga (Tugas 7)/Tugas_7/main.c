#include <stdio.h>
#include <math.h>
#include "area.h"
#include "perimeter.h"
#include "circumcenter.h"

int main() {
    double x1, y1, x2, y2, x3, y3;
    double ox, oy;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    scanf("%lf %lf", &x3, &y3);

    printf("Luas segitiga: %.2lf\n", luas_segitiga(x1, y1, x2, y2, x3, y3));
    printf("Keliling segitiga: %.2lf\n", keliling_segitiga(x1, y1, x2, y2, x3, y3));

    circumcenter(x1, y1, x2, y2, x3, y3, &ox, &oy);
    if (isnan(ox)) {
        printf("Titik tengah lingkaran: Tidak valid (titik segaris)\n");
    } else {
        printf("Titik tengah lingkaran: (%.2lf, %.2lf)\n", ox, oy);
    }

    return 0;
}
