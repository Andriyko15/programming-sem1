#include <stdio.h>

int is_prime(int n);
int get_primes_count(int increment);

int main(void) {
    int number;
    int total_primes = 0;

    printf("=== Perevirka chysel na prostotu (Variant 3) ===\n");
    printf("Vvodit tsili chysla (vvedit 0 dlia zavershennia):\n");

    while (1) {
        printf("\nVvedit chyslo: ");
        if (scanf("%d", &number) != 1) {
            printf("Pomylka vvedennia!\n");
            return 1;
        }

        if (number == 0) {
            break;
        }

        if (is_prime(number)) {
            total_primes = get_primes_count(1);
            printf("Chyslo %d ye PROSTYM.\n", number);
        } else {
            total_primes = get_primes_count(0);
            printf("Chyslo %d NE ye prostym.\n", number);
        }

        printf("Usoho prostykh chysel vyyavleno za sesiiu: %d\n", total_primes);
    }

    printf("\nSesiiu zaversheno. Pidsumkova kilkist prostykh chysel: %d\n", total_primes);
    return 0;
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int get_primes_count(int increment) {
    static int prime_counter = 0;
    if (increment > 0) {
        prime_counter += increment;
    }
    return prime_counter;
}