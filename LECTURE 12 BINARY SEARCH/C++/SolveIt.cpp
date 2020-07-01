#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
const double eps = 1e-8;

double f(double p, double q, double r, double s, double t, double u, double x)
{
    return (p * exp(-x) + q * sin(x) + r * cos(x)+ s * tan(x) + t * x * x + u);
}
double p, q, r, s, t, u;

int main()
{
    
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        double lo = 0.000;
        double hi = 1.000;
        
        if (f(p, q, r, s, t, u, 1.0) > 1e-9 || p + r + u < 0)
        {
            cout << "No solution" << endl;
            continue;
        }

        double res = -1;
        for (int i = 0; i <= 1000; i++)
        {
            double x = (lo + hi)/2.0;
            double F = f(p, q, r, s, t, u, x);

            if (F > 0) lo = x;
            else hi = x;
        }

        cout << fixed << setprecision(4) << lo << endl;
    }
    return 0;
}