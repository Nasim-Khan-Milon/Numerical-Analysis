#include<bits/stdc++.h>
using namespace std;

// Example: solve x^2 - 4 = 0 -> g(x) = sqrt(4)
double g(double x) {
    return sqrt(4); // simple example
}

int main()
{
    double x0;      // Initial guess
    double tol;     // Tolerance
    int maxIter;    // Maximum iterations

    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter tolerance: ";
    cin >> tol;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    double x = x0;
    double x1;
    int iter = 0;

    cout << fixed << setprecision(6);
    cout << "\nIter\t x_n\t x_{n+1}\t Error\n";

    while(iter<maxIter)
    {
        x1 = g(x);
        double error = fabs(x1 - x);

        cout << iter+1 << "\t" << x << "\t" << x1 << "\t" << error << endl;

        if (error < tol) {   // stop based on tolerance
            cout << "\nConverged to root: " << x1 << " after " << iter+1 << " iterations.\n";
            return 0;
        }

        x = x1;
        iter++;
    }

    cout << "\nDid not converge after " << maxIter << " iterations. Approximate root: " << x1 << endl;

    return 0;
}