#include <stdio.h>

#define MAX_LEN 256

void to_uppercase_ascii(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

int main() {
    char str[MAX_LEN];

    printf("Vvedit riadok latynytseiu: ");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '\n') {
                str[i] = '\0';
                break;
            }
        }

        printf("Vykhidnyi riadok: %s\n", str);
        to_uppercase_ascii(str);
        printf("Riadok u verkhnomu rehystri: %s\n", str);
    }

    return 0;
}