#include <stdio.h>

int main() {
    char s[4];
    scanf("%s", s);

    int pts[3] = {0, 0, 0};

    if (s[0] == 'I') pts[0] += 3;
    else if (s[0] == 'S') pts[2] += 3;
    else if (s[0] == 'D') { pts[0]++; pts[2]++; }

    if (s[1] == 'R') pts[1] += 3;
    else if (s[1] == 'I') pts[0] += 3;
    else if (s[1] == 'D') { pts[1]++; pts[0]++; }

    if (s[2] == 'S') pts[2] += 3;
    else if (s[2] == 'R') pts[1] += 3;
    else if (s[2] == 'D') { pts[2]++; pts[1]++; }

    int pos = 1;
    if (pts[0] < pts[1] || pts[0] < pts[2]) pos = 3;
    else if ((pts[0] < pts[1] && pts[0] > pts[2]) || (pts[0] > pts[1] && pts[0] < pts[2])) pos = 2;
    else if (pts[0] == pts[1] && pts[0] == pts[2]) pos = 1;

    if (pos == 1)
        printf("King Indo lolos pildun!!!");
    else if (pos == 2)
        printf("Masih ada harapan! Tetap semangat!");
    else
        printf("Kali ini kami menyatakan kalah, tapi selanjutnya kami akan menang!");

    return 0;
}