#include <stdio.h>

int main(void) {
    // Змінні
    float V, S, t;

    // Розмір файлу
    printf("Vvedit rozmir faylu V (MB): ");
    scanf("%f", &V);

    // Пропускна здатність
    printf("Vvedit propusknu zdatnist S (Mbit/s): ");
    scanf("%f", &S);

    // Розрахунок часу за формулою
    t = (V * 8.0) / S;

    // Виведення результату
    printf("Chas peredachi t: %.2f s\n", t);

    return 0;
}