#include <stdio.h>
#include <math.h>

// Define the quadratic equation coefficients
double p, q, r;

// Function to calculate the value of the polynomial equation
double f(double x) {
    return p * x * x + q * x + r;
}

// Function to find the root using the Regula Falsi method
double regulaFalsi(double a, double b, int n, double eps) {
    double c;
    
    for (int i = 0; i < n; i++) {
        // Calculate the Regula Falsi approximation
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        
        // Check if the root is within the error tolerance
        if (fabs(f(c)) < eps) {
            return c;
        }
        
        // Update the interval [a, b] based on the sign of f(c)
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    // Return the final approximation if max iterations reached
    return c;
}

int main() {
    double a, b, eps, root;
    int n;

    // Input coefficients p, q, and r
    printf("Enter coefficients (p, q, r): ");
    scanf("%lf %lf %lf", &p, &q, &r);

    // Input interval endpoints [a, b], max iterations, and error tolerance
    printf("Enter interval endpoints (a, b): ");
    scanf("%lf %lf", &a, &b);

    printf("Enter maximum number of iterations (n): ");
    scanf("%d", &n);

    printf("Enter error tolerance (eps): ");
    scanf("%lf", &eps);

    // Find the root using the Regula Falsi method
    root = regulaFalsi(a, b, n, eps);

    // Print the result
    printf("The root is approximately: %lf\n", root);

    return 0;
}
