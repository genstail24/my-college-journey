#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fin, *fgenap, *fganjil;
    int angka;

    fin = fopen("angka.txt", "r");
    if (fin == NULL) {
        perror("Gagal membuka file angka.txt");
        return EXIT_FAILURE;
    }

    fgenap  = fopen("genap.txt", "w");
    fganjil = fopen("ganjil.txt", "w");
    if (fgenap == NULL || fganjil == NULL) {
        perror("Gagal membuka file output");
        fclose(fin);
        return EXIT_FAILURE;
    }

    while (fscanf(fin, "%d", &angka) == 1) {
        if (angka % 2 == 0) {
            fprintf(fgenap, "%d\n", angka);
        } else {
            fprintf(fganjil, "%d\n", angka);
        }
    }

    fclose(fin);
    fclose(fgenap);
    fclose(fganjil);

    printf("Pemrosesan selesai. Periksa genap.txt dan ganjil.txt\n");
    return EXIT_SUCCESS;
}
