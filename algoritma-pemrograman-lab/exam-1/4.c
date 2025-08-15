#include <stdio.h>

long hitung_faktorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * hitung_faktorial(n - 1);
    }
}

int main()
{
    int input;
    int hasil;

    printf("Masukan angka: ");
    scanf("%d", &input);

    hasil = hitung_faktorial(input);
    printf("Faktorial dari %d adalah %d", input, hasil);
}
