#include <stdio.h>
#include <string.h>

int main() {
    int n, q, t, found = 0;
    char s[105];
    scanf("%d", &n);

    char items[n][105];
    int qty[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", s, &q);
        strcpy(items[i], s);
        qty[i] = q;
    }

    scanf("%d", &t);

    for (int i = 0; i < n; i++) {
        if (qty[i] >= t) {
            if (!found) printf("Items that can be bought:\n");
            printf("- %s : %d\n", items[i], qty[i]);
            found = 1;
        }
    }

    if (!found) printf("Come on Uncle Sakura, I'm hungry!");

    return 0;
}