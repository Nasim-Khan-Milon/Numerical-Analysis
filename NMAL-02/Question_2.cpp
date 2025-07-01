/*
2.compair between bisection & false position method
with True percentage Relative error : f(x) = 4x^2 + 3x - 3.
*/

#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return 4 * x * x + 3 * x - 3;
}

double falsePosition(double a, double b, double tol, int &iterations)
{
    double fa = f(a);
    double fb = f(b);
    double c = a, fc = tol + 1;
    iterations = 0;

    if (fa * fb > 0)
    {
        return -1;
    }

    while (fabs(fc) > tol)
    {
        c = ((a * fb) - (b * fa)) / (fb - fa);
        fc = f(c);

        if (fc == 0)
            break;
        else if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        iterations++;
    }

    return c;
}

double bisection(double a, double b, double tol, int &iterations)
{
    double fa = f(a);
    double fb = f(b);
    iterations = 0;

    if (fa * fb > 0)
    {
        return -1;
    }

    double c;
    while (fabs(b - a) > tol)
    {
        c = (a + b) / 2.0;
        double fc = f(c);

        if (fc == 0)
            break;
        else if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        iterations++;
    }

    return (a + b) / 2.0;
}

int main()
{
    double a = -2, b = -1;
    double tol = 1e-4;

    // True root (from quadratic formula)
    double x_true = (-3 - sqrt(57)) / 8.0;

    int it_fp = 0, it_bis = 0;
    double root_fp = falsePosition(a, b, tol, it_fp);
    double root_bis = bisection(a, b, tol, it_bis);

    double error_fp = fabs((x_true - root_fp) / x_true) * 100;
    double error_bis = fabs((x_true - root_bis) / x_true) * 100;

    cout << fixed << setprecision(6);
    cout << "True Root ≈ " << x_true << "\n\n";

    cout << "False Position Method:\n";
    cout << "  Root = " << root_fp << ", Iterations = " << it_fp << ", True % Relative Error = " << error_fp << "%\n\n";

    cout << "Bisection Method:\n";
    cout << "  Root = " << root_bis << ", Iterations = " << it_bis << ", True % Relative Error = " << error_bis << "%\n";

    return 0;
}