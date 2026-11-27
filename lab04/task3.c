#include <stdio.h>
#include <stdint.h>

uint16_t pack_telemetry(uint8_t priority, uint8_t fan_speed, uint8_t error_code, uint8_t power);
void unpack_telemetry(uint16_t packet, uint8_t *priority, uint8_t *fan_speed, uint8_t *error_code, uint8_t *power);

int main(void) {
    uint8_t in_priority = 5u;
    uint8_t in_fan_speed = 180u;
    uint8_t in_error_code = 2u;
    uint8_t in_power = 1u;

    uint16_t packet = pack_telemetry(in_priority, in_fan_speed, in_error_code, in_power);

    uint8_t out_priority = 0u;
    uint8_t out_fan_speed = 0u;
    uint8_t out_error_code = 0u;
    uint8_t out_power = 0u;

    unpack_telemetry(packet, &out_priority, &out_fan_speed, &out_error_code, &out_power);

    printf("=== Pakuvannia ta rozpakuvannia telemetrii (Variant 3) ===\n");
    printf("Pochatkovi parametry:\n");
    printf("  Priority   : %u\n", (unsigned int)in_priority);
    printf("  Fan speed  : %u\n", (unsigned int)in_fan_speed);
    printf("  Error code : %u\n", (unsigned int)in_error_code);
    printf("  Power      : %u\n", (unsigned int)in_power);

    printf("\nUpakovane slovo (HEX): 0x%04X\n", (unsigned int)packet);

    printf("\nRozpakovani parametry:\n");
    printf("  Priority   : %u\n", (unsigned int)out_priority);
    printf("  Fan speed  : %u\n", (unsigned int)out_fan_speed);
    printf("  Error code : %u\n", (unsigned int)out_error_code);
    printf("  Power      : %u\n", (unsigned int)out_power);

    if (in_priority == out_priority &&
        in_fan_speed == out_fan_speed &&
        in_error_code == out_error_code &&
        in_power == out_power) {
        printf("\nRezultat: parametry povnistiu identychni.\n");
    } else {
        printf("\nRezultat: viyavleno nevidpovidnist parametriv.\n");
    }

    return 0;
}

uint16_t pack_telemetry(uint8_t priority, uint8_t fan_speed, uint8_t error_code, uint8_t power) {
    uint16_t p = (uint16_t)(priority & 0x0Fu);
    uint16_t f = (uint16_t)(fan_speed & 0xFFu);
    uint16_t e = (uint16_t)(error_code & 0x03u);
    uint16_t pw = (uint16_t)(power & 0x01u);

    uint16_t packet = 0u;
    packet |= (uint16_t)(p << 0);
    packet |= (uint16_t)(f << 4);
    packet |= (uint16_t)(e << 12);
    packet |= (uint16_t)(pw << 14);

    return packet;
}

void unpack_telemetry(uint16_t packet, uint8_t *priority, uint8_t *fan_speed, uint8_t *error_code, uint8_t *power) {
    if (priority != NULL) {
        *priority = (uint8_t)((packet >> 0) & 0x0Fu);
    }
    if (fan_speed != NULL) {
        *fan_speed = (uint8_t)((packet >> 4) & 0xFFu);
    }
    if (error_code != NULL) {
        *error_code = (uint8_t)((packet >> 12) & 0x03u);
    }
    if (power != NULL) {
        *power = (uint8_t)((packet >> 14) & 0x01u);
    }
}