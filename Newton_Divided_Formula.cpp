#include <bits/stdc++.h>
using namespace std;

void dividedDifferenceTable(vector<double> &x, vector<vector<double>> &y, int n)
{
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

double applyFormula(int value, vector<double> &x, vector<vector<double>> &y, int n)
{
    double ans = y[0][0];
    double product = 1;

    for (int i = 1; i < n; i++)
    {
        product *= (value - x[i-1]);
        ans += (product * y[0][i]);
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n);
    vector<vector<double>> y(n, vector<double>(n));

    cout << "Enter data points (x, y):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i][0];
    }

    // Calculate divided difference table
    dividedDifferenceTable(x, y, n);

    // Print divided difference table
    cout << "\nDivided Difference Table:\n";
    for (int i = 0; i < n; i++)
    {
        cout << setw(10) << x[i];
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(10) << y[i][j];
        }
        cout << endl;
    }

    double value;
    cout << "\nEnter the value of x to interpolate: ";
    cin >> value;

    double result = applyFormula(value, x, y, n);
    cout << "Interpolated value at x = " << value << " is " << result << endl;

    return 0;
}