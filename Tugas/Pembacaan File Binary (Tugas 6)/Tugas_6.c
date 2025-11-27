#include <stdio.h>
#include <time.h>

#pragma pack(push, 1)
typedef struct {
    char nama[40];
    short tahun;
    short bulan;
    short tanggal;
    char desa[20];
    char kecamatan[20];
} Penduduk;
#pragma pack(pop)

int hitungUsia(short tahun, short bulan, short tanggal) {
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    int usia = (1900 + tahun);

    usia = now->tm_year + 1900 - usia;
    if ((bulan > now->tm_mon + 1) || ((bulan == now->tm_mon + 1) && tanggal > now->tm_mday))
        usia--;
    return usia;
}

int main() {
    FILE *fp;
    Penduduk p;
    char gender;
    int usia;

    fp = fopen("WargaKebumen.dat", "rb");
    if (!fp) {
        printf("❌ File tidak ditemukan\n");
        return 1;
    }

    fseek(fp, 4, SEEK_SET);

    printf("%-40s %-10s %-20s %-20s %-5s\n", "Nama", "Tgl Lahir", "Desa", "Kecamatan", "Usia");

    while (fread(&p, sizeof(Penduduk), 1, fp)) {

        if (p.tanggal > 40) {
            gender = 'P';
            p.tanggal -= 40;
        } else {
            gender = 'L';
        }

        usia = hitungUsia(p.tahun, p.bulan, p.tanggal);

        if ((usia >= 0 && usia <= 5) || (usia >= 18 && usia <= 60)) {
            printf("%-40s %02d-%02d-%02d %-20s %-20s %d (%c)\n",
                p.nama,
                p.tanggal, p.bulan, (1900 + p.tahun) % 100,
                p.desa, p.kecamatan,
                usia, gender
            );
        }
    }

    fclose(fp);
    return 0;
}