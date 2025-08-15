#include <stdio.h>
#include <string.h>

// Deklarasi fungsi
void reverseString(char str[], int start, int end);

int main() {
    char str[100];
    printf("Enter a string: ");
    if (!fgets(str, sizeof str, stdin)) return 0;   // pengganti gets
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') str[len-1] = '\0';

    reverseString(str, 0, (int)strlen(str) - 1);
    printf("Reversed string: %s\n", str);
    return 0;
}

// Definisi fungsi
void reverseString(char str[], int start, int end) {
    if (start >= end) {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseString(str, start + 1, end - 1);
}
