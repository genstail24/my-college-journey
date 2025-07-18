#include <stdio.h>

#define JUMLAH_MAKSIMAL_PRODUK 100

typedef struct
{
    char nama[50];
    float harga;
    int jumlah;
} Barang;

int main()
{
    Barang daftar[JUMLAH_MAKSIMAL_PRODUK];
    int totalProdukYangInginDimasukan, i, indexProdukTermahal = 0;

    printf("\n=== PROGRAM MENCARI PRODUK DENGAN HARGA TERTINGGI ===\n");
    printf("Jumlah produk yang ingin dimasukkan: ");
    scanf("%d", &totalProdukYangInginDimasukan);

    for (i = 0; i < totalProdukYangInginDimasukan; i++)
    {
        printf("\n[Input Produk %d]\n", i + 1);
        printf("Nama produk   : ");
        scanf(" %[^\n]", daftar[i].nama);
        printf("Harga produk  : ");
        scanf("%f", &daftar[i].harga);
        printf("Jumlah stok   : ");
        scanf("%d", &daftar[i].jumlah);
    }

    for (i = 1; i < totalProdukYangInginDimasukan; i++)
    {
        if (daftar[i].harga > daftar[indexProdukTermahal].harga)
        {
            indexProdukTermahal = i;
        }
    }

    printf("\n=== PRODUK DENGAN HARGA TERTINGGI ===\n");
    printf("Nama   : %s\n", daftar[indexProdukTermahal].nama);
    printf("Harga  : Rp%.2f\n", daftar[indexProdukTermahal].harga);
    printf("Stok   : %d unit\n", daftar[indexProdukTermahal].jumlah);

    return 0;
}
