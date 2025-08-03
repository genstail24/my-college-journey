#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_NAMA 50

typedef struct {
    char nama[MAX_NAMA];
    int umur;
    char no_registrasi[20];
} Siswa;

void tambahDataSiswa() {
    Siswa siswa;
    FILE *fp = fopen("data_siswa.txt", "a");
    if (!fp) {
        printf("Gagal membuka file.\n");
        return;
    }

    printf("Masukkan nama: ");
    fgets(siswa.nama, sizeof(siswa.nama), stdin);
    siswa.nama[strcspn(siswa.nama, "\n")] = 0;

    printf("Masukkan umur: ");
    scanf("%d", &siswa.umur);
    getchar(); // buang newline

    printf("Masukkan nomor registrasi: ");
    fgets(siswa.no_registrasi, sizeof(siswa.no_registrasi), stdin);
    siswa.no_registrasi[strcspn(siswa.no_registrasi, "\n")] = 0;

    fprintf(fp, "%s,%d,%s\n", siswa.nama, siswa.umur, siswa.no_registrasi);
    fclose(fp);

    printf("Data siswa berhasil ditambahkan.\n");
}

void hapusDataSiswa() {
    char no_target[20];
    char line[MAX_LINE];
    int ditemukan = 0;

    printf("Masukkan nomor registrasi yang ingin dihapus: ");
    fgets(no_target, sizeof(no_target), stdin);
    no_target[strcspn(no_target, "\n")] = 0;

    FILE *fp = fopen("data_siswa.txt", "r");
    FILE *tmp = fopen("temp_siswa.txt", "w");

    if (!fp || !tmp) {
        printf("Gagal membuka file.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *nama = strtok(line, ",");
        char *umur = strtok(NULL, ",");
        char *no_reg = strtok(NULL, ",\n");

        if (no_reg && strcmp(no_target, no_reg) == 0) {
            ditemukan = 1;
            continue;
        }

        if (nama && umur && no_reg) {
            fprintf(tmp, "%s,%s,%s\n", nama, umur, no_reg);
        }
    }

    fclose(fp);
    fclose(tmp);

    if (ditemukan) {
        remove("data_siswa.txt");
        rename("temp_siswa.txt", "data_siswa.txt");
        printf("Data berhasil dihapus.\n");
    } else {
        remove("temp_siswa.txt");
        printf("Data tidak ditemukan.\n");
    }
}

void cariDataSiswa() {
    char keyword[50];
    char line[MAX_LINE];
    int ditemukan = 0;

    printf("Masukkan nama atau nomor registrasi: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    FILE *fp = fopen("data_siswa.txt", "r");
    if (!fp) {
        printf("Gagal membuka file.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *nama = strtok(line, ",");
        char *umur = strtok(NULL, ",");
        char *no_reg = strtok(NULL, ",\n");

        if (
            (nama && strstr(nama, keyword)) ||
            (no_reg && strcmp(no_reg, keyword) == 0)
        ) {
            printf("Ditemukan:\nNama: %s\nUmur: %s\nNo. Registrasi: %s\n\n",
                   nama, umur, no_reg);
            ditemukan = 1;
        }
    }

    fclose(fp);

    if (!ditemukan) {
        printf("Data tidak ditemukan.\n");
    }
}

int main() {
    int pilihan;

    while (1) {
        printf("\n=== MENU DATA SISWA ===\n");
        printf("1. Tambah Data Siswa\n");
        printf("2. Hapus Data Siswa\n");
        printf("3. Cari Data Siswa\n");
        printf("0. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        getchar(); // konsumsi newline

        switch (pilihan) {
            case 1: tambahDataSiswa(); break;
            case 2: hapusDataSiswa(); break;
            case 3: cariDataSiswa(); break;
            case 0: exit(0);
            default: printf("Pilihan tidak valid.\n");
        }
    }

    return 0;
}
