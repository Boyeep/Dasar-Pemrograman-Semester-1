#include <stdio.h>

int main() {
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);
    
    int i, j, panen = 0;
    int tebu[X];
    
    for(i = 0; i < X; i++) scanf("%d", &tebu[i]);
    
    for(i = 0; i < Z; i++) {
        for(j = 0; j < X; j++) printf("%d%c", tebu[j], j == X - 1 ? '\n' : ' ');
        for(j = 0; j < X; j++) tebu[j]++;
        for(j = 0; j < X; j++) if(tebu[j] > Y) { tebu[j]--; panen++; }
    }
    
    printf("%d", panen);
    return 0;
}