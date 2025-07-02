/*
1.Implement Newton Raphson Method for
 f(x) = x^5 -3x +5.
error, £s=10^-3

*/

#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return pow(x, 5) - 3 * x + 5; // Example: f(x) = x⁵ - 3x + 5
}

double df(double x)
{
    return 5 * pow(x, 4) - 3; // Derivative: f'(x) = 5x^4 - 3
}

double newtonRaphson(double x0, double tol)
{
    double x1 = x0 - (f(x0) / df(x0));

    while (fabs(x1 - x0) > tol)
    {
        x0 = x1;
        x1 = x0 - (f(x0) / df(x0));

    }
    return x0;
}

int main()
{
    double a = -2, b = -3;
    double tol = 1e-3;

    double x0 = (abs(f(a)) < abs(f(b))) ? a : b;

    double ans = newtonRaphson(x0, tol);

    cout << fixed << setprecision(6);
    cout <<"Approximate root: "<<ans;
}