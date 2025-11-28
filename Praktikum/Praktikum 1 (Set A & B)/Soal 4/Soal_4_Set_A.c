#include <stdio.h>
#include <stdlib.h>

int main() {
    long long N, M;
    long long BK, KK, BV, KV;
    
    scanf("%lld %lld", &N, &M);
    scanf("%lld %lld %lld %lld", &BK, &KK, &BV, &KV);
    
    long long jarak = llabs(BK - BV) + llabs(KK - KV);
    
    if (jarak <= 1) {
        printf("[Now I am the master.]");
    } else {
        printf("[Only a master of evil, Darth.]");
    }
    
    return 0;
}