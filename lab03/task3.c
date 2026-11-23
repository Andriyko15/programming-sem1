#include <stdio.h>

#define MAX_LEN 256

void to_lowercase_ascii(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

int main() {
    char text[MAX_LEN];

    printf("Vvedit riadok latynytseiu: ");
    if (fgets(text, MAX_LEN, stdin) != NULL) {
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] == '\n') {
                text[i] = '\0';
                break;
            }
        }

        printf("Vykhidnyi riadok: %s\n", text);
        to_lowercase_ascii(text);
        printf("Riadok u nyzhnomu rehystri: %s\n", text);
    }

    return 0;
}