#include <stdio.h>

int main() {
    int M, B;
    scanf("%d %d", &M, &B);
    
    int beda = M < B ? M : B;
    int sisa = M > B ? M - B : B - M;
    int sama = sisa / 2;
    
    printf("%d %d", beda, sama);
    return 0;
}