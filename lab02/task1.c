#include <stdio.h>
#include <math.h>

int main(void) {
    double x_start, x_end, dx, x, y;

    printf("Vvedit X_start: ");
    scanf("%lf", &x_start);
    printf("Vvedit X_end: ");
    scanf("%lf", &x_end);
    printf("Vvedit krok dX: ");
    scanf("%lf", &dx);

    if (x_start >= x_end || dx <= 0) {
        printf("Pomylka: nekorektni vkhidni dani! (X_start maie byty menshym za X_end, a dX > 0)\n");
        return 1; 
    }

    printf("\n----------------------------\n");
    printf("|     X      |      Y      |\n");
    printf("----------------------------\n");

    for (x = x_start; x <= x_end; x += dx) {
        if (x <= 1.0) {
            y = 2.0 * x + 1.0;
            printf("| %10.2lf | %11.4lf |\n", x, y);
        } else if (x > 1.0 && x <= 3.0) {
            // Захист від ділення на нуль при X = 2
            if (fabs(x - 2.0) < 1e-9) { 
                printf("| %10.2lf | [Ne vyznacheno] |\n", x);
            } else {
                y = x / (x - 2.0);
                printf("| %10.2lf | %11.4lf |\n", x, y);
            }
        } else {
            y = sqrt(x);
            printf("| %10.2lf | %11.4lf |\n", x, y);
        }
    }
    printf("----------------------------\n");

    return 0;
}