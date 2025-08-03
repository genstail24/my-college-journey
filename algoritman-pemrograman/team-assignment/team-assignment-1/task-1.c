#include <stdio.h>
#include <string.h>

struct Buku {
    char pengarang[100];
};

struct Majalah {
    char penerbit[100];
    char edisi[100];
};

union JenisMedia {
    struct Buku buku;
    struct Majalah majalah;
};

struct ItemPerpustakaan {
    char judul[100];
    int tahun_terbit;
    union JenisMedia jenis_media;
};

int main() {
    // declaration
    struct ItemPerpustakaan item;
    char jenis_media[10];

    // input
    printf("Masukkan Judul (tanpa spasi): ");
    scanf("%s", item.judul);
    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &item.tahun_terbit);
    printf("Jenis Media (Buku/Majalah): ");
    scanf("%s", jenis_media);

    // process & output
    if (strcmp(jenis_media, "Buku") == 0) {
        printf("Masukkan Nama Pengarang (tanpa spasi) : ");
        scanf("%s", item.jenis_media.buku.pengarang);
        printf("\n--- DATA BUKU ---\n");
        printf("Judul        : %s\n", item.judul);
        printf("Tahun Terbit : %d\n", item.tahun_terbit);
        printf("Pengarang    : %s\n", item.jenis_media.buku.pengarang);
    } else if (strcmp(jenis_media, "Majalah") == 0) {
        printf("Masukkan Nama Penerbit (tanpa spasi) : ");
        scanf("%s", item.jenis_media.majalah.penerbit);
        printf("Masukkan Edisi (contoh 2) : ");
        scanf("%s", item.jenis_media.majalah.edisi);
        printf("\n--- DATA MAJALAH ---\n");
        printf("Judul        : %s\n", item.judul);
        printf("Tahun Terbit : %d\n", item.tahun_terbit);
        printf("Penerbit     : %s\n", item.jenis_media.majalah.penerbit);
        printf("Edisi ke     : %s\n", item.jenis_media.majalah.edisi);
    } else {
        printf("Jenis media tidak dikenali. Harus 'Buku' atau 'Majalah'.\n");
    }

    return 0;
}
