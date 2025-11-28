#include <stdio.h>

int main() {
    long long E, S;
    scanf("%lld %lld", &E, &S);
    if ((E & S) == 0) printf("hop on roblox!");
    else printf("we’ll try again tomorrow :(");
    return 0;
}