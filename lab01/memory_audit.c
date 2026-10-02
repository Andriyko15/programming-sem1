#include <stdio.h>

int main(void) {
    printf("--- Audit pamiati (Memory Audit) ---\n");
    printf("Rozmir typu char: %zu bytes\n", sizeof(char));
    printf("Rozmir typu int: %zu bytes\n", sizeof(int));
    printf("Rozmir typu float: %zu bytes\n", sizeof(float));
    printf("Rozmir typu double: %zu bytes\n", sizeof(double));
    printf("Rozmir typu short: %zu bytes\n", sizeof(short));
    printf("Rozmir typu long long: %zu bytes\n", sizeof(long long));

    return 0;
}