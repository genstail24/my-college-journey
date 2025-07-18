#include <stdio.h>

#define JUMLAH_MAKSIMAL_ANGKA 100

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int daftarAngka[JUMLAH_MAKSIMAL_ANGKA];
    int totalAngkaYangInginDimasukan, angkaYangInginDicari, indeksHasilPencarian;

    printf("\n=== PROGRAM MENGURUTKAN DAN MENCARI ANGKA ===\n");
    printf("Jumlah angka yang ingin dimasukkan: ");
    scanf("%d", &totalAngkaYangInginDimasukan);

    printf("Masukkan %d angka:\n", totalAngkaYangInginDimasukan);
    for (int i = 0; i < totalAngkaYangInginDimasukan; i++)
    {
        printf("- Angka ke-%d: ", i + 1);
        scanf("%d", &daftarAngka[i]);
    }
    insertionSort(daftarAngka, totalAngkaYangInginDimasukan);

    printf("\nData angka setelah diurutkan dari yang terkecil ke terbesar:\n");
    for (int i = 0; i < totalAngkaYangInginDimasukan; i++)
    {
        printf("%d ", daftarAngka[i]);
    }
    printf("\n");

    printf("\nMasukkan angka yang ingin dicari: ");
    scanf("%d", &angkaYangInginDicari);

    indeksHasilPencarian = linearSearch(daftarAngka, totalAngkaYangInginDimasukan, angkaYangInginDicari);

    if (indeksHasilPencarian != -1)
    {
        printf("Angka %d ditemukan di indeks ke-%d dan urutan ke-%d (setelah diurutkan)\n", angkaYangInginDicari, indeksHasilPencarian, (indeksHasilPencarian + 1));
    }
    else
    {
        printf("Angka %d tidak ditemukan dalam data\n", angkaYangInginDicari);
    }

    return 0;
}
