#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += 1LL * c[i] * x;
        if (x > 1)
            x--;
    }
    cout << result;

    return 0;
}