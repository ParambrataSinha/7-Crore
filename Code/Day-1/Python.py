import math

def taylor_sin(x, terms=10):
    approx_sin = 0.0
    term = x  # First term (x^1 / 1!)
    numerator = x  # x^1
    denominator = 1  # 1!
    
    true_sin = math.sin(x)  # True value of sin(x)

    # Print table header
    print(f"\n{'Iteration':<10}{'Approx Sin(x)':<20}{'Absolute Error':<20}{'Relative Error':<20}{'Percentage Error':<20}")
    print("-" * 90)

    for n in range(terms):
        approx_sin += term  # Add current term to approximation

        # Calculate errors
        absolute_error = abs(true_sin - approx_sin)
        relative_error = absolute_error / abs(true_sin) if true_sin != 0 else 0
        percentage_error = relative_error * 100

        # Print table row
        print(f"{n+1:<10}{approx_sin:<20.6f}{absolute_error:<20.6f}{relative_error:<20.6f}{percentage_error:<20.2f}")

        # Update term for next iteration
        numerator *= -x * x  # x^(2n+1) to x^(2n+3)
        denominator *= (2 * n + 2) * (2 * n + 3)  # (2n+1)! to (2n+3)!
        term = numerator / denominator  # Compute next term

# Input from user
x = float(input("Enter the value of x (in radians): "))
taylor_sin(x, 10)  # Compute sin(x) up to the 10th term
