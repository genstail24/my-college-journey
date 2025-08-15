#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int panjangKarakter;

    printf("Masukkan nama: ");
    scanf("%s", input);

    panjangKarakter = strlen(input);
    printf("Panjang string: %d\n", panjangKarakter);

    return 0;
}
