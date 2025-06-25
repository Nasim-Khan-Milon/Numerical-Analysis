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

    double error = fabs(a-b);

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
        error = fabs(a-b);
    }

    return {(a+b)/2.0, iteration};
}


pair<double, int> improved_bisection(double a, double b, double tol)
{
    int iteration = 0;
    double fa = f(a);
    double fb = f(b);

    if(fa * fb >0)
    {
        return {-1, 0};
    }

    double error = fabs(a-b);

    while(error > tol)
    {
        double c = (a+b) / 2.0;
        double fc = f(c);

        if(fc == 0)
        {
            break;
        }
        else if(fa * fc <= 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        iteration++;
        error = fabs(a-b);
    }

    return {(a+b)/2.0, iteration};
}


int main()
{
    double a = 1, b = 2, tol = 1e-6;

    pair<double, int> result1 = traditional_bisection(a, b, tol);
    double root1 = result1.first;
    int iter1 = result1.second;

    pair<double, int> result2 = improved_bisection(a, b, tol);
    double root2 = result2.first;
    int iter2 = result2.second;

    cout << fixed << setprecision(6);
    cout << "Traditional Bisection:\n";
    cout << "  Root = " << root1 << ", Iterations = " << iter1 << "\n\n";

     cout << "Improved Bisection:\n";
    cout << "  Root = " << root2 << ", Iterations = " << iter2 << "\n";
}