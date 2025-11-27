#include <stdio.h>

typedef struct {
    double ril;
    double imag;
} Comp;

Comp add(Comp a, Comp b) {
    return (Comp){
        a.ril + b.ril,
        a.imag + b.imag};
}

Comp subtract(Comp a, Comp b) {
    return (Comp){
        a.ril - b.ril,
        a.imag - b.imag};
}

Comp multiply(Comp a, Comp b) {
    return (Comp){
        a.ril * b.ril - a.imag * b.imag,
        a.ril * b.imag + a.imag * b.ril};
}

Comp divide(Comp a, Comp b) {
    double d = b.ril * b.ril + b.imag * b.imag;
    return (d != 0) ? (Comp){
        (a.ril * b.ril + a.imag * b.imag) / d,
        (a.imag * b.ril - a.ril * b.imag) / d} : (Comp){0, 0};
}

void PrintComp(Comp c) {
    printf("(");
    if (c.imag < 0)
        printf("%.5lf - %.5lfi", c.ril, -c.imag);
    else
        printf("%.5lf + %.5lfi", c.ril, c.imag);
    printf(")");
}

void PrintOp(Comp a, Comp b, Comp res, char op) {
    PrintComp(a);
    printf(" %c ", op);
    PrintComp(b);
    printf(" = ");
    PrintComp(res);
    printf("\n");
}

int main() {
    Comp a, b;

    printf("Input ril a: "); scanf("%lf", &a.ril);
    printf("Input imag a: "); scanf("%lf", &a.imag);
    printf("Input ril b: "); scanf("%lf", &b.ril);
    printf("Input imag b: "); scanf("%lf", &b.imag);
    printf("\n");

    PrintOp(a, b, add(a, b), '+');
    PrintOp(a, b, subtract(a, b), '-');
    PrintOp(a, b, multiply(a, b), '*');
    PrintOp(a, b, divide(a, b), '/');

    return 0;
}