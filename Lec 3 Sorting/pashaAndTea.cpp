#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> a(2*n);

    for (int i = 0; i < 2*n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    double x = min(a[0] * 1.0, a[n]/2.0);
    double total = 3.0 * n * x;
    if (total <= w)
        cout << setprecision(9) << total;
    else
        cout << w;
    return 0;
}