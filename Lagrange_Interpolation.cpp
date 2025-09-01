#include <bits/stdc++.h>
using namespace std;

double lagrangeInterpolation(double x[], double y[], int n, double xp)
{
    double yp = 0;

    for (int i = 0; i < n; i++)
    {
        double term = y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                term *= ((xp - x[j]) / (x[i] - x[j]));
            }
        }
        yp += term;
    }

    return yp;
}

int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[n], y[n];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    double xp;
    cout << "Enter the value of x to interpolate: ";
    cin >> xp;

    double yp = lagrangeInterpolation(x, y, n, xp);

    cout << "Interpolated value at x = " << xp << " is " << yp << endl;

    return 0;
}