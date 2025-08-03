#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *nilai;
    int i;
    long sum = 0;
    double avg;

    printf("Masukkan jumlah siswa: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "Input tidak valid.\n");
        return EXIT_FAILURE;
    }

    nilai = (int *)malloc(n * sizeof(int));
    if (nilai == NULL)
    {
        perror("Gagal alokasi memori");
        return EXIT_FAILURE;
    }

    for (i = 0; i < n; i++)
    {
        printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
        if (scanf("%d", &nilai[i]) != 1)
        {
            fprintf(stderr, "Input nilai tidak valid.\n");
            free(nilai);
            return EXIT_FAILURE;
        }
        sum += nilai[i];
    }

    avg = (double)sum / n;
    printf("\nRata-rata nilai: %.2f\n", avg);

    free(nilai);

    return EXIT_SUCCESS;
}
