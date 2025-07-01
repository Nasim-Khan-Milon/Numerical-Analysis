/*
1.solve this with regular False position method : 
f(x)=ln(3x)-3, error=10 inverse 4.(code->github).
*/

#include<bits/stdc++.h>
using namespace std;

double f (double x){
    return log(3*x) - 3;
}

pair<double, int> falsePosition(double a, double b, double tol)
{
    double fa = f(a);
    double fb = f(b);
    double c=a,fc=tol+1;
    int iteration = 0;

    if(fa*fb > 0)
    {
        return {-1 , 0};
    }

    while (fabs(fc)>tol)
    {
        c = ((a * fb) - (b * fa)) / (fb - fa);
        fc = f(c);

        if(fc == 0)
        {
            break;
        }
        else if(fc < 0)
        {
            a = c;
            fa = fc;
        }
        else 
        {
            b = c;
            fb = fc;
        }
        iteration++;
    }

    return {c , iteration};
    
}

int main()
{
    double a = 5, b = 8;       
    double tol = 1e-4;        

    pair<double, int> ans = falsePosition(a, b, tol);

    cout << fixed << setprecision(6);
    cout<<"Answer is "<<ans.first<<" after "<<ans.second<<" iteratin.";
}