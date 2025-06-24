//f(x) = x^3 - x - 2

#include<bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x*x*x - x - 2 ;
}

pair<double, int > traditional_bisection(double a, double b, double tol)
{
    int iteration = 0;

    if(f(a) * f(b) >0)
    {
        return {-1, 0};
    }

    double error = abs(a-b);

    while(error > tol)
    {
        double c = (a+b) / 2.0;

        if(f(c) == 0)
        {
            break;
        }
        else if(f(a) * f(c) <= 0)
        {
            b=c;
        }
        else
        {
            a=c;
        }
        iteration++;
        error = abs(a-b);
    }

    return {(a+b)/2.0, iteration};
}


int main()
{
    double a = 1, b = 2, tol = 1e-6;

    pair<double, int> result1 = traditional_bisection(a, b, tol);
    double root1 = result1.first;
    int iter1 = result1.second;

    cout << fixed << setprecision(6);
    cout << "Traditional Bisection:\n";
    cout << "  Root = " << root1 << ", Iterations = " << iter1 << "\n\n";
}