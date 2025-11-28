#include <stdio.h>

int main() {
    long long t;
    scanf("%lld", &t);
    getchar();
    
    while (t--) {
        int n;
        scanf("%d", &n);
        getchar();
        
        char s[1005];
        fgets(s, sizeof(s), stdin);
        
        long long a, key = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a);
            key += a;
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                long long shift = key % 26;
                if (shift < 0) shift += 26;
                if (s[i] >= 'a' && s[i] <= 'z')
                    s[i] = (s[i] - 'a' + shift) % 26 + 'a';
                else
                    s[i] = (s[i] - 'A' + shift) % 26 + 'A';
            }
        }
        
        printf("%s", s);
    }
    return 0;
}