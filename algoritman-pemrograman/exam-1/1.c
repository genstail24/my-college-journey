#include <stdio.h>

int main()
{
    int angka;

    printf("=== 1. PROGRAM MENGECEK BILANGAN BULAT ADALAH GANJIL ATAU GENAP ===\n");
    printf("Masukkan sebuah angka: ");
    scanf("%d", &angka);

    if (angka % 2 == 0)
    {
        printf("\n%d adalah bilangan genap\n", angka);
    }
    else
    {
        printf("\n%d adalah bilangan ganjil\n", angka);
    }

    return 0;
}