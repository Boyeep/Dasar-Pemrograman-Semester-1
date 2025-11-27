#include <stdio.h>
#include <math.h>

void quadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    double RilPart, ImagPart;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    } 
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        printf("x1 = %.2lf\n", x);
        printf("x2 = %.2lf\n", x);
    } 
    else {
        RilPart = -b / (2 * a);
        ImagPart = sqrt(-discriminant) / (2 * a);
        printf("x1 = %.2lf + %.2lfi\n", RilPart, ImagPart);
        printf("x2 = %.2lf - %.2lfi\n", RilPart, ImagPart);
    }
}

int main() {
    double a, b, c;

    printf("Input a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {
        printf("Bukan persamaan kuadrat (a tidak boleh 0)\n");
        return 1;
    }

    quadratic(a, b, c);

    return 0;
}