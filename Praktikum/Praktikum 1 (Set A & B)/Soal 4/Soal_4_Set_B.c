#include <stdio.h>
#include <stdlib.h>

int main() {
    int d1, h1, m1;
    int d2, h2, m2;
    char kendaraan, opsi;

    scanf("%d %d:%d", &d1, &h1, &m1);
    scanf("%d %d:%d", &d2, &h2, &m2);
    scanf(" %c", &kendaraan);
    scanf(" %c", &opsi);

    long long start = d1 * 24 * 60 + h1 * 60 + m1;
    long long end = d2 * 24 * 60 + h2 * 60 + m2;

    if (end < start) {
        printf("Tidak mungkin");
        return 0;
    }

    long long diff = end - start;
    int hari = diff / (24 * 60);
    diff %= (24 * 60);
    int jam = diff / 60;
    int menit = diff % 60;

    long long biaya = 0;

    if (kendaraan == 'M') {
        if (hari > 0) {
            biaya = 10000 + hari * 150000;
            if (jam < 3) {
                biaya += jam * 0;
            } else {
                biaya += (jam - 3) * 2000;
            }
            if (menit > 0) biaya += 2000;
        } else {
            if (jam < 3) biaya = 10000;
            else biaya = 10000 + (jam - 3) * 2000;
            if (jam >= 3 && menit > 0) biaya += 2000;
        }
    } else if (kendaraan == 'S') {
        if (hari > 0) {
            biaya = hari * 50000;
            if (jam > 0 || menit > 0) biaya += 3000;
        } else {
            biaya = 3000;
        }
    }

    long long diskon = 0;
    if (opsi == 'b') {
        diskon = biaya * 20 / 100;
        if (diskon > 10000) diskon = 10000;
    } else if (opsi == 'c') {
        diskon = biaya * 10 / 100;
        if (diskon > 20000) diskon = 20000;
    }

    biaya -= diskon;

    printf("Anda telah berada di sini selama %d hari, %d jam, dan %d menit. Anda harus membayar sebesar %lld rupiah",
        hari, jam, menit, biaya);

    return 0;
}
