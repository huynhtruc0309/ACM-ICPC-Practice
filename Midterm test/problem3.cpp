#include <iostream>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int main()
{
    long long k, n, w;
    cin >> k >> n >> w;
    long long buy = 0;
    for (int i = 1; i <= w; i++)
    {
        buy += i*k;
    }
    if (buy > n)
        cout << buy - n;
    else
        cout << 0;
    return 0;
}