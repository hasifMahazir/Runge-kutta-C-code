#include <stdio.h>
#include <math.h>

double exact_solution(double x) {
    return exp(-x);
}

void backward_euler(double h) {
    double x, y, y_exact;
    int n = 1 / h;  // Number of steps

    printf("Step Size (h) = %f\n\n", h);
    printf("x\t\tApproximate (y)\t\tExact (y_exact)\t\t|y - y_exact|\n");
    printf("--------------------------------------------------------------\n");

    // Initial conditions
    x = 0.0;
    y = 1.0;

    printf("%f\t%f\t\t%f\t\t%f\n", x, y, exact_solution(x), fabs(y - exact_solution(x)));

    // Perform backward Euler method
    for (int i = 1; i <= n; i++) {
        x += h;
        y = y / (1 + h);
        y_exact = exact_solution(x);
        printf("%f\t%f\t\t%f\t\t%f\n", x, y, y_exact, fabs(y - y_exact));
    }

    printf("\n");
}

int main() {
    double h_values[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7};  // Step sizes

    printf("Backward Euler Method for Stiff Differential Equations\n\n");

    for (int i = 0; i < sizeof(h_values) / sizeof(h_values[0]); i++) {
        backward_euler(h_values[i]);
    }

    return 0;
}
