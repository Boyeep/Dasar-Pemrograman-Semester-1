#include <stdio.h>
#include <string.h>

#include "header.h"

void swap(Penduduk *xp, Penduduk *yp) {
    Penduduk temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(Penduduk arr[], int n) {
    int i, j, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            int cmp = strcmp(arr[j].nama, arr[j+1].nama);
            if (cmp > 0 ||
               (cmp == 0 && (arr[j].tahun_lahir > arr[j+1].tahun_lahir ||
                (arr[j].tahun_lahir == arr[j+1].tahun_lahir && arr[j].bulan_lahir > arr[j+1].bulan_lahir) ||
                (arr[j].tahun_lahir == arr[j+1].tahun_lahir && arr[j].bulan_lahir == arr[j+1].bulan_lahir &&
                 arr[j].tanggal_lahir > arr[j+1].tanggal_lahir)) )) {

                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    FILE *file = fopen("db.dat", "rb");
    if (!file) {
        printf("Error: Could not open file db.dat\n");
        return 1;
    }

    int n;
    fread(&n, sizeof(n), 1, file);

    Penduduk p[n];
    char line[256];

    for (int i = 0; i < n; i++) {
        fread(p, sizeof(p[0]), n, file);
    }

    fclose(file);

    bubbleSort(p, n);

    printf("\nData penduduk setelah diurutkan:\n");
    for (int i = 0; i < n; i++) {
        printf("Nama: %s | TTL: %hd/%hd/%hd | Desa: %s | Kecamatan: %s\n",
               p[i].nama, p[i].tanggal_lahir, p[i].bulan_lahir, p[i].tahun_lahir, p[i].desa, p[i].kecamatan);
    }

    printf("\nData duplikat:\n");
    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        if (strcmp(p[i].nama, p[i+1].nama) == 0 &&
            p[i].tanggal_lahir == p[i+1].tanggal_lahir &&
            p[i].bulan_lahir == p[i+1].bulan_lahir &&
            p[i].tahun_lahir == p[i+1].tahun_lahir) {

            printf("Nama: %s | TTL: %hd/%hd/%hd | Desa: %s | Kecamatan: %s\n",
                   p[i].nama,
                   p[i].tanggal_lahir, p[i].bulan_lahir, p[i].tahun_lahir,
                   p[i].desa, p[i].kecamatan);
            found = 1;
        }
    }

    if (!found) printf("Tidak ada duplikat.\n");

    return 0;
}