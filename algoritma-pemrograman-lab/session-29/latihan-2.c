#include <stdio.h>

// Deklarasi fungsi
int findMax(int arr[], int n);

int main(void) {
    int n;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The maximum element in the array is: %d\n", findMax(arr, n));
    return 0;
}

// Definisi fungsi
int findMax(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }

    int max = findMax(arr, n - 1);
    if (arr[n - 1] > max) {
        return arr[n - 1];
    } else {
        return max;
    }
}
