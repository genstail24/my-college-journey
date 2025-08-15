#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Mahasiswa
{
    char nim[11];
    char nama[21];
    int nilai;
};

struct Mahasiswa daftar[100];
int jumlahData = 0;

void tampilkanData()
{
    printf("========================================\n");
    printf("|NIM        |NAMA                 |NILAI\n");
    printf("========================================\n");
    for (int i = 0; i < jumlahData; i++)
    {
        printf("|%-10s |%-20s |%d   |\n", daftar[i].nim, daftar[i].nama, daftar[i].nilai);
    }
    printf("========================================");
}

void sortingNimAsc()
{
    for (int i = 0; i < jumlahData - 1; i++)
    {
        for (int j = i + 1; j < jumlahData; j++)
        {
            if (strcmp(daftar[i].nim, daftar[j].nim) > 0)
            {
                struct Mahasiswa tmp = daftar[i];
                daftar[i] = daftar[j];
                daftar[j] = tmp;
            }
        }
    }
}

void sortingNilaiDesc()
{
    for (int i = 0; i < jumlahData - 1; i++)
    {
        for (int j = i + 1; j < jumlahData; j++)
        {
            if (daftar[i].nilai < daftar[j].nilai)
            {
                struct Mahasiswa tmp = daftar[i];
                daftar[i] = daftar[j];
                daftar[j] = tmp;
            }
        }
    }
}

int nimValid(char nim[])
{
    if (strlen(nim) != 10)
        return 0;
    for (int i = 0; i < 10; i++)
    {
        if (!isdigit((unsigned char)nim[i]))
            return 0;
    }
    return 1;
}

int namaValid(char nama[])
{
    int panjangNama = strlen(nama);
    return panjangNama >= 3 && panjangNama <= 20;
}

int nilaiValid(int nilai)
{
    return nilai >= 0 && nilai <= 9;
}

void tambahDataMahasiswa()
{
    if (jumlahData >= 100)
    {
        printf("Daftar penuh.\n");
        return;
    }

    struct Mahasiswa mahasiswa;

    while (1)
    {
        printf("Masukkan NIM (10 digit angka): ");
        if (scanf("%10s", mahasiswa.nim) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Input tidak valid!\n");
            continue;
        }
        if (!nimValid(mahasiswa.nim))
        {
            printf("NIM tidak valid! Harus 10 digit angka.\n");
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Masukkan Nama (3-20 karakter tanpa spasi): ");
        if (scanf("%20s", mahasiswa.nama) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Input tidak valid!\n");
            continue;
        }
        if (!namaValid(mahasiswa.nama))
        {
            printf("Nama tidak valid! Panjang 3-20 karakter tanpa spasi.\n");
            continue;
        }
        break;
    }

    while (1)
    {
        printf("Masukkan Nilai (0-9): ");
        if (scanf("%d", &mahasiswa.nilai) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Nilai harus berupa angka.\n");
            continue;
        }
        if (!nilaiValid(mahasiswa.nilai))
        {
            printf("Nilai tidak valid! Masukkan angka antara 0 dan 9.\n");
            continue;
        }
        break;
    }

    daftar[jumlahData++] = mahasiswa;
}

void bacaDariFile()
{
    FILE *f = fopen("file.txt", "r");
    if (!f)
        return;
    while (fscanf(f, "%10s %20s %d", daftar[jumlahData].nim, daftar[jumlahData].nama, &daftar[jumlahData].nilai) == 3)
    {
        jumlahData++;
        if (jumlahData >= 100)
            break;
    }
    fclose(f);
}

void simpanKeFile()
{
    FILE *f = fopen("file.txt", "w");
    if (!f)
        return;
    for (int i = 0; i < jumlahData; i++)
    {
        fprintf(f, "%s %s %d\n", daftar[i].nim, daftar[i].nama, daftar[i].nilai);
    }
    fclose(f);
}

int main()
{
    int pilihan = 0;
    printf("          Program Entri Nilai\n");
    printf("          ===================");
    printf("\n");
    printf("\n");
    bacaDariFile();
    tampilkanData();
    printf("\n");
    while (pilihan != 4)
    {
        printf("\n");
        printf("1. Sorting nim asc\n");
        printf("2. Sorting nilai desc\n");
        printf("3. Tambah Data\n");
        printf("4. Keluar dan Save ke File\n");
        printf("\nMasukan Pilihan : ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
            sortingNimAsc();
            tampilkanData();
        }
        else if (pilihan == 2)
        {
            sortingNilaiDesc();
            tampilkanData();
        }
        else if (pilihan == 3)
        {
            tambahDataMahasiswa();
        }
        else if (pilihan == 4)
        {
            simpanKeFile();
            printf("Data disimpan.\n");
        }
        else
        {
            printf("Menu tidak valid!\n");
        }
    }
    return 0;
}
