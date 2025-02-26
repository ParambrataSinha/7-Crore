#include <stdio.h>
#include <math.h>

// Function to compute sin(x) using the Taylor series
void taylor_sin(double x, int terms)
{
    double approx_sin = 0.0, term = x;
    double true_sin = sin(x);
    double numerator = x;   // x^1 (numerator of first term)
    double denominator = 1; // 1! (denominator of first term)

    // Print table header
    printf("\n%-10s %-15s %-15s %-15s %-15s\n", "Iteration", "Approx Sin(x)", "Absolute Error", "Relative Error", "Percentage Error");
    printf("----------+---------------+---------------+---------------+----------------\n");

    for (int n = 0; n < terms; n++)
    {
        approx_sin += term;

        // Compute absolute, relative, and percentage errors
        double absolute_error = fabs(true_sin - approx_sin);
        double relative_error = (true_sin != 0) ? absolute_error / fabs(true_sin) : 0;
        double percentage_error = relative_error * 100;

        // Print table row
        printf("%-10d %-15.6f %-15.6f %-15.6f %-15.2f\n",
               n + 1, approx_sin, absolute_error, relative_error, percentage_error);

        // Prepare for next iteration
        numerator *= -x * x;                      // Update x^(2n+1) to x^(2n+3)
        denominator *= (2 * n + 2) * (2 * n + 3); // Update factorial (2n+1)! to (2n+3)!
        term = numerator / denominator;           // Compute next term
    }
}

int main()
{
    double x;
    printf("Enter the value of x (in radians): ");
    scanf("%lf", &x);

    taylor_sin(x, 10); // Compute sin(x) up to the 10th term

    return 0;
}
