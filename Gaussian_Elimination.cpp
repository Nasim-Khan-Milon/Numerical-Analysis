#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1)); // augmented matrix [A|B]
    vector<double> x(n);                                // solution

    cout << "Enter the augmented matrix (A|B):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for (int i = 0; i < n - 1; i++)
    {
        // Pivoting (optional: improves accuracy)
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(a[i][i]) < fabs(a[k][i]))
            {
                swap(a[i], a[k]);
            }
        }

        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++)
            {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    // Print Solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
