#include <stdio.h>

int main(void) {
    // Оголошення змінних (використовуємо float для чисел з рухомою комою)
    float V, S, t;

    // Запит та введення розміру файлу
    printf("Vvedit rozmir faylu V (MB): ");
    scanf("%f", &V);

    // Запит та введення пропускної здатності
    printf("Vvedit propusknu zdatnist S (Mbit/s): ");
    scanf("%f", &S);

    // Розрахунок часу за формулою
    t = (V * 8.0) / S;

    // Виведення результату
    printf("Chas peredachi t: %.2f s\n", t);

    return 0;
}