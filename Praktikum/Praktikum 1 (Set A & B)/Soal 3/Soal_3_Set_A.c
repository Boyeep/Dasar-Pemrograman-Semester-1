#include <stdio.h>
#include <math.h>

int main() {
    int B, N, n=0, e=0, s=0, w=0;
    char M;
    scanf("%d", &B);
    for(int i=0;i<4;i++){
        scanf(" %c %d", &M, &N);
        if(M=='N') n=N;
        else if(M=='E') e=N;
        else if(M=='S') s=N;
        else if(M=='W') w=N;
    }
    int x = e - w;
    int y = n - s;
    int dist = abs(x) + abs(y);
    if(dist <= B) printf("CONAN KECE BET");
    else printf("RAN KECEWA");
    return 0;
}