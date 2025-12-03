#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "header.h"

void print_cli(){
    printf("======================================\n");
    printf("[1] %s", "DATA ENTRY\n");
    printf("[2] %s", "LIST\n");
    printf("[3] %s", "LIST SORTED\n");
    printf("[4] %s", "FIND DUPLICATE\n");
    printf("[9] %s", "EXIT\n");
    printf("======================================\n");
}

void create_entry(){
    FILE *fp = fopen("db.dat", "rb");
    FILE *tmp = fopen("tmp.dat", "wb");
    int cnt;
    fread(&cnt, sizeof cnt, 1, fp);
    cnt++;
    fwrite(&cnt, sizeof cnt, 1, tmp);
    Penduduk penduduk;
    while(fread(&penduduk, sizeof penduduk, 1, fp)){
        fwrite(&penduduk, sizeof penduduk, 1, tmp);
    }
    printf("Nama: ");
    getchar();
    fgets(penduduk.nama, 100, stdin);
    for(int i = 0; penduduk.nama[i]; i++){
        if(penduduk.nama[i] == '\n') penduduk.nama[i] = '\0';
    }
    printf("Tanggal Lahir: ");
    scanf("%hd", &penduduk.tanggal_lahir);
    printf("Bulan Lahir: ");
    scanf("%hd", &penduduk.bulan_lahir);
    printf("Tahun Lahir: ");
    scanf("%hd", &penduduk.tahun_lahir);
    printf("Desa       : ");
    scanf("%s", &penduduk.desa);
    printf("Kecamatan  : ");
    scanf("%s", &penduduk.kecamatan);
    fwrite(&penduduk, sizeof penduduk, 1, tmp);
    fclose(fp);
    fclose(tmp);
    remove("db.dat");
    rename("tmp.dat", "db.dat");
}

void displayPenduduk(Penduduk *citizen){
    printf("%-40s %02hd-%02hd-%-07hd %-20s %-20s\n",
        citizen->nama, citizen->tanggal_lahir, citizen->bulan_lahir,
        citizen->tahun_lahir, citizen->desa, citizen->kecamatan
    );
}

void read_entry(){
    FILE *fp = fopen("db.dat", "rb");
    Penduduk penduduk;
    printf("%-40s %-8s %-20s %-20s\n",
        "Nama", "Tanggal Lahir", "Desa", "Kecamatan");
    int cnt;
    fread(&cnt, sizeof cnt, 1, fp);
    while(fread(&penduduk, sizeof penduduk, 1, fp)){
        displayPenduduk(&penduduk);
    }
    printf("\n");
    fclose(fp);
}

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

void listSorted() {
    FILE *file = fopen("db.dat", "rb");
    if (!file) {
        printf("Error: Could not open file db.dat\n");
        return;
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
}

void findDuplicate(){
    FILE *file = fopen("db.dat", "rb");
    if (!file) {
        printf("Error: Could not open file db.dat\n");
        return;
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
}

int prompt(){
    printf("> ");
    int ins;
    scanf("%d", &ins);
    switch(ins){
    case 1:
        create_entry();
    break;
    case 2:
        read_entry();
    break;
    case 3:
        listSorted();
    break;
    case 4:
        findDuplicate();
    break;
    case 9:
        return 0;
    break;
    default:
        printf("Invalid instruction. Please select and action between 1 (entry) and 2 (list) or 9 (exit)\n");
    }
    return 1;
}

void file_not_exist(){
    FILE *fp = fopen("db.dat", "rb");
    if(!fp){
        fclose(fp);
        fp = fopen("db.dat", "wb");
        int cnt = 0;
        fwrite(&cnt, sizeof cnt, 1, fp);
    }
    fclose(fp);
}

int main(){
    printf("TUGAS FINAL DASAR PEMROGRAMAN 2025\n");
    printf("I Gede Made Adi Putra Adnyana (5025251153)\n");
    printf("Boy Steven Benaya Aritonang (5025251154)\n");
    print_cli();    
    file_not_exist();
    while(prompt()){
        print_cli();
    }
}