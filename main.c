#include <stdio.h>
#include "time.h"

int * generateArray(int size) {//ця функція генерує масив цілих чисел
    int * array = malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++) {
        *(array + i) = rand() % 120 - 60;
        /*  rand() генерує випадкове число. rand() % 120 обмежує це число від 0 до 120.
            rand() % 120 - 60 здвигає цей діапазон від -60 до 60*/
    }
    return array;
}

void printArray(int * array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
    fflush(stdout);
}

int amountOfPairsWithIdenticalNumbers(int * array, int size) {
    int amount = 0;
    int i;
    for (i = 1; i < size; i++) {
        if (*(array + i - 1) == *(array + i)) {
            amount++;
        }
    }
    return amount;
}

int main(int argc, char *argv[])
{
    int size;
    int * array;
    srand(time(NULL));

    size = rand() % 190 + 40;
    array = generateArray(size);
    printArray(array, size);
    printf("%d\n", amountOfPairsWithIdenticalNumbers(array, size));
    return 0;
}
