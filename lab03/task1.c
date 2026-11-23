#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main() {
    int arr[SIZE];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101 - 50;
    }

    printf("Vykhidnyi masyv:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%4d ", arr[i]);
    }
    printf("\n\n");

    int min_val = arr[0];
    int min_idx = 0;

    for (int i = 1; i < SIZE; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_idx = i;
        }
    }

    printf("Minimalnyi element: %d (indeks: %d, nomer: %d)\n",
           min_val, min_idx, min_idx + 1);

    int first_pos = -1;
    int last_pos = -1;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > 0) {
            if (first_pos == -1) {
                first_pos = i;
            }
            last_pos = i;
        }
    }

    if (first_pos == -1 || first_pos == last_pos) {
        printf("Nedostatno dodatnykh elementiv dlia obchyslennia sumy.\n");
    } else if (last_pos - first_pos == 1) {
        printf("Mizh pershym (indeks %d) ta ostannim (indeks %d) dodatnymy nemaie elementiv. Suma = 0.\n",
               first_pos, last_pos);
    } else {
        int sum = 0;
        for (int i = first_pos + 1; i < last_pos; i++) {
            sum += arr[i];
        }
        printf("Pershyi dodatnyi: arr[%d] = %d\n", first_pos, arr[first_pos]);
        printf("Ostannii dodatnyi: arr[%d] = %d\n", last_pos, arr[last_pos]);
        printf("Suma elementiv mizh nymy: %d\n", sum);
    }

    return 0;
}