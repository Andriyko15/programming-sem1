#include <stdio.h>
#include <stdint.h>

uint32_t set_bit(uint32_t reg, unsigned int bit);
uint32_t clear_bit(uint32_t reg, unsigned int bit);
uint32_t toggle_bit(uint32_t reg, unsigned int bit);
int check_bit(uint32_t reg, unsigned int bit);
void print_binary(uint32_t reg);

int main(void) {
    uint32_t reg = 0x00000104u;

    printf("=== Emuliatsiia 32-bitnoho rehistra GPIO (Variant 3) ===\n");
    printf("Pochatkovyi stan rehistra: 0x%08X\n", reg);
    print_binary(reg);

    reg = set_bit(reg, 4);
    printf("\nPislia vstanovlennia bita 4 (0x%08X):\n", reg);
    print_binary(reg);

    reg = clear_bit(reg, 8);
    printf("\nPislia skydannia bita 8 (0x%08X):\n", reg);
    print_binary(reg);

    reg = toggle_bit(reg, 14);
    printf("\nPislia invertuvannia bita 14 (0x%08X):\n", reg);
    print_binary(reg);

    int bit2_state = check_bit(reg, 2);
    printf("\nPerevirka stanu bita 2: %d\n", bit2_state);

    return 0;
}

uint32_t set_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32u) {
        return reg;
    }
    return reg | (1u << bit);
}

uint32_t clear_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32u) {
        return reg;
    }
    return reg & ~(1u << bit);
}

uint32_t toggle_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32u) {
        return reg;
    }
    return reg ^ (1u << bit);
}

int check_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32u) {
        return 0;
    }
    return ((reg & (1u << bit)) != 0u) ? 1 : 0;
}

void print_binary(uint32_t reg) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (int)((reg >> i) & 1u));
        if (i > 0 && i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}