#include <iostream>
#include <vector>
using namespace std;
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    
    double sumEnergy, sumTransfer, _left, _right, mid, mi = 1000, ma = 0;
    
    sumEnergy = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> A[i];
        sumEnergy += A[i];
        if (A[i] < mi)
            mi = A[i];
        if (A[i] > ma)
            ma = A[i];
    }
    
    _left = mi;
    _right = ma;

    while (_right - _left > 1e-7) 
    {
        mid =(_left + _right) / 2;
        sumTransfer = 0;
        for (int i = 0; i < n; i++) 
        {
            if (A[i] > mid)
                sumTransfer += A[i] - mid;
        }
        if (mid * n < sumEnergy - sumTransfer * k / 100) 
        {
        	_left = mid;
        }
        else 
        {
        	_right = mid;
        }
    }
    printf("%.9f", _left);

    return 0;
}