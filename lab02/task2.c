#include <stdio.h>
#include <math.h>

int main(void) {
    double x, epsilon;
    
    printf("Vvedit argument X: ");
    scanf("%lf", &x);
    printf("Vvedit tochnist epsilon (napryklad 1e-5): ");
    scanf("%lf", &epsilon);

    // Область збіжності для cos(x) - від мінус нескінченності до плюс нескінченності
    double sum = 1.0;     // Перший член ряду (при n=0) дорівнює 1
    double a_n = 1.0;     // Поточний член ряду
    int n = 1;            // Лічильник ітерацій
    int max_iter = 100000; // Захисний лічильник (Timeout Guard)

    // Цикл працює, поки модуль поточного доданка більший або дорівнює точності
    while (fabs(a_n) >= epsilon) {
        if (n > max_iter) {
            printf("Uvaha: dosyahnuto limit iteratsiy! Ryad rozbihaietsia.\n");
            break;
        }
        
        // Рекурентне співвідношення для cos(x)
        a_n = a_n * (- (x * x) / ((2.0 * n - 1.0) * (2.0 * n)));
        sum += a_n;
        n++;
    }

    double exact_val = cos(x);
    double error = fabs(exact_val - sum);

    printf("\n--- Rezultaty ---\n");
    printf("Obchyslena suma ryadu: %.10lf\n", sum);
    printf("Tochne znachennia cos(X): %.10lf\n", exact_val);
    printf("Absoliutna pokhybka: %.10e\n", error);
    printf("Vytracheno iteratsiy: %d\n", n - 1);

    return 0;
}