#include <stdio.h>

void hanoi(int n, char sumber, char tujuan, char pembantu) {
    if (n == 1) {
        printf("Pindahkan disk 1 dari %c ke %c\n", sumber, tujuan);
    } else {
        hanoi(n - 1, sumber, pembantu, tujuan);

        printf("Pindahkan disk %d dari %c ke %c\n", n, sumber, tujuan);

        hanoi(n - 1, pembantu, tujuan, sumber);
    }
}

int main() {
    int n = 4;
    printf("Langkah-langkah memindahkan %d disk dari tiang A ke C:\n\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
