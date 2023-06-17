#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return -y;
}

void rungeKutta(double x0, double y0, double h, double x_end) {
    int n = (int)((x_end - x0) / h);
    double x = x0, y = y0;
    printf("Step Size (h): %.4f\n\n", h);
    printf("x\t\t\t y (approx.)\t\t y (exact)\t\t Error\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i <= n; i++) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * f(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;

        double exact = exp(-x);
        double error = fabs(exact - y);
        printf("%.4f\t\t %.6f\t\t %.6f\t\t %.6f\n", x, y, exact, error);
    }
    printf("\n");
}

int main() {
    double x0 = 0.0;  // initial value of x
    double y0 = 1.0;  // initial value of y
    double x_end = 1.0;  // end value of x

    // Case 1: Step size inside the stable region
    double h1 = 0.1;
    rungeKutta(x0, y0, h1, x_end);

    // Case 2: Step size outside the stable region
    double h2 = 0.2;
    rungeKutta(x0, y0, h2, x_end);

    return 0;
}
