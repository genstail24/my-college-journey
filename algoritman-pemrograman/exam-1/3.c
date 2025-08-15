#include <stdio.h>

int main()
{
    int array[] = {10, 20, 30, 40, 50};
    int *ptrArray = array;
    int jumlahArray = sizeof(array) / sizeof(array[0]);

    printf("Elemen array: ");
    for (int i = 0; i < jumlahArray; i++)
    {
        printf("%d ", *(ptrArray + i));
    }
    printf("\n");

    return 0;
}
